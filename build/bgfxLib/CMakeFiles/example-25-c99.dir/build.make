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
include bgfxLib/CMakeFiles/example-25-c99.dir/depend.make

# Include the progress variables for this target.
include bgfxLib/CMakeFiles/example-25-c99.dir/progress.make

# Include the compile flags for this target's objects.
include bgfxLib/CMakeFiles/example-25-c99.dir/flags.make

bgfxLib/CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.o: bgfxLib/CMakeFiles/example-25-c99.dir/flags.make
bgfxLib/CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.o: ../bgfxLib/bgfx/examples/25-c99/helloworld.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object bgfxLib/CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.o"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.o   -c /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/25-c99/helloworld.c

bgfxLib/CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.i"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/25-c99/helloworld.c > CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.i

bgfxLib/CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.s"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/25-c99/helloworld.c -o CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.s

# Object files for target example-25-c99
example__25__c99_OBJECTS = \
"CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.o"

# External object files for target example-25-c99
example__25__c99_EXTERNAL_OBJECTS =

bgfxLib/example-25-c99: bgfxLib/CMakeFiles/example-25-c99.dir/bgfx/examples/25-c99/helloworld.c.o
bgfxLib/example-25-c99: bgfxLib/CMakeFiles/example-25-c99.dir/build.make
bgfxLib/example-25-c99: bgfxLib/libexample-common.a
bgfxLib/example-25-c99: bgfxLib/libbgfx.a
bgfxLib/example-25-c99: bgfxLib/libbimg.a
bgfxLib/example-25-c99: bgfxLib/libastc.a
bgfxLib/example-25-c99: bgfxLib/libedtaa3.a
bgfxLib/example-25-c99: bgfxLib/libetc1.a
bgfxLib/example-25-c99: bgfxLib/libetc2.a
bgfxLib/example-25-c99: bgfxLib/libiqa.a
bgfxLib/example-25-c99: bgfxLib/libsquish.a
bgfxLib/example-25-c99: bgfxLib/libnvtt.a
bgfxLib/example-25-c99: bgfxLib/libpvrtc.a
bgfxLib/example-25-c99: bgfxLib/libib-compress.a
bgfxLib/example-25-c99: bgfxLib/libdear-imgui.a
bgfxLib/example-25-c99: bgfxLib/libbx.a
bgfxLib/example-25-c99: bgfxLib/CMakeFiles/example-25-c99.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example-25-c99"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example-25-c99.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bgfxLib/CMakeFiles/example-25-c99.dir/build: bgfxLib/example-25-c99

.PHONY : bgfxLib/CMakeFiles/example-25-c99.dir/build

bgfxLib/CMakeFiles/example-25-c99.dir/clean:
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && $(CMAKE_COMMAND) -P CMakeFiles/example-25-c99.dir/cmake_clean.cmake
.PHONY : bgfxLib/CMakeFiles/example-25-c99.dir/clean

bgfxLib/CMakeFiles/example-25-c99.dir/depend:
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib/CMakeFiles/example-25-c99.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bgfxLib/CMakeFiles/example-25-c99.dir/depend

