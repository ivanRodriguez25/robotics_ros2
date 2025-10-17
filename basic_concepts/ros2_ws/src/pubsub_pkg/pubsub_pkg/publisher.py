import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64


class NumberPublisherNode(Node):
    def __init__(self):
        super().__init__("number_publisher")
        topic_interface = Int64
        topic_name = "number"
        queue_size = 10
        self.number_ = 1

        # Create publisher
        self.number_publisher_ = self.create_publisher(topic_interface, topic_name, queue_size)

        # Create timer
        frequency = 1
        self.number_timer_ = self.create_timer(frequency, self.publish_number)

        self.get_logger().info("number_publisher node has started")


    def publish_number(self):
        msg = Int64()
        msg.data = self.number_
        self.number_publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()