# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robogait/azure_kinect_ws/src/body_tracking

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robogait/azure_kinect_ws/build/body_tracking

# Utility rule file for body_tracking.

# Include the progress variables for this target.
include CMakeFiles/body_tracking.dir/progress.make

CMakeFiles/body_tracking: /home/robogait/azure_kinect_ws/src/body_tracking/msg/HipCoordinates.msg
CMakeFiles/body_tracking: /home/robogait/azure_kinect_ws/src/body_tracking/msg/Skeleton.msg
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Accel.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/AccelStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/AccelWithCovariance.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/AccelWithCovarianceStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Inertia.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/InertiaStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Point.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Point32.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/PointStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Polygon.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/PolygonStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Pose.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Pose2D.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/PoseArray.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/PoseStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/PoseWithCovariance.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/PoseWithCovarianceStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Quaternion.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/QuaternionStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Transform.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/TransformStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Twist.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/TwistStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/TwistWithCovariance.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/TwistWithCovarianceStamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Vector3.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Vector3Stamped.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/Wrench.idl
CMakeFiles/body_tracking: /opt/ros/foxy/share/geometry_msgs/msg/WrenchStamped.idl


body_tracking: CMakeFiles/body_tracking
body_tracking: CMakeFiles/body_tracking.dir/build.make

.PHONY : body_tracking

# Rule to build all files generated by this target.
CMakeFiles/body_tracking.dir/build: body_tracking

.PHONY : CMakeFiles/body_tracking.dir/build

CMakeFiles/body_tracking.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/body_tracking.dir/cmake_clean.cmake
.PHONY : CMakeFiles/body_tracking.dir/clean

CMakeFiles/body_tracking.dir/depend:
	cd /home/robogait/azure_kinect_ws/build/body_tracking && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robogait/azure_kinect_ws/src/body_tracking /home/robogait/azure_kinect_ws/src/body_tracking /home/robogait/azure_kinect_ws/build/body_tracking /home/robogait/azure_kinect_ws/build/body_tracking /home/robogait/azure_kinect_ws/build/body_tracking/CMakeFiles/body_tracking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/body_tracking.dir/depend

