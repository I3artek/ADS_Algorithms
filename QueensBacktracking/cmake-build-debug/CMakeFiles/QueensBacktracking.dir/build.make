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
CMAKE_SOURCE_DIR = /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/QueensBacktracking.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/QueensBacktracking.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QueensBacktracking.dir/flags.make

CMakeFiles/QueensBacktracking.dir/main.c.o: CMakeFiles/QueensBacktracking.dir/flags.make
CMakeFiles/QueensBacktracking.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/QueensBacktracking.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/QueensBacktracking.dir/main.c.o -c /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/main.c

CMakeFiles/QueensBacktracking.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/QueensBacktracking.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/main.c > CMakeFiles/QueensBacktracking.dir/main.c.i

CMakeFiles/QueensBacktracking.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/QueensBacktracking.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/main.c -o CMakeFiles/QueensBacktracking.dir/main.c.s

CMakeFiles/QueensBacktracking.dir/Algorithm.c.o: CMakeFiles/QueensBacktracking.dir/flags.make
CMakeFiles/QueensBacktracking.dir/Algorithm.c.o: ../Algorithm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/QueensBacktracking.dir/Algorithm.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/QueensBacktracking.dir/Algorithm.c.o -c /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/Algorithm.c

CMakeFiles/QueensBacktracking.dir/Algorithm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/QueensBacktracking.dir/Algorithm.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/Algorithm.c > CMakeFiles/QueensBacktracking.dir/Algorithm.c.i

CMakeFiles/QueensBacktracking.dir/Algorithm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/QueensBacktracking.dir/Algorithm.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/Algorithm.c -o CMakeFiles/QueensBacktracking.dir/Algorithm.c.s

# Object files for target QueensBacktracking
QueensBacktracking_OBJECTS = \
"CMakeFiles/QueensBacktracking.dir/main.c.o" \
"CMakeFiles/QueensBacktracking.dir/Algorithm.c.o"

# External object files for target QueensBacktracking
QueensBacktracking_EXTERNAL_OBJECTS =

QueensBacktracking: CMakeFiles/QueensBacktracking.dir/main.c.o
QueensBacktracking: CMakeFiles/QueensBacktracking.dir/Algorithm.c.o
QueensBacktracking: CMakeFiles/QueensBacktracking.dir/build.make
QueensBacktracking: CMakeFiles/QueensBacktracking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable QueensBacktracking"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QueensBacktracking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QueensBacktracking.dir/build: QueensBacktracking
.PHONY : CMakeFiles/QueensBacktracking.dir/build

CMakeFiles/QueensBacktracking.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QueensBacktracking.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QueensBacktracking.dir/clean

CMakeFiles/QueensBacktracking.dir/depend:
	cd /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/cmake-build-debug /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/cmake-build-debug /Users/i3artek/Studies/Clion_/ADS_Algorithms/QueensBacktracking/cmake-build-debug/CMakeFiles/QueensBacktracking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QueensBacktracking.dir/depend

