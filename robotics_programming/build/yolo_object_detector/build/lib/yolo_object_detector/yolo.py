import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
from std_msgs.msg import String


class YoloNode(Node):
    def __init__(self):
        super().__init__('yolo_node')

        # Suscripción al topic de la cámara
        self.subscription = self.create_subscription(
            Image, '/camera/image_raw', self.image_callback, 10
        )

        # Publicador de detecciones
        self.detections_publisher = self.create_publisher(String, 'yolo/detections', 10)

        self.bridge = CvBridge()

        # Cargar modelo YOLOv8
        self.model = YOLO('yolov8n.pt')
        self.get_logger().info("Successfully created YOLO node.")

    def image_callback(self, msg):
        try:
            # Convertir ROS Image a OpenCV
            frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        except Exception as e:
            self.get_logger().error(f"Error converting image: {e}")
            return

        # Realizar detección
        results = self.model(frame)[0]  # Solo un frame a la vez

        # Visualizar resultados
        self.display_results(frame, results)

        # Publicar detecciones como texto
        detection_msg = String()
        detection_msg.data = self.format_detections(results)
        self.detections_publisher.publish(detection_msg)

    def display_results(self, frame, results):
        boxes = results.boxes
        for box in boxes:
            # Convertir tensores a valores nativos
            x1, y1, x2, y2 = map(int, box.xyxy[0].tolist())
            class_id = int(box.cls.item())
            confidence = float(box.conf.item())
            label = self.model.names[class_id]

            # Dibujar cajas y etiquetas
            cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.putText(
                frame, f"{label} {confidence:.2f}", (x1, y1 - 10),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2
            )

        # Mostrar la imagen en una ventana
        cv2.imshow('YOLOv8 Detections', frame)
        cv2.waitKey(1)

    def format_detections(self, results):
        detections = []
        boxes = results.boxes
        for box in boxes:
            class_id = int(box.cls.item())
            label = self.model.names[class_id]
            detections.append(label)

        return ', '.join(detections) if detections else 'No objects detected'


def main(args=None):
    rclpy.init(args=args)
    node = YoloNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
