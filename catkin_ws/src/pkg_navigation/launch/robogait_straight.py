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
   
   
   return LaunchDescription([
   
        Node(package='ros2_serial_cpp', executable='driver_controller', name='driver_controller'),
        Node(package='kinect_azure_body_tracker', executable='kinect_azure_body_tracker_recording_node_simplified', name='kinect_azure_body_tracker_recording_node_simplified',output='screen'),
        
        #Node(package='teleop_twist_keyboard',node_executable="teleop_twist_keyboard",output='screen',prefix = 'xterm -e',node_name='teleop'),
               
   ])
