# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/nishanth/Desktop/Assignments/Assignment2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nishanth/Desktop/Assignments/Assignment2/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/md4_o.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/md4_o.cpp.o: /home/nishanth/Desktop/Assignments/Assignment2/md4_o.cpp
CMakeFiles/main.dir/md4_o.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nishanth/Desktop/Assignments/Assignment2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/md4_o.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/md4_o.cpp.o -MF CMakeFiles/main.dir/md4_o.cpp.o.d -o CMakeFiles/main.dir/md4_o.cpp.o -c /home/nishanth/Desktop/Assignments/Assignment2/md4_o.cpp

CMakeFiles/main.dir/md4_o.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/md4_o.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nishanth/Desktop/Assignments/Assignment2/md4_o.cpp > CMakeFiles/main.dir/md4_o.cpp.i

CMakeFiles/main.dir/md4_o.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/md4_o.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nishanth/Desktop/Assignments/Assignment2/md4_o.cpp -o CMakeFiles/main.dir/md4_o.cpp.s

CMakeFiles/main.dir/rand.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/rand.cpp.o: /home/nishanth/Desktop/Assignments/Assignment2/rand.cpp
CMakeFiles/main.dir/rand.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nishanth/Desktop/Assignments/Assignment2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/rand.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/rand.cpp.o -MF CMakeFiles/main.dir/rand.cpp.o.d -o CMakeFiles/main.dir/rand.cpp.o -c /home/nishanth/Desktop/Assignments/Assignment2/rand.cpp

CMakeFiles/main.dir/rand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/rand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nishanth/Desktop/Assignments/Assignment2/rand.cpp > CMakeFiles/main.dir/rand.cpp.i

CMakeFiles/main.dir/rand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/rand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nishanth/Desktop/Assignments/Assignment2/rand.cpp -o CMakeFiles/main.dir/rand.cpp.s

CMakeFiles/main.dir/stream.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/stream.cpp.o: /home/nishanth/Desktop/Assignments/Assignment2/stream.cpp
CMakeFiles/main.dir/stream.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nishanth/Desktop/Assignments/Assignment2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/stream.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/stream.cpp.o -MF CMakeFiles/main.dir/stream.cpp.o.d -o CMakeFiles/main.dir/stream.cpp.o -c /home/nishanth/Desktop/Assignments/Assignment2/stream.cpp

CMakeFiles/main.dir/stream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/stream.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nishanth/Desktop/Assignments/Assignment2/stream.cpp > CMakeFiles/main.dir/stream.cpp.i

CMakeFiles/main.dir/stream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/stream.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nishanth/Desktop/Assignments/Assignment2/stream.cpp -o CMakeFiles/main.dir/stream.cpp.s

CMakeFiles/main.dir/util.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/util.cpp.o: /home/nishanth/Desktop/Assignments/Assignment2/util.cpp
CMakeFiles/main.dir/util.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nishanth/Desktop/Assignments/Assignment2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/util.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/util.cpp.o -MF CMakeFiles/main.dir/util.cpp.o.d -o CMakeFiles/main.dir/util.cpp.o -c /home/nishanth/Desktop/Assignments/Assignment2/util.cpp

CMakeFiles/main.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nishanth/Desktop/Assignments/Assignment2/util.cpp > CMakeFiles/main.dir/util.cpp.i

CMakeFiles/main.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nishanth/Desktop/Assignments/Assignment2/util.cpp -o CMakeFiles/main.dir/util.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/md4_o.cpp.o" \
"CMakeFiles/main.dir/rand.cpp.o" \
"CMakeFiles/main.dir/stream.cpp.o" \
"CMakeFiles/main.dir/util.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/md4_o.cpp.o
main: CMakeFiles/main.dir/rand.cpp.o
main: CMakeFiles/main.dir/stream.cpp.o
main: CMakeFiles/main.dir/util.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nishanth/Desktop/Assignments/Assignment2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/nishanth/Desktop/Assignments/Assignment2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nishanth/Desktop/Assignments/Assignment2 /home/nishanth/Desktop/Assignments/Assignment2 /home/nishanth/Desktop/Assignments/Assignment2/build /home/nishanth/Desktop/Assignments/Assignment2/build /home/nishanth/Desktop/Assignments/Assignment2/build/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend
