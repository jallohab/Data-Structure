# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/5th.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/5th.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5th.dir/flags.make

CMakeFiles/5th.dir/main.cpp.o: CMakeFiles/5th.dir/flags.make
CMakeFiles/5th.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/5th.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/5th.dir/main.cpp.o -c "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th/main.cpp"

CMakeFiles/5th.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/5th.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th/main.cpp" > CMakeFiles/5th.dir/main.cpp.i

CMakeFiles/5th.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/5th.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th/main.cpp" -o CMakeFiles/5th.dir/main.cpp.s

# Object files for target 5th
5th_OBJECTS = \
"CMakeFiles/5th.dir/main.cpp.o"

# External object files for target 5th
5th_EXTERNAL_OBJECTS =

5th: CMakeFiles/5th.dir/main.cpp.o
5th: CMakeFiles/5th.dir/build.make
5th: CMakeFiles/5th.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 5th"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/5th.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5th.dir/build: 5th

.PHONY : CMakeFiles/5th.dir/build

CMakeFiles/5th.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/5th.dir/cmake_clean.cmake
.PHONY : CMakeFiles/5th.dir/clean

CMakeFiles/5th.dir/depend:
	cd "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th" "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th" "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th/cmake-build-debug" "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th/cmake-build-debug" "/mnt/c/Users/luox6/OneDrive - Rensselaer Polytechnic Institute/Documents/Project/DS/hw/5th/cmake-build-debug/CMakeFiles/5th.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/5th.dir/depend
