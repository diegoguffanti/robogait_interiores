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

# Include any dependencies generated for this target.
include CMakeFiles/body_tracking__python.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/body_tracking__python.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/body_tracking__python.dir/flags.make

CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.o: CMakeFiles/body_tracking__python.dir/flags.make
CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.o: rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robogait/azure_kinect_ws/build/body_tracking/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.o   -c /home/robogait/azure_kinect_ws/build/body_tracking/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c

CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/robogait/azure_kinect_ws/build/body_tracking/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c > CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.i

CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/robogait/azure_kinect_ws/build/body_tracking/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c -o CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.s

CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.o: CMakeFiles/body_tracking__python.dir/flags.make
CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.o: rosidl_generator_py/body_tracking/msg/_skeleton_s.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robogait/azure_kinect_ws/build/body_tracking/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.o   -c /home/robogait/azure_kinect_ws/build/body_tracking/rosidl_generator_py/body_tracking/msg/_skeleton_s.c

CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/robogait/azure_kinect_ws/build/body_tracking/rosidl_generator_py/body_tracking/msg/_skeleton_s.c > CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.i

CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/robogait/azure_kinect_ws/build/body_tracking/rosidl_generator_py/body_tracking/msg/_skeleton_s.c -o CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.s

# Object files for target body_tracking__python
body_tracking__python_OBJECTS = \
"CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.o" \
"CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.o"

# External object files for target body_tracking__python
body_tracking__python_EXTERNAL_OBJECTS =

rosidl_generator_py/body_tracking/libbody_tracking__python.so: CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_hip_coordinates_s.c.o
rosidl_generator_py/body_tracking/libbody_tracking__python.so: CMakeFiles/body_tracking__python.dir/rosidl_generator_py/body_tracking/msg/_skeleton_s.c.o
rosidl_generator_py/body_tracking/libbody_tracking__python.so: CMakeFiles/body_tracking__python.dir/build.make
rosidl_generator_py/body_tracking/libbody_tracking__python.so: libbody_tracking__rosidl_generator_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /usr/lib/x86_64-linux-gnu/libpython3.8.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: libbody_tracking__rosidl_typesupport_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/share/geometry_msgs/cmake/../../../lib/libgeometry_msgs__python.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/share/std_msgs/cmake/../../../lib/libstd_msgs__python.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/share/builtin_interfaces/cmake/../../../lib/libbuiltin_interfaces__python.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_introspection_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_generator_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_introspection_cpp.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_cpp.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_generator_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_cpp.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_generator_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/librosidl_typesupport_introspection_cpp.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/librosidl_typesupport_introspection_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/librosidl_typesupport_cpp.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/librosidl_typesupport_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/librosidl_runtime_c.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/librcpputils.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: /opt/ros/foxy/lib/librcutils.so
rosidl_generator_py/body_tracking/libbody_tracking__python.so: CMakeFiles/body_tracking__python.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robogait/azure_kinect_ws/build/body_tracking/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library rosidl_generator_py/body_tracking/libbody_tracking__python.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/body_tracking__python.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/body_tracking__python.dir/build: rosidl_generator_py/body_tracking/libbody_tracking__python.so

.PHONY : CMakeFiles/body_tracking__python.dir/build

CMakeFiles/body_tracking__python.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/body_tracking__python.dir/cmake_clean.cmake
.PHONY : CMakeFiles/body_tracking__python.dir/clean

CMakeFiles/body_tracking__python.dir/depend:
	cd /home/robogait/azure_kinect_ws/build/body_tracking && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robogait/azure_kinect_ws/src/body_tracking /home/robogait/azure_kinect_ws/src/body_tracking /home/robogait/azure_kinect_ws/build/body_tracking /home/robogait/azure_kinect_ws/build/body_tracking /home/robogait/azure_kinect_ws/build/body_tracking/CMakeFiles/body_tracking__python.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/body_tracking__python.dir/depend

