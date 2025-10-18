import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge
from datetime import datetime


class ImageSubscriberNode(Node):
    def __init__(self):
        super().__init__("image_subscriber")

        topic_interface = Image
        topic_name = "image"
        callback_function = self.callback_image
        queue_size = 10
        self.image_subscriber_ = self.create_subscription(topic_interface, topic_name, callback_function, queue_size)
        self.bridge = CvBridge()

        self.counter = 0

        self.get_logger().info("Created image_subscriber node")


    def callback_image(self, msg: Image):
        self.counter += 1
        
        image_ = self.bridge.imgmsg_to_cv2(msg, desired_encoding='rgb8')
        
        # Add hour to image
        text = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        image_ = cv2.putText(image_, 
                             text, 
                             (10, 30), 
                             cv2.FONT_HERSHEY_SCRIPT_SIMPLEX, 
                             0.9, 
                             (255, 0, 0), 
                             2, 
                             cv2.LINE_4)

        # Showing image
        if image_ is not None:
            cv2.imshow("Image Subscriber", image_)
            
            self.get_logger().info(f'Image captured - Received {self.counter} images - {text}')

            if cv2.waitKey(20) & 0xFF == ord('q'):
                return


def main(args=None):
    rclpy.init(args=args)
    node = ImageSubscriberNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
