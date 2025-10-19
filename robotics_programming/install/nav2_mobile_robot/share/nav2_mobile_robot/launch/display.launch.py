from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import Command, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # Ruta del archivo .xacro dentro del paquete
    xacro_file = PathJoinSubstitution([
        FindPackageShare('nav2_mobile_robot'),
        'urdf',
        'nav2_mobile_robot.xacro'
    ])

    # Procesar el xacro para obtener la descripción del robot
    robot_description = Command(['xacro ', xacro_file])

    # Nodo de robot_state_publisher
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_description}]
    )

    # Nodo del joint_state_publisher_gui
    joint_state_publisher_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        output='screen'
    )

    # Nodo de RViz2
    rviz2_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen'
    )

    # LaunchDescription con todos los nodos
    ld = LaunchDescription([
        robot_state_publisher_node,
        joint_state_publisher_gui,
        rviz2_node
    ])

    return ld
