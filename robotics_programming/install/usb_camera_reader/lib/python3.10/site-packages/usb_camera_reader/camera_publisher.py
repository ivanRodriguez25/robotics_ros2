import rclpy
from rclpy.node import Node
import time
import subprocess
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np


class CameraPublisher(Node):
    def __init__(self):
        super().__init__('usb_camera_publisher')

        self.declare_parameter('camera_id', 0)
        camera_id = self.get_parameter('camera_id').value

        self.topic_name = "/usb_camera/image_raw"
        self.camera_id = f"/dev/video{camera_id}"

        # Setup camera
        self.setup_camera()
        CAMERA_PATH = '/dev/video0'

        # Create publisher
        pub_interface = Image
        pub_name = self.topic_name
        queue_size = 10
        self.publisher_ = self.create_publisher(pub_interface, pub_name, queue_size)
        self.t0, self.t1 = 0, 0
        self.times = [0]

        # Create timer
        self.get_frame_timer = self.create_timer(0.0001, self.get_image_frame)
        self.image_elaboration_timer = self.create_timer(0.0001, self.image_elaboration)

        self.bridge = CvBridge()
        self.frame = []
        self.img_ready = False

        # Instantiate camera
        self.capture = cv2.VideoCapture(CAMERA_PATH, cv2.CAP_V4L2)

        # Define camera properties
        self.capture.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))
        self.capture.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.capture.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.capture.set(cv2.CAP_PROP_FPS, 120)

        if not self.capture.isOpened():
            self.get_logger().error(f"Could not open video device with ID {camera_id}")
            raise SystemExit
    

    def run_command(self, cmd):
        result = subprocess.run(
            cmd,
            shell=True,
            capture_output=True,
            text=True,
            encoding='cp1252',
            errors='replace'
        )
        return result.stdout, result.stderr
    

    def setup_camera(self):
        try:
            # Listar dispositivos USB
            stdout, _ = self.run_command('cmd.exe /C "usbipd list"')
            self.get_logger().info(f"Dispositivos actuales:\n{stdout}")

            # Bind y attach
            self.run_command('cmd.exe /C "usbipd bind --busid=1-2"')
            self.run_command('cmd.exe /C "usbipd attach --wsl --busid=1-2"')

            # Esperar hasta que esté “Attached”
            self.get_logger().info("Esperando a que la cámara esté adjunta...")
            attached = False
            max_wait = 30  # segundos
            start = time.time()

            while time.time() - start < max_wait:
                stdout, _ = self.run_command('cmd.exe /C "usbipd list"')
                if "1-2" in stdout and "Attached" in stdout:
                    attached = True
                    break
                time.sleep(1)

            if attached:
                self.get_logger().info("Cámara detectada y adjunta.")
            else:
                self.get_logger().error("Timeout esperando que la cámara se adjunte.")

        except Exception as e:
            self.get_logger().error(f"Error al ejecutar usbipd: {e}")


    def get_image_frame(self):
        ret, self.frame = self.capture.read()
        
        if ret:
            height, width = self.frame.shape[:2]
            new_size = (width // 3, height // 3)
            resized_frame = cv2.resize(self.frame, new_size)
            gray_frame = cv2.cvtColor(resized_frame, cv2.COLOR_BGR2GRAY)

            if gray_frame is not None:
                cv2.imshow('frame', gray_frame)
                self.img_ready = True
                if cv2.waitKey(20) & 0xFF == ord('q'):
                    return



    def image_elaboration(self):
        
        self.t0 = self.t1
        self.t1 = time.time()

        if self.img_ready == True:
            
            self.times.append(1/(self.t1 - self.t0))
            self.times = self.times[-10:]
            fps_ = round(np.mean(self.times), 2)
            self.get_logger().info(f"fps: {fps_}")

            frame = self.frame
            height, width, _ = frame.shape
            font = cv2.FONT_HERSHEY_SIMPLEX
            font_scale = 0.6
            font_color = (255, 255, 255)
            font_thickness = 1
            
            position_device = (10, 30)
            position_topic  = (10, 60)
            position_res    = (10, 90)
            position_fps    = (10, 120)

            cv2.putText(frame, f"Device {self.camera_id}", position_device, font, font_scale, font_color, font_thickness)
            cv2.putText(frame, f"Topic {self.topic_name}", position_topic, font, font_scale, font_color, font_thickness)
            cv2.putText(frame, f"Resolution: {width}x{height}", position_res, font, font_scale, font_color, font_thickness)
            cv2.putText(frame, f"FPS: {fps_}", position_fps, font, font_scale, font_color, font_thickness)

            image_msg = self.bridge.cv2_to_imgmsg(frame, encoding="bgr8")
            self.publisher_.publish(image_msg)
            self.t0 = time.time()


def main(args=None):
    rclpy.init(args=args)
    node = CameraPublisher()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()