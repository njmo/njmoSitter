# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_SOURCE_DIR = /home/njmo/njmositter/rpi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/njmo/njmositter/rpi/cmake

# Include any dependencies generated for this target.
include application/utils/CMakeFiles/utils.dir/depend.make

# Include the progress variables for this target.
include application/utils/CMakeFiles/utils.dir/progress.make

# Include the compile flags for this target's objects.
include application/utils/CMakeFiles/utils.dir/flags.make

application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o: application/utils/CMakeFiles/utils.dir/flags.make
application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o: ../application/utils/Logger/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/njmo/njmositter/rpi/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o"
	cd /home/njmo/njmositter/rpi/cmake/application/utils && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/utils.dir/Logger/Logger.cpp.o -c /home/njmo/njmositter/rpi/application/utils/Logger/Logger.cpp

application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/Logger/Logger.cpp.i"
	cd /home/njmo/njmositter/rpi/cmake/application/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/njmo/njmositter/rpi/application/utils/Logger/Logger.cpp > CMakeFiles/utils.dir/Logger/Logger.cpp.i

application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/Logger/Logger.cpp.s"
	cd /home/njmo/njmositter/rpi/cmake/application/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/njmo/njmositter/rpi/application/utils/Logger/Logger.cpp -o CMakeFiles/utils.dir/Logger/Logger.cpp.s

application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o.requires:

.PHONY : application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o.requires

application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o.provides: application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o.requires
	$(MAKE) -f application/utils/CMakeFiles/utils.dir/build.make application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o.provides.build
.PHONY : application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o.provides

application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o.provides.build: application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o


# Object files for target utils
utils_OBJECTS = \
"CMakeFiles/utils.dir/Logger/Logger.cpp.o"

# External object files for target utils
utils_EXTERNAL_OBJECTS =

application/utils/libutils.a: application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o
application/utils/libutils.a: application/utils/CMakeFiles/utils.dir/build.make
application/utils/libutils.a: application/utils/CMakeFiles/utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/njmo/njmositter/rpi/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libutils.a"
	cd /home/njmo/njmositter/rpi/cmake/application/utils && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean_target.cmake
	cd /home/njmo/njmositter/rpi/cmake/application/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
application/utils/CMakeFiles/utils.dir/build: application/utils/libutils.a

.PHONY : application/utils/CMakeFiles/utils.dir/build

application/utils/CMakeFiles/utils.dir/requires: application/utils/CMakeFiles/utils.dir/Logger/Logger.cpp.o.requires

.PHONY : application/utils/CMakeFiles/utils.dir/requires

application/utils/CMakeFiles/utils.dir/clean:
	cd /home/njmo/njmositter/rpi/cmake/application/utils && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean.cmake
.PHONY : application/utils/CMakeFiles/utils.dir/clean

application/utils/CMakeFiles/utils.dir/depend:
	cd /home/njmo/njmositter/rpi/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/njmo/njmositter/rpi /home/njmo/njmositter/rpi/application/utils /home/njmo/njmositter/rpi/cmake /home/njmo/njmositter/rpi/cmake/application/utils /home/njmo/njmositter/rpi/cmake/application/utils/CMakeFiles/utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : application/utils/CMakeFiles/utils.dir/depend

