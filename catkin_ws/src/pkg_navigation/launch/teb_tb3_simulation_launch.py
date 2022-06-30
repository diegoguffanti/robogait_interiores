# Copyright (c) 2018 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# This is all-in-one launch script intended for use by nav2 developers.

import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, GroupAction,IncludeLaunchDescription, SetEnvironmentVariable)
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch_ros.actions import PushRosNamespace


def generate_launch_description():
    # Get the launch directory
    
    pkg_navigation_dir = os.path.join(get_package_share_directory('pkg_navigation'))
    bringup_launch_dir = os.path.join(get_package_share_directory('nav2_bringup'), 'launch')
    realsense_launch_dir = os.path.join(get_package_share_directory('realsense2_camera'), 'launch')
    
    
    #rviz_config_file = os.path.join(pkg_navigation_dir,'rviz', 'rviz_config_nav2_teb.rviz')
    #nav2_bringup_launch_dir=os.path.join(pkg_navigation_dir,'launch','tb3_simulation_launch.py')

    # Create the launch configuration variables
    namespace = LaunchConfiguration('namespace')
    use_namespace = LaunchConfiguration('use_namespace')
    slam = LaunchConfiguration('slam')
    map_yaml_file = LaunchConfiguration('map')
    use_sim_time = LaunchConfiguration('use_sim_time')
    params_file = LaunchConfiguration('params_file')
    default_bt_xml_filename = LaunchConfiguration('default_bt_xml_filename')
    autostart = LaunchConfiguration('autostart')
    use_rviz = LaunchConfiguration('use_rviz')
    rviz_config_file = LaunchConfiguration('rviz_config_file')
    
    stdout_linebuf_envvar = SetEnvironmentVariable(
        'RCUTILS_LOGGING_BUFFERED_STREAM', '1')
    
    declare_namespace_cmd = DeclareLaunchArgument(
        'namespace',
        default_value='',
        description='Top-level namespace')

    declare_use_namespace_cmd = DeclareLaunchArgument(
        'use_namespace',
        default_value='false',
        description='Whether to apply a namespace to the navigation stack')

    declare_slam_cmd = DeclareLaunchArgument(
        'slam',
        default_value='False',
        description='Whether run a SLAM')
    
    declare_rviz_config_file_cmd = DeclareLaunchArgument(
        'rviz_config_file',
        default_value=os.path.join(get_package_share_directory('nav2_bringup'),'rviz', 'nav2_default_view.rviz'),    
        description='Full path to the RVIZ config file to use')
    
    #default_value=os.path.join(get_package_share_directory('nav2_bringup'),'rviz', 'nav2_default_view.rviz'),    
    #default_value=os.path.join(pkg_navigation_dir,'rviz', 'rviz_config_nav2_teb.rviz'),
    
    declare_use_rviz_cmd = DeclareLaunchArgument(
        'use_rviz',
        default_value='True',
        description='Whether to start RVIZ')

    declare_map_yaml_cmd = DeclareLaunchArgument(
        'map',
        default_value=os.path.join(pkg_navigation_dir,'maps','map_laboratory.yaml'),
        description='Full path to map yaml file to load')
    #Map list
    #map_laboratory.yaml
    #map_pasillos_posteriores_edited.yaml
    
    declare_use_sim_time_cmd = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation clock if true')

    declare_params_file_cmd = DeclareLaunchArgument(
        'params_file',
        default_value=os.path.join(pkg_navigation_dir,'config','teb_params.yaml'),
        description='Full path to the ROS2 parameters file to use for all launched nodes')

    declare_bt_xml_cmd = DeclareLaunchArgument(
        'default_bt_xml_filename',
        default_value=os.path.join(
            get_package_share_directory('nav2_bt_navigator'),
            'behavior_trees', 'navigate_w_replanning_and_recovery.xml'),
        description='Full path to the behavior tree xml file to use')

    declare_autostart_cmd = DeclareLaunchArgument(
        'autostart', default_value='true',
        description='Automatically startup the nav2 stack')
        
        

    # Specify the actions
    bringup_cmd_group = GroupAction([
        PushRosNamespace(
            condition=IfCondition(use_namespace),
            namespace=namespace),
            
        

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(bringup_launch_dir, 'slam_launch.py')),
            condition=IfCondition(slam),
            launch_arguments={'namespace': namespace,
                              'use_sim_time': use_sim_time,
                              'autostart': autostart,
                              'params_file': params_file}.items()),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(bringup_launch_dir,
                                                       'localization_launch.py')),
            condition=IfCondition(PythonExpression(['not ', slam])),
            launch_arguments={'namespace': namespace,
                              'map': map_yaml_file,
                              'use_sim_time': use_sim_time,
                              'autostart': autostart,
                              'params_file': params_file,
                              'use_lifecycle_mgr': 'false'}.items()),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(bringup_launch_dir, 'navigation_launch.py')),
            launch_arguments={'namespace': namespace,
                              'use_sim_time': use_sim_time,
                              'autostart': autostart,
                              'params_file': params_file,
                              'default_bt_xml_filename': default_bt_xml_filename,
                              'use_lifecycle_mgr': 'false',
                              'map_subscribe_transient_local': 'true'}.items()),
                              
                                                       
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(pkg_navigation_dir,'launch','robogait_state_publisher.py'))),
            
        #IncludeLaunchDescription(
        #    PythonLaunchDescriptionSource(os.path.join(pkg_navigation_dir,'launch','person_state_publisher.py'))),
                                                       

            
        #IncludeLaunchDescription(
            #PythonLaunchDescriptionSource(os.path.join(realsense_launch_dir,'realsense_pointcloud_launch.py')))
                                                       
                                                       
                                                       
                                                        

                              
    ])
    
    rviz_cmd = IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(pkg_navigation_dir,'launch','rviz_launch.py')),
            condition=IfCondition(use_rviz),
            launch_arguments={'namespace': '',
                              'use_namespace': 'False',
                              'rviz_config': rviz_config_file}.items())
    

    ld = LaunchDescription()
    # Set environment variables
    ld.add_action(stdout_linebuf_envvar)

    # Declare the launch options
    ld.add_action(declare_namespace_cmd)
    ld.add_action(declare_use_namespace_cmd)
    ld.add_action(declare_slam_cmd)
    ld.add_action(declare_map_yaml_cmd)
    ld.add_action(declare_use_sim_time_cmd)
    ld.add_action(declare_params_file_cmd)
    ld.add_action(declare_autostart_cmd)
    ld.add_action(declare_bt_xml_cmd)
    
    ld.add_action(declare_rviz_config_file_cmd)
    ld.add_action(declare_use_rviz_cmd)
    ld.add_action(rviz_cmd)
    ld.add_action(bringup_cmd_group)
    
    
    

    return ld
    