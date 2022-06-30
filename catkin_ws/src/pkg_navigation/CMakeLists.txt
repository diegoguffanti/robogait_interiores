cmake_minimum_required(VERSION 3.5)
project(pkg_navigation)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#------------------------------------------------------------------
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(turtlesim REQUIRED)
find_package(body_tracker_msgs REQUIRED)



add_executable(publisher_subscriber src/publisher_subscriber.cpp)
add_executable(tf2_broadcaster src/tf2_broadcaster.cpp)
add_executable(publisher_initial_pose src/publisher_initial_pose.cpp)
add_executable(robot_odom_tf2_listener src/robot_odom_tf2_listener.cpp)
add_executable(robot_controller src/robot_controller.cpp)
add_executable(robot_controller_position src/robot_controller_position.cpp)
add_executable(tf2_broadcaster_person src/tf2_broadcaster_person.cpp)
add_executable(person_odom_tf2_listener src/person_odom_tf2_listener.cpp)
add_executable(robot_controller_straight src/robot_controller_straight.cpp)
add_executable(tf2_broadcaster_camera src/tf2_broadcaster_camera.cpp)
add_executable(camera_controller src/camera_controller.cpp)




ament_target_dependencies(
publisher_subscriber
 
rclcpp
std_msgs
geometry_msgs
nav_msgs
sensor_msgs
tf2
tf2_ros
)

ament_target_dependencies(
tf2_broadcaster
 
rclcpp
std_msgs
geometry_msgs
nav_msgs
sensor_msgs
tf2
tf2_ros
turtlesim
)

ament_target_dependencies(
tf2_broadcaster_person
 
rclcpp
std_msgs
geometry_msgs
nav_msgs
sensor_msgs
tf2
tf2_ros
turtlesim
body_tracker_msgs
)

ament_target_dependencies(
tf2_broadcaster_camera
 
rclcpp
std_msgs
geometry_msgs
nav_msgs
sensor_msgs
tf2
tf2_ros
turtlesim

)



ament_target_dependencies(
robot_controller
 
rclcpp
std_msgs
geometry_msgs
nav_msgs
sensor_msgs
tf2
tf2_ros


)

ament_target_dependencies(
robot_controller_position
 
rclcpp
std_msgs
geometry_msgs
nav_msgs
sensor_msgs
tf2
tf2_ros
body_tracker_msgs

)

ament_target_dependencies(
camera_controller
 
rclcpp
std_msgs
geometry_msgs
nav_msgs
sensor_msgs
tf2
tf2_ros
body_tracker_msgs

)


ament_target_dependencies(
robot_controller_straight
 
rclcpp
std_msgs
geometry_msgs
nav_msgs
sensor_msgs
tf2
tf2_ros
body_tracker_msgs

)





ament_target_dependencies(
robot_odom_tf2_listener
 
rclcpp
tf2
tf2_ros
geometry_msgs
nav_msgs
)


ament_target_dependencies(
person_odom_tf2_listener
 
rclcpp
tf2
tf2_ros
geometry_msgs
nav_msgs
)



ament_target_dependencies(
publisher_initial_pose
 
rclcpp
geometry_msgs
)

install(TARGETS publisher_subscriber tf2_broadcaster publisher_initial_pose robot_odom_tf2_listener robot_controller robot_controller_position tf2_broadcaster_person tf2_broadcaster_camera person_odom_tf2_listener robot_controller_straight camera_controller DESTINATION lib/${PROJECT_NAME})


install(DIRECTORY launch rviz config maps DESTINATION share/${PROJECT_NAME})




#------------------------------------------------------------------------  
  


ament_package()
