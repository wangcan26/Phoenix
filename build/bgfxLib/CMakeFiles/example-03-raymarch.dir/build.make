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
include bgfxLib/CMakeFiles/example-03-raymarch.dir/depend.make

# Include the progress variables for this target.
include bgfxLib/CMakeFiles/example-03-raymarch.dir/progress.make

# Include the compile flags for this target's objects.
include bgfxLib/CMakeFiles/example-03-raymarch.dir/flags.make

../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_raymarching.bin: ../bgfxLib/bgfx/examples/03-raymarch/fs_raymarching.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Compiling shader 03-raymarch/fs_raymarching.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/03-raymarch/fs_raymarching.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/fs_raymarching.bin --platform osx --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/03-raymarch/fs_raymarching.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/fs_raymarching.bin --platform android --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/03-raymarch/fs_raymarching.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_raymarching.bin --platform linux --type fragment --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_raymarching.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_raymarching.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_raymarching.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_raymarching.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_raymarching.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_raymarching.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_raymarching.bin: ../bgfxLib/bgfx/examples/03-raymarch/vs_raymarching.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Compiling shader 03-raymarch/vs_raymarching.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/03-raymarch/vs_raymarching.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/vs_raymarching.bin --platform osx --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/03-raymarch/vs_raymarching.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/vs_raymarching.bin --platform android --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/03-raymarch/vs_raymarching.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_raymarching.bin --platform linux --type vertex --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_raymarching.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_raymarching.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_raymarching.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_raymarching.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_raymarching.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_raymarching.bin

bgfxLib/CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.o: bgfxLib/CMakeFiles/example-03-raymarch.dir/flags.make
bgfxLib/CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.o: ../bgfxLib/bgfx/examples/03-raymarch/raymarch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object bgfxLib/CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.o"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.o -c /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/03-raymarch/raymarch.cpp

bgfxLib/CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.i"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/03-raymarch/raymarch.cpp > CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.i

bgfxLib/CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.s"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/03-raymarch/raymarch.cpp -o CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.s

# Object files for target example-03-raymarch
example__03__raymarch_OBJECTS = \
"CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.o"

# External object files for target example-03-raymarch
example__03__raymarch_EXTERNAL_OBJECTS =

bgfxLib/example-03-raymarch: bgfxLib/CMakeFiles/example-03-raymarch.dir/bgfx/examples/03-raymarch/raymarch.cpp.o
bgfxLib/example-03-raymarch: bgfxLib/CMakeFiles/example-03-raymarch.dir/build.make
bgfxLib/example-03-raymarch: bgfxLib/libexample-common.a
bgfxLib/example-03-raymarch: bgfxLib/libbgfx.a
bgfxLib/example-03-raymarch: bgfxLib/libbimg.a
bgfxLib/example-03-raymarch: bgfxLib/libastc.a
bgfxLib/example-03-raymarch: bgfxLib/libedtaa3.a
bgfxLib/example-03-raymarch: bgfxLib/libetc1.a
bgfxLib/example-03-raymarch: bgfxLib/libetc2.a
bgfxLib/example-03-raymarch: bgfxLib/libiqa.a
bgfxLib/example-03-raymarch: bgfxLib/libsquish.a
bgfxLib/example-03-raymarch: bgfxLib/libnvtt.a
bgfxLib/example-03-raymarch: bgfxLib/libpvrtc.a
bgfxLib/example-03-raymarch: bgfxLib/libib-compress.a
bgfxLib/example-03-raymarch: bgfxLib/libdear-imgui.a
bgfxLib/example-03-raymarch: bgfxLib/libbx.a
bgfxLib/example-03-raymarch: bgfxLib/CMakeFiles/example-03-raymarch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable example-03-raymarch"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example-03-raymarch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bgfxLib/CMakeFiles/example-03-raymarch.dir/build: bgfxLib/example-03-raymarch

.PHONY : bgfxLib/CMakeFiles/example-03-raymarch.dir/build

bgfxLib/CMakeFiles/example-03-raymarch.dir/clean:
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && $(CMAKE_COMMAND) -P CMakeFiles/example-03-raymarch.dir/cmake_clean.cmake
.PHONY : bgfxLib/CMakeFiles/example-03-raymarch.dir/clean

bgfxLib/CMakeFiles/example-03-raymarch.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_raymarching.bin
bgfxLib/CMakeFiles/example-03-raymarch.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_raymarching.bin
bgfxLib/CMakeFiles/example-03-raymarch.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_raymarching.bin
bgfxLib/CMakeFiles/example-03-raymarch.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_raymarching.bin
bgfxLib/CMakeFiles/example-03-raymarch.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_raymarching.bin
bgfxLib/CMakeFiles/example-03-raymarch.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_raymarching.bin
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib/CMakeFiles/example-03-raymarch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bgfxLib/CMakeFiles/example-03-raymarch.dir/depend

