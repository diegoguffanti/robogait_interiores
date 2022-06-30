# Install script for directory: /home/robogait/azure_kinect_ws/src/kinect_azure_body_tracker

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/robogait/azure_kinect_ws/install/kinect_azure_body_tracker")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_simplified")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_recording_node_simplified")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_full_processing")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_finite")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker" TYPE EXECUTABLE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test"
         OLD_RPATH "/opt/ros/foxy/lib:/home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinect_azure_body_tracker/kinect_azure_body_tracker_node_plus_recording_test")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/kinect_azure_body_tracker")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/kinect_azure_body_tracker")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker/environment" TYPE FILE FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker/environment" TYPE FILE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker/environment" TYPE FILE FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker/environment" TYPE FILE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker" TYPE FILE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker" TYPE FILE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker" TYPE FILE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker" TYPE FILE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker" TYPE FILE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_index/share/ament_index/resource_index/packages/kinect_azure_body_tracker")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker/cmake" TYPE FILE FILES
    "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_core/kinect_azure_body_trackerConfig.cmake"
    "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/ament_cmake_core/kinect_azure_body_trackerConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_azure_body_tracker" TYPE FILE FILES "/home/robogait/azure_kinect_ws/src/kinect_azure_body_tracker/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
