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
   
   rlidar_node = IncludeLaunchDescription(PythonLaunchDescriptionSource([os.path.join(get_package_share_directory('sllidar_ros2'), 'launch'),'/view_sllidar_s2_launch.py']))
   rviz_config = os.path.join(get_package_share_directory('pkg_navigation'),'rviz','rviz_config.rviz')
   #slam_toolbox_mapping = IncludeLaunchDescription(PythonLaunchDescriptionSource([os.path.join(get_package_share_directory('pkg_navigation'), 'launch'),'/online_async_launch.py']))
   localization_amcl_map_server = IncludeLaunchDescription(PythonLaunchDescriptionSource([os.path.join(get_package_share_directory('pkg_navigation'), 'launch'),'/localization_launch.py']))
   map_file=os.path.join(get_package_share_directory('pkg_navigation'),'maps','test_map.yaml')
   
 

        
   
   return LaunchDescription([
   

            
        #To remap a topic
        #Node(package='teleop_twist_keyboard',node_executable="teleop_twist_keyboard",output='screen',prefix = 'xterm -e',node_name='teleop',remappings=[('/cmd_vel', '/turtle1/cmd_vel')]),
        rlidar_node,
        Node(package='tf2_ros', executable='static_transform_publisher',arguments = ['0', '0', '0.11', '3.14159', '0', '0', 'base_footprint', 'laser']),
        Node(package='pkg_navigation', executable='tf2_broadcaster', name='tf2_broadcaster'),
        Node(package='ros2_serial_cpp', executable='driver_controller', name='driver_controller'),
        Node(package='teleop_twist_keyboard',node_executable="teleop_twist_keyboard",output='screen',prefix = 'xterm -e',node_name='teleop'),
        #Node(package='turtlesim',node_executable="turtlesim_node",output='screen',node_name='turtlesim_pkg_navigation'),
        #localization_amcl_map_server,
        Node(package='rviz2',executable='rviz2',name='rviz2',arguments=['-d', rviz_config])
        #slam_toolbox_mapping,
        
               
   ])
