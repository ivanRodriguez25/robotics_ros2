import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
import numpy as np


class TurtleControl(Node):
    def __init__(self):
        super().__init__("turtle_controller")

        topic_interface_subscriber = Pose
        topic_vel = "/turtle1/cmd_vel"
        topic_color = "/turtle1/color_sensor"
        topic_pose = "/turtle1/pose"
        callback_function = self.callback_control
        queue_size = 10

        # Create subscription
        self.control_subscriber_pose = self.create_subscription(topic_interface_subscriber, topic_pose, callback_function, queue_size)
        self.counter_ = 0

        self.get_logger().info("Created control_subscriber node")

        # Create publisher
        topic_interface_publisher = Twist
        self.control_publisher = self.create_publisher(topic_interface_publisher, topic_vel, queue_size)
        
        # Create timer
        dt = 0.5
        self.control_timer = self.create_timer(dt, self.publish_control)
        self.get_logger().info("Created control_publisher node")


    def callback_control(self, msg: Pose):
        x = msg.x
        y = msg.y
        th = msg.theta
        lv = msg.linear_velocity

        self.get_logger().info(f"Iteration {self.counter_} - {th} - {lv}")
        self.counter_ += 1


    def publish_control(self):
        vel_cmd = Twist()

        vel_cmd.linear.x = 0.25
        #vel_cmd.linear.y = 0.25
        vel_cmd.angular.z = 0.15
        
        self.control_publisher.publish(vel_cmd)
        self.get_logger().info(f"Publishing {vel_cmd}")

        


def main(args=None):
    rclpy.init(args=args)
    node = TurtleControl()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()