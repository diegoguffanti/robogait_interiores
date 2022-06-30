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
   
   rviz_config = os.path.join(get_package_share_directory('pkg_navigation'),'rviz','rviz_config_map_server.rviz')
   #rviz_config = os.path.join(get_package_share_directory('nav2_course'), 'config', 'nav2_default_view.rviz')
   map_server_launch = IncludeLaunchDescription(PythonLaunchDescriptionSource([os.path.join(get_package_share_directory('pkg_navigation'), 'launch'),'/map_server_launch.py']))
   
 

        
   
   return LaunchDescription([
   

        map_server_launch,    
        Node(package='rviz2',executable='rviz2',name='rviz2',arguments=['-d', rviz_config])
        #slam_toolbox_mapping,
        
               
   ])
