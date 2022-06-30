import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration
from nav2_common.launch import RewrittenYaml



def generate_launch_description():
   
    #rlidar_node = IncludeLaunchDescription(PythonLaunchDescriptionSource([os.path.join(get_package_share_directory('sllidar_ros2'), 'launch'),'/view_sllidar_s2_launch.py']))
   
   return LaunchDescription([
   
        #Node(package='tf2_ros', executable='static_transform_publisher',name='tf2_static_tf_realsense',arguments = ['0.14', '0', '0.10', '0', '0', '0', 'base_footprint', 'camera_link']),
        
        
        #Node(package='pkg_navigation', executable='tf2_broadcaster', name='tf2_broadcaster'),
        #Node(package='tf2_ros', executable='static_transform_publisher',name='tf2_static_tf_camera',arguments = ['0', '0', '0.35', '3.14159', '0', '0', 'base_footprint', 'camera_link']),
        #Node(package='ros2_serial_cpp', executable='driver_controller', name='driver_controller'),
        #Node(package='pkg_navigation', executable='robot_controller', name='robot_controller'),
        #Node(package='pkg_navigation', executable='robot_controller_position', name='robot_controller_position'),
        Node(package='kinect_azure_body_tracker', executable='kinect_azure_body_tracker_node_simplified', name='kinect_azure_body_tracker_node_simplified'),
        Node(package='pkg_navigation', executable='tf2_broadcaster_person', name='tf2_broadcaster_person'),
        Node(package='pkg_navigation', executable='tf2_broadcaster_camera', name='tf2_broadcaster_camera'),
        Node(package='pkg_navigation', executable='camera_controller', name='camera_controller'),
        Node(package='pkg_navigation', executable='person_odom_tf2_listener', name='person_odom_tf2_listener')
        
        
        
        
        #Node(package='teleop_twist_keyboard',node_executable="teleop_twist_keyboard",output='screen',prefix = 'xterm -e',node_name='teleop'),
               
   ])
