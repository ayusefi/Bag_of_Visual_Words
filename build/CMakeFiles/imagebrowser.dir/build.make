# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/abdullah/modern_cpp/Bag_of_Visual_Words

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abdullah/modern_cpp/Bag_of_Visual_Words/build

# Include any dependencies generated for this target.
include CMakeFiles/imagebrowser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/imagebrowser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/imagebrowser.dir/flags.make

CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o: CMakeFiles/imagebrowser.dir/flags.make
CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o: ../src/image_browser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abdullah/modern_cpp/Bag_of_Visual_Words/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o -c /home/abdullah/modern_cpp/Bag_of_Visual_Words/src/image_browser.cpp

CMakeFiles/imagebrowser.dir/src/image_browser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imagebrowser.dir/src/image_browser.cpp.i"
	/usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdullah/modern_cpp/Bag_of_Visual_Words/src/image_browser.cpp > CMakeFiles/imagebrowser.dir/src/image_browser.cpp.i

CMakeFiles/imagebrowser.dir/src/image_browser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imagebrowser.dir/src/image_browser.cpp.s"
	/usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdullah/modern_cpp/Bag_of_Visual_Words/src/image_browser.cpp -o CMakeFiles/imagebrowser.dir/src/image_browser.cpp.s

CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o.requires:

.PHONY : CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o.requires

CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o.provides: CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o.requires
	$(MAKE) -f CMakeFiles/imagebrowser.dir/build.make CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o.provides.build
.PHONY : CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o.provides

CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o.provides.build: CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o


# Object files for target imagebrowser
imagebrowser_OBJECTS = \
"CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o"

# External object files for target imagebrowser
imagebrowser_EXTERNAL_OBJECTS =

libimagebrowser.a: CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o
libimagebrowser.a: CMakeFiles/imagebrowser.dir/build.make
libimagebrowser.a: CMakeFiles/imagebrowser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abdullah/modern_cpp/Bag_of_Visual_Words/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libimagebrowser.a"
	$(CMAKE_COMMAND) -P CMakeFiles/imagebrowser.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imagebrowser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/imagebrowser.dir/build: libimagebrowser.a

.PHONY : CMakeFiles/imagebrowser.dir/build

CMakeFiles/imagebrowser.dir/requires: CMakeFiles/imagebrowser.dir/src/image_browser.cpp.o.requires

.PHONY : CMakeFiles/imagebrowser.dir/requires

CMakeFiles/imagebrowser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/imagebrowser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/imagebrowser.dir/clean

CMakeFiles/imagebrowser.dir/depend:
	cd /home/abdullah/modern_cpp/Bag_of_Visual_Words/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abdullah/modern_cpp/Bag_of_Visual_Words /home/abdullah/modern_cpp/Bag_of_Visual_Words /home/abdullah/modern_cpp/Bag_of_Visual_Words/build /home/abdullah/modern_cpp/Bag_of_Visual_Words/build /home/abdullah/modern_cpp/Bag_of_Visual_Words/build/CMakeFiles/imagebrowser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imagebrowser.dir/depend

