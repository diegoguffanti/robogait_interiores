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
CMAKE_SOURCE_DIR = /home/robogait/azure_kinect_ws/src/kinect_azure_body_tracker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker

# Include any dependencies generated for this target.
include CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/flags.make

CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.o: CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/flags.make
CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.o: /home/robogait/azure_kinect_ws/src/kinect_azure_body_tracker/src/kinectAzure_body_tracker_node_plus_recording_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.o -c /home/robogait/azure_kinect_ws/src/kinect_azure_body_tracker/src/kinectAzure_body_tracker_node_plus_recording_test.cpp

CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robogait/azure_kinect_ws/src/kinect_azure_body_tracker/src/kinectAzure_body_tracker_node_plus_recording_test.cpp > CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.i

CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robogait/azure_kinect_ws/src/kinect_azure_body_tracker/src/kinectAzure_body_tracker_node_plus_recording_test.cpp -o CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.s

# Object files for target kinect_azure_body_tracker_node_plus_recording_test
kinect_azure_body_tracker_node_plus_recording_test_OBJECTS = \
"CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.o"

# External object files for target kinect_azure_body_tracker_node_plus_recording_test
kinect_azure_body_tracker_node_plus_recording_test_EXTERNAL_OBJECTS =

kinect_azure_body_tracker_node_plus_recording_test: CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/src/kinectAzure_body_tracker_node_plus_recording_test.cpp.o
kinect_azure_body_tracker_node_plus_recording_test: CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/build.make
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librclcpp.so
kinect_azure_body_tracker_node_plus_recording_test: /home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib/libbody_tracker_msgs__rosidl_typesupport_introspection_c.so
kinect_azure_body_tracker_node_plus_recording_test: /home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib/libbody_tracker_msgs__rosidl_typesupport_c.so
kinect_azure_body_tracker_node_plus_recording_test: /home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib/libbody_tracker_msgs__rosidl_typesupport_introspection_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib/libbody_tracker_msgs__rosidl_typesupport_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/liblibstatistics_collector.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_introspection_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_generator_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_introspection_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librcl.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librcl_interfaces__rosidl_generator_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librmw_implementation.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librmw.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librcl_logging_spdlog.so
kinect_azure_body_tracker_node_plus_recording_test: /usr/lib/x86_64-linux-gnu/libspdlog.so.1.5.0
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librcl_yaml_param_parser.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libyaml.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_generator_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_generator_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libtracetools.so
kinect_azure_body_tracker_node_plus_recording_test: /home/robogait/azure_kinect_ws/install/body_tracker_msgs/lib/libbody_tracker_msgs__rosidl_generator_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_introspection_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_generator_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_introspection_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libstd_msgs__rosidl_generator_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_generator_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librosidl_typesupport_introspection_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librosidl_typesupport_introspection_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librosidl_typesupport_cpp.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librosidl_typesupport_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librcpputils.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librosidl_runtime_c.so
kinect_azure_body_tracker_node_plus_recording_test: /opt/ros/foxy/lib/librcutils.so
kinect_azure_body_tracker_node_plus_recording_test: CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kinect_azure_body_tracker_node_plus_recording_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/build: kinect_azure_body_tracker_node_plus_recording_test

.PHONY : CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/build

CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/clean

CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/depend:
	cd /home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robogait/azure_kinect_ws/src/kinect_azure_body_tracker /home/robogait/azure_kinect_ws/src/kinect_azure_body_tracker /home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker /home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker /home/robogait/azure_kinect_ws/build/kinect_azure_body_tracker/CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kinect_azure_body_tracker_node_plus_recording_test.dir/depend

