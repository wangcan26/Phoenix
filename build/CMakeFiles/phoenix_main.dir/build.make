# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build

# Include any dependencies generated for this target.
include CMakeFiles/phoenix_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/phoenix_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/phoenix_main.dir/flags.make

CMakeFiles/phoenix_main.dir/main.cc.o: CMakeFiles/phoenix_main.dir/flags.make
CMakeFiles/phoenix_main.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/phoenix_main.dir/main.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phoenix_main.dir/main.cc.o -c /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/main.cc

CMakeFiles/phoenix_main.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phoenix_main.dir/main.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/main.cc > CMakeFiles/phoenix_main.dir/main.cc.i

CMakeFiles/phoenix_main.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phoenix_main.dir/main.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/main.cc -o CMakeFiles/phoenix_main.dir/main.cc.s

# Object files for target phoenix_main
phoenix_main_OBJECTS = \
"CMakeFiles/phoenix_main.dir/main.cc.o"

# External object files for target phoenix_main
phoenix_main_EXTERNAL_OBJECTS =

phoenix_main: CMakeFiles/phoenix_main.dir/main.cc.o
phoenix_main: CMakeFiles/phoenix_main.dir/build.make
phoenix_main: /System/Library/Frameworks/Foundation.framework/Foundation
phoenix_main: /System/Library/Frameworks/Cocoa.framework/Cocoa
phoenix_main: /System/Library/Frameworks/Metal.framework/Metal
phoenix_main: /System/Library/Frameworks/QuartzCore.framework/QuartzCore
phoenix_main: ../install/lib/libbgfx.a
phoenix_main: ../install/lib/libbimg.a
phoenix_main: ../install/lib/libbx.a
phoenix_main: CMakeFiles/phoenix_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable phoenix_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/phoenix_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/phoenix_main.dir/build: phoenix_main

.PHONY : CMakeFiles/phoenix_main.dir/build

CMakeFiles/phoenix_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/phoenix_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/phoenix_main.dir/clean

CMakeFiles/phoenix_main.dir/depend:
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles/phoenix_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/phoenix_main.dir/depend

