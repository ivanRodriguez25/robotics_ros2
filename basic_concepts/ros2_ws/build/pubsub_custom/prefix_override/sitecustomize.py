import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/ivan/personal/robotics_ros2/basic_concepts/ros2_ws/install/pubsub_custom'
