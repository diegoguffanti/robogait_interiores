cmake_minimum_required(VERSION 3.5)
project(test)

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
find_package(nav_msgs REQUIRED)

add_executable(publisher_subscriber src/publisher_subscriber.cpp)
ament_target_dependencies(publisher_subscriber rclcpp std_msgs nav_msgs)

install(TARGETS publisher_subscriber DESTINATION lib/${PROJECT_NAME})

#------------------------------------------------------------------------  
  

ament_package()
