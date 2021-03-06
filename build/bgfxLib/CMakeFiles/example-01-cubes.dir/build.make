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
include bgfxLib/CMakeFiles/example-01-cubes.dir/depend.make

# Include the progress variables for this target.
include bgfxLib/CMakeFiles/example-01-cubes.dir/progress.make

# Include the compile flags for this target's objects.
include bgfxLib/CMakeFiles/example-01-cubes.dir/flags.make

../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_cubes.bin: ../bgfxLib/bgfx/examples/01-cubes/fs_cubes.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Compiling shader 01-cubes/fs_cubes.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/01-cubes/fs_cubes.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/fs_cubes.bin --platform osx --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/01-cubes/fs_cubes.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/fs_cubes.bin --platform android --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/01-cubes/fs_cubes.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_cubes.bin --platform linux --type fragment --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_cubes.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_cubes.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_cubes.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_cubes.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_cubes.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_cubes.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_cubes.bin: ../bgfxLib/bgfx/examples/01-cubes/vs_cubes.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Compiling shader 01-cubes/vs_cubes.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/01-cubes/vs_cubes.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/vs_cubes.bin --platform osx --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/01-cubes/vs_cubes.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/vs_cubes.bin --platform android --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/01-cubes/vs_cubes.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_cubes.bin --platform linux --type vertex --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_cubes.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_cubes.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_cubes.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_cubes.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_cubes.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_cubes.bin

bgfxLib/CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.o: bgfxLib/CMakeFiles/example-01-cubes.dir/flags.make
bgfxLib/CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.o: ../bgfxLib/bgfx/examples/01-cubes/cubes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object bgfxLib/CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.o"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.o -c /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/01-cubes/cubes.cpp

bgfxLib/CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.i"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/01-cubes/cubes.cpp > CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.i

bgfxLib/CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.s"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/01-cubes/cubes.cpp -o CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.s

# Object files for target example-01-cubes
example__01__cubes_OBJECTS = \
"CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.o"

# External object files for target example-01-cubes
example__01__cubes_EXTERNAL_OBJECTS =

bgfxLib/example-01-cubes: bgfxLib/CMakeFiles/example-01-cubes.dir/bgfx/examples/01-cubes/cubes.cpp.o
bgfxLib/example-01-cubes: bgfxLib/CMakeFiles/example-01-cubes.dir/build.make
bgfxLib/example-01-cubes: bgfxLib/libexample-common.a
bgfxLib/example-01-cubes: bgfxLib/libbgfx.a
bgfxLib/example-01-cubes: bgfxLib/libbimg.a
bgfxLib/example-01-cubes: bgfxLib/libastc.a
bgfxLib/example-01-cubes: bgfxLib/libedtaa3.a
bgfxLib/example-01-cubes: bgfxLib/libetc1.a
bgfxLib/example-01-cubes: bgfxLib/libetc2.a
bgfxLib/example-01-cubes: bgfxLib/libiqa.a
bgfxLib/example-01-cubes: bgfxLib/libsquish.a
bgfxLib/example-01-cubes: bgfxLib/libnvtt.a
bgfxLib/example-01-cubes: bgfxLib/libpvrtc.a
bgfxLib/example-01-cubes: bgfxLib/libib-compress.a
bgfxLib/example-01-cubes: bgfxLib/libdear-imgui.a
bgfxLib/example-01-cubes: bgfxLib/libbx.a
bgfxLib/example-01-cubes: bgfxLib/CMakeFiles/example-01-cubes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable example-01-cubes"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example-01-cubes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bgfxLib/CMakeFiles/example-01-cubes.dir/build: bgfxLib/example-01-cubes

.PHONY : bgfxLib/CMakeFiles/example-01-cubes.dir/build

bgfxLib/CMakeFiles/example-01-cubes.dir/clean:
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && $(CMAKE_COMMAND) -P CMakeFiles/example-01-cubes.dir/cmake_clean.cmake
.PHONY : bgfxLib/CMakeFiles/example-01-cubes.dir/clean

bgfxLib/CMakeFiles/example-01-cubes.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_cubes.bin
bgfxLib/CMakeFiles/example-01-cubes.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_cubes.bin
bgfxLib/CMakeFiles/example-01-cubes.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_cubes.bin
bgfxLib/CMakeFiles/example-01-cubes.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_cubes.bin
bgfxLib/CMakeFiles/example-01-cubes.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_cubes.bin
bgfxLib/CMakeFiles/example-01-cubes.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_cubes.bin
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib/CMakeFiles/example-01-cubes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bgfxLib/CMakeFiles/example-01-cubes.dir/depend

