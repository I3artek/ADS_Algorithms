# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Midterm_task_2_c.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Midterm_task_2_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Midterm_task_2_c.dir/flags.make

CMakeFiles/Midterm_task_2_c.dir/main.c.o: CMakeFiles/Midterm_task_2_c.dir/flags.make
CMakeFiles/Midterm_task_2_c.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Midterm_task_2_c.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Midterm_task_2_c.dir/main.c.o -c /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong/main.c

CMakeFiles/Midterm_task_2_c.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Midterm_task_2_c.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong/main.c > CMakeFiles/Midterm_task_2_c.dir/main.c.i

CMakeFiles/Midterm_task_2_c.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Midterm_task_2_c.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong/main.c -o CMakeFiles/Midterm_task_2_c.dir/main.c.s

# Object files for target Midterm_task_2_c
Midterm_task_2_c_OBJECTS = \
"CMakeFiles/Midterm_task_2_c.dir/main.c.o"

# External object files for target Midterm_task_2_c
Midterm_task_2_c_EXTERNAL_OBJECTS =

Midterm_task_2_c: CMakeFiles/Midterm_task_2_c.dir/main.c.o
Midterm_task_2_c: CMakeFiles/Midterm_task_2_c.dir/build.make
Midterm_task_2_c: CMakeFiles/Midterm_task_2_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Midterm_task_2_c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Midterm_task_2_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Midterm_task_2_c.dir/build: Midterm_task_2_c
.PHONY : CMakeFiles/Midterm_task_2_c.dir/build

CMakeFiles/Midterm_task_2_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Midterm_task_2_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Midterm_task_2_c.dir/clean

CMakeFiles/Midterm_task_2_c.dir/depend:
	cd /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong/cmake-build-debug /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong/cmake-build-debug /Users/i3artek/Studies/Clion_/ADS_Algorithms/Midterm_task_2_wrong/cmake-build-debug/CMakeFiles/Midterm_task_2_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Midterm_task_2_c.dir/depend

