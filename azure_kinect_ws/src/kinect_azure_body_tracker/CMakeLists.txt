cmake_minimum_required(VERSION 3.5)
project(kinect_azure_body_tracker)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wno-dev)
endif()

IF(NOT WIN32)
  SET(SPECIAL_OS_LIBS "pthread" "X11")
  add_definitions(-Wno-write-strings)
ENDIF()

## find dependencies ---------------
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# Mensajes creados
#find_package(${PROJECT_NAME} REQUIRED)
find_package(body_tracker_msgs REQUIRED)

# Paquete de generación de interfaces
find_package(rosidl_default_generators REQUIRED)

# Paquetes de k4a
find_package(rosidl_typesupport_cpp REQUIRED)

set( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ${CMAKE_MODULE_PATH} )
include(../../build/${PROJECT_NAME}/CMakeFiles/Export/share/kinect/cmake/Findk4abt.cmake)
include(../../build/${PROJECT_NAME}/CMakeFiles/Export/share/kinect/cmake/Findk4a.cmake)
if(POLICY CMP0074)
  # TODO:
  # 1. Find*.cmake modules need to be individually verified.
  # 2. PCLConfig.cmake needs to be changed.
  cmake_policy(SET CMP0074 OLD)
endif()
find_package( k4a REQUIRED )
find_package( k4abt REQUIRED )

#if( k4a_FOUND AND k4abt_FOUND )
#  target_link_libraries( K4ABT k4a::k4a )
#  target_link_libraries( K4ABT k4a::k4abt )
#endif()

## Ejecutable ---------------
# Sin grabacion | completo
add_executable(${PROJECT_NAME}_node src/kinectAzure_body_tracker_node.cpp)
ament_target_dependencies(${PROJECT_NAME}_node rclcpp body_tracker_msgs K4ABT)
target_link_libraries(${PROJECT_NAME}_node
    k4a
    k4abt
    )

# Con grabacion | completo
add_executable(${PROJECT_NAME}_recording_node src/kinectAzure_body_tracker_node_plus_recording.cpp)
ament_target_dependencies(${PROJECT_NAME}_recording_node rclcpp body_tracker_msgs K4A K4ABT)
target_link_libraries(${PROJECT_NAME}_recording_node
    k4a
    k4arecord
    k4abt
    )

# Sin grabacion | solo pelvis
add_executable(${PROJECT_NAME}_node_simplified src/kinectAzure_body_tracker_node_simplified.cpp)
ament_target_dependencies(${PROJECT_NAME}_node_simplified rclcpp body_tracker_msgs K4A K4ABT)
target_link_libraries(${PROJECT_NAME}_node_simplified
    k4a
    k4abt
    )

# Con grabacion | solo pelvis
add_executable(${PROJECT_NAME}_recording_node_simplified src/kinectAzure_body_tracker_node_plus_recording_simplified.cpp)
ament_target_dependencies(${PROJECT_NAME}_recording_node_simplified rclcpp body_tracker_msgs K4A K4ABT)
target_link_libraries(${PROJECT_NAME}_recording_node_simplified
    k4a
    k4arecord
    k4abt
    )

# Con grabacion y post-procesamiento | Distancia: solo pelvis | Grabación + post-procesamiento: articulaciones completas
add_executable(${PROJECT_NAME}_node_full_processing src/kinectAzure_body_tracker_node_full_processing.cpp)
ament_target_dependencies(${PROJECT_NAME}_node_full_processing rclcpp body_tracker_msgs K4A K4ABT)
target_link_libraries(${PROJECT_NAME}_node_full_processing
    k4a
    k4arecord
    k4abt
    )

# Con grabacion y con cierre correcto del vídeo | Distancia: solo pelvis | Grabación: articulaciones completas
add_executable(${PROJECT_NAME}_node_finite src/kinectAzure_body_tracker_node_finite.cpp)
ament_target_dependencies(${PROJECT_NAME}_node_finite rclcpp body_tracker_msgs K4A K4ABT)
target_link_libraries(${PROJECT_NAME}_node_finite
    k4a
    k4arecord
    k4abt
    )

# PRUEBAS
add_executable(${PROJECT_NAME}_node_plus_recording_test src/kinectAzure_body_tracker_node_plus_recording_test.cpp)
ament_target_dependencies(${PROJECT_NAME}_node_plus_recording_test rclcpp body_tracker_msgs K4A K4ABT)
target_link_libraries(${PROJECT_NAME}_node_plus_recording_test
    k4a
    k4arecord
    k4abt
    )

## Crear el nodo ---------------
install(TARGETS ${PROJECT_NAME}_node ${PROJECT_NAME}_recording_node ${PROJECT_NAME}_node_simplified ${PROJECT_NAME}_recording_node_simplified ${PROJECT_NAME}_node_full_processing ${PROJECT_NAME}_node_finite ${PROJECT_NAME}_node_plus_recording_test
  DESTINATION lib/${PROJECT_NAME})
install(TARGETS
  ${PROJECT_NAME}_node
  ${PROJECT_NAME}_recording_node
  ${PROJECT_NAME}_node_simplified
  ${PROJECT_NAME}_recording_node_simplified
  ${PROJECT_NAME}_node_full_processing
  ${PROJECT_NAME}_node_finite
  ${PROJECT_NAME}_node_plus_recording_test
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
