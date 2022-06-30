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
   robot_localization_file_path = os.path.join(get_package_share_directory('pkg_navigation'),'config','ekf.yaml')
   use_sim_time = LaunchConfiguration('use_sim_time')
    
   return LaunchDescription([
   
        DeclareLaunchArgument(
            'use_sim_time', default_value='false',
            description='Use simulation (Gazebo) clock if true'),
   
        rlidar_node,
        Node(package='ros2_serial_cpp', executable='driver_controller', name='driver_controller'),
        Node(package='pkg_navigation', executable='tf2_broadcaster', name='tf2_broadcaster'),
        Node(package='tf2_ros', executable='static_transform_publisher',name='tf2_static_tf_laser',arguments = ['0', '0', '0.24', '3.14159', '0', '0', 'base_footprint', 'laser']),
        #Node(package='tf2_ros', executable='static_transform_publisher',name='tf2_static_tf_realsense',arguments = ['0.14', '0', '0.10', '0', '0', '0', 'base_footprint', 'camera_link']),
        #Node(package='tf2_ros', executable='static_transform_publisher',name='tf2_static_tf_camera',arguments = ['0', '0', '0.35', '3.14159', '0', '0', 'base_footprint', 'camera_link']),
        Node(package='pkg_navigation', executable='robot_odom_tf2_listener', name='robot_odom_tf2_listener'),
        Node(package='robot_localization', executable='ekf_node', name='ekf_filter_node',output='screen',parameters=[robot_localization_file_path,{'use_sim_time': use_sim_time}],remappings=[('/odometry/filtered', '/odom')])
        
        #Node(package='teleop_twist_keyboard',node_executable="teleop_twist_keyboard",output='screen',prefix = 'xterm -e',node_name='teleop'),
               
   ])
