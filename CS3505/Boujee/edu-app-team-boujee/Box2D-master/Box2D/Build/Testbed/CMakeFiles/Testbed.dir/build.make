# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/stow/cmake/cmake-3.4.1/bin/cmake

# The command to remove a file.
RM = /usr/local/stow/cmake/cmake-3.4.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/amcghie/CS3505/Box2D-master/Box2D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amcghie/CS3505/Box2D-master/Box2D/Build

# Include any dependencies generated for this target.
include Testbed/CMakeFiles/Testbed.dir/depend.make

# Include the progress variables for this target.
include Testbed/CMakeFiles/Testbed.dir/progress.make

# Include the compile flags for this target's objects.
include Testbed/CMakeFiles/Testbed.dir/flags.make

# Object files for target Testbed
Testbed_OBJECTS =

# External object files for target Testbed
Testbed_EXTERNAL_OBJECTS =

Testbed/Testbed: Testbed/CMakeFiles/Testbed.dir/build.make
Testbed/Testbed: Box2D/libBox2D.a
Testbed/Testbed: glew/libglew.a
Testbed/Testbed: glfw/libglfw.a
Testbed/Testbed: /usr/lib64/libGLU.so
Testbed/Testbed: /usr/lib64/libGL.so
Testbed/Testbed: Testbed/CMakeFiles/Testbed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amcghie/CS3505/Box2D-master/Box2D/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX executable Testbed"
	cd /home/amcghie/CS3505/Box2D-master/Box2D/Build/Testbed && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Testbed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Testbed/CMakeFiles/Testbed.dir/build: Testbed/Testbed

.PHONY : Testbed/CMakeFiles/Testbed.dir/build

Testbed/CMakeFiles/Testbed.dir/requires:

.PHONY : Testbed/CMakeFiles/Testbed.dir/requires

Testbed/CMakeFiles/Testbed.dir/clean:
	cd /home/amcghie/CS3505/Box2D-master/Box2D/Build/Testbed && $(CMAKE_COMMAND) -P CMakeFiles/Testbed.dir/cmake_clean.cmake
.PHONY : Testbed/CMakeFiles/Testbed.dir/clean

Testbed/CMakeFiles/Testbed.dir/depend:
	cd /home/amcghie/CS3505/Box2D-master/Box2D/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amcghie/CS3505/Box2D-master/Box2D /home/amcghie/CS3505/Box2D-master/Box2D/Testbed /home/amcghie/CS3505/Box2D-master/Box2D/Build /home/amcghie/CS3505/Box2D-master/Box2D/Build/Testbed /home/amcghie/CS3505/Box2D-master/Box2D/Build/Testbed/CMakeFiles/Testbed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Testbed/CMakeFiles/Testbed.dir/depend

