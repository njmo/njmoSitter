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
include application/event/executors/CMakeFiles/executors.dir/depend.make

# Include the progress variables for this target.
include application/event/executors/CMakeFiles/executors.dir/progress.make

# Include the compile flags for this target's objects.
include application/event/executors/CMakeFiles/executors.dir/flags.make

application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o: application/event/executors/CMakeFiles/executors.dir/flags.make
application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o: ../application/event/executors/EventExecutor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/njmo/njmositter/rpi/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o"
	cd /home/njmo/njmositter/rpi/cmake/application/event/executors && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executors.dir/EventExecutor.cpp.o -c /home/njmo/njmositter/rpi/application/event/executors/EventExecutor.cpp

application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executors.dir/EventExecutor.cpp.i"
	cd /home/njmo/njmositter/rpi/cmake/application/event/executors && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/njmo/njmositter/rpi/application/event/executors/EventExecutor.cpp > CMakeFiles/executors.dir/EventExecutor.cpp.i

application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executors.dir/EventExecutor.cpp.s"
	cd /home/njmo/njmositter/rpi/cmake/application/event/executors && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/njmo/njmositter/rpi/application/event/executors/EventExecutor.cpp -o CMakeFiles/executors.dir/EventExecutor.cpp.s

application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o.requires:

.PHONY : application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o.requires

application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o.provides: application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o.requires
	$(MAKE) -f application/event/executors/CMakeFiles/executors.dir/build.make application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o.provides.build
.PHONY : application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o.provides

application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o.provides.build: application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o


application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o: application/event/executors/CMakeFiles/executors.dir/flags.make
application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o: ../application/event/executors/TestExecutor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/njmo/njmositter/rpi/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o"
	cd /home/njmo/njmositter/rpi/cmake/application/event/executors && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executors.dir/TestExecutor.cpp.o -c /home/njmo/njmositter/rpi/application/event/executors/TestExecutor.cpp

application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executors.dir/TestExecutor.cpp.i"
	cd /home/njmo/njmositter/rpi/cmake/application/event/executors && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/njmo/njmositter/rpi/application/event/executors/TestExecutor.cpp > CMakeFiles/executors.dir/TestExecutor.cpp.i

application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executors.dir/TestExecutor.cpp.s"
	cd /home/njmo/njmositter/rpi/cmake/application/event/executors && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/njmo/njmositter/rpi/application/event/executors/TestExecutor.cpp -o CMakeFiles/executors.dir/TestExecutor.cpp.s

application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o.requires:

.PHONY : application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o.requires

application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o.provides: application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o.requires
	$(MAKE) -f application/event/executors/CMakeFiles/executors.dir/build.make application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o.provides.build
.PHONY : application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o.provides

application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o.provides.build: application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o


executors: application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o
executors: application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o
executors: application/event/executors/CMakeFiles/executors.dir/build.make

.PHONY : executors

# Rule to build all files generated by this target.
application/event/executors/CMakeFiles/executors.dir/build: executors

.PHONY : application/event/executors/CMakeFiles/executors.dir/build

application/event/executors/CMakeFiles/executors.dir/requires: application/event/executors/CMakeFiles/executors.dir/EventExecutor.cpp.o.requires
application/event/executors/CMakeFiles/executors.dir/requires: application/event/executors/CMakeFiles/executors.dir/TestExecutor.cpp.o.requires

.PHONY : application/event/executors/CMakeFiles/executors.dir/requires

application/event/executors/CMakeFiles/executors.dir/clean:
	cd /home/njmo/njmositter/rpi/cmake/application/event/executors && $(CMAKE_COMMAND) -P CMakeFiles/executors.dir/cmake_clean.cmake
.PHONY : application/event/executors/CMakeFiles/executors.dir/clean

application/event/executors/CMakeFiles/executors.dir/depend:
	cd /home/njmo/njmositter/rpi/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/njmo/njmositter/rpi /home/njmo/njmositter/rpi/application/event/executors /home/njmo/njmositter/rpi/cmake /home/njmo/njmositter/rpi/cmake/application/event/executors /home/njmo/njmositter/rpi/cmake/application/event/executors/CMakeFiles/executors.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : application/event/executors/CMakeFiles/executors.dir/depend

