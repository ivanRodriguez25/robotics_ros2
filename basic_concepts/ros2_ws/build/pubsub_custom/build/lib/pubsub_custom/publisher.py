import rclpy
from rclpy.node import Node
from pubsub_interfaces.msg import HardwareStatus


class HardwareStatusPublisher(Node):
    def __init__(self):
        super().__init__("jardware_status")

        topic_interface = HardwareStatus
        topic_name = "hardware_status"
        queue_size = 10
        
        # Create publisher
        self.status_publisher_ = self.create_publisher(topic_interface, topic_name, queue_size)

        # Create timer
        frequency = 1
        self.number_timer_ = self.create_timer(frequency, self.publish_status)

        self.number_ = 0

        self.get_logger().info("number_publisher node has started")


    def publish_status(self):
        # Crear mensaje
        msg = HardwareStatus()
        msg.version = self.number_
        msg.temperature = 36.5
        msg.are_motors_ready = True
        msg.debug_message = f"Status OK - iteration {self.number_}"

        # Publicar
        self.status_publisher_.publish(msg)

        # Log
        self.get_logger().info(
            f"Publishing: version={msg.version}, temp={msg.temperature}, motors_ready={msg.are_motors_ready}, msg='{msg.debug_message}'"
        )

        self.number_ += 1


def main(args=None):
    rclpy.init(args=args)
    node = HardwareStatusPublisher()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()