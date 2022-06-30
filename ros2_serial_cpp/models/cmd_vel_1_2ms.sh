#!/bin/bash
ros2 topic pub --once /cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0}}"&
sleep 5 
ros2 topic pub --once /cmd_vel geometry_msgs/msg/Twist "{linear: {x: 1.2}}"&
sleep 3 
ros2 topic pub --once /cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0}}"&
