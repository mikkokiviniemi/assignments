# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build

# Include any dependencies generated for this target.
include includes/CMakeFiles/food.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include includes/CMakeFiles/food.dir/compiler_depend.make

# Include the progress variables for this target.
include includes/CMakeFiles/food.dir/progress.make

# Include the compile flags for this target's objects.
include includes/CMakeFiles/food.dir/flags.make

includes/CMakeFiles/food.dir/food.cpp.o: includes/CMakeFiles/food.dir/flags.make
includes/CMakeFiles/food.dir/food.cpp.o: ../includes/food.cpp
includes/CMakeFiles/food.dir/food.cpp.o: includes/CMakeFiles/food.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object includes/CMakeFiles/food.dir/food.cpp.o"
	cd /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build/includes && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT includes/CMakeFiles/food.dir/food.cpp.o -MF CMakeFiles/food.dir/food.cpp.o.d -o CMakeFiles/food.dir/food.cpp.o -c /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/includes/food.cpp

includes/CMakeFiles/food.dir/food.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/food.dir/food.cpp.i"
	cd /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build/includes && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/includes/food.cpp > CMakeFiles/food.dir/food.cpp.i

includes/CMakeFiles/food.dir/food.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/food.dir/food.cpp.s"
	cd /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build/includes && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/includes/food.cpp -o CMakeFiles/food.dir/food.cpp.s

# Object files for target food
food_OBJECTS = \
"CMakeFiles/food.dir/food.cpp.o"

# External object files for target food
food_EXTERNAL_OBJECTS =

includes/libfood.a: includes/CMakeFiles/food.dir/food.cpp.o
includes/libfood.a: includes/CMakeFiles/food.dir/build.make
includes/libfood.a: includes/CMakeFiles/food.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libfood.a"
	cd /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build/includes && $(CMAKE_COMMAND) -P CMakeFiles/food.dir/cmake_clean_target.cmake
	cd /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build/includes && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/food.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
includes/CMakeFiles/food.dir/build: includes/libfood.a
.PHONY : includes/CMakeFiles/food.dir/build

includes/CMakeFiles/food.dir/clean:
	cd /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build/includes && $(CMAKE_COMMAND) -P CMakeFiles/food.dir/cmake_clean.cmake
.PHONY : includes/CMakeFiles/food.dir/clean

includes/CMakeFiles/food.dir/depend:
	cd /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1 /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/includes /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build/includes /home/mikkoki/in_progress/week2/Tuesday/assignment2_2_1/build/includes/CMakeFiles/food.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : includes/CMakeFiles/food.dir/depend

