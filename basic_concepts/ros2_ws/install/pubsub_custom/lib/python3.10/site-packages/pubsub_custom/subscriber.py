import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64


class NumberSubscriberNode(Node):
    def __init__(self):
        super().__init__("number_subscriber")

        topic_interface = Int64
        topic_name = "number"
        callback_function = self.callback_number
        queue_size = 10

        self.number_subscriber = self.create_subscription(topic_interface, topic_name, callback_function, queue_size)

        self.counter_ = 0

        self.get_logger().info("Created number_subscriber node")


    def callback_number(self, msg: Int64):
        self.counter_ += msg.data
        self.get_logger().info(f"Counter: {self.counter_}")


def main(args=None):
    rclpy.init(args=args)
    node = NumberSubscriberNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()