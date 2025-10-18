import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import os

class ImagePublisherNode(Node):
    def __init__(self):
        super().__init__("image_publisher")

        topic_interface = Image
        topic_name = "image"
        queue_size = 10

        self.image_publisher_ = self.create_publisher(topic_interface, topic_name, queue_size)
        self.bridge = CvBridge()
        
        frequency = 1
        self.image_timer_ = self.create_timer(frequency, self.publish_image)

        # Load image
        IMAGE_PATH = "./src/pubsub_img_pkg/data/samples/robot_sample.png"
        image_ = cv2.imread(IMAGE_PATH)
        self.image_ = cv2.cvtColor(image_, cv2.COLOR_BGR2RGB)

        self.get_logger().info(f"Created ImagePublisher node.")


    def publish_image(self):
        msg = self.bridge.cv2_to_imgmsg(self.image_, encoding="rgb8")
        self.image_publisher_.publish(msg)
        self.get_logger().info("Publishing image. ")


def main(args=None):
    rclpy.init(args=args)
    node = ImagePublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
