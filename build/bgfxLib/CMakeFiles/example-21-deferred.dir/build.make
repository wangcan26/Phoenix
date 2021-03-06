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
include bgfxLib/CMakeFiles/example-21-deferred.dir/depend.make

# Include the progress variables for this target.
include bgfxLib/CMakeFiles/example-21-deferred.dir/progress.make

# Include the compile flags for this target's objects.
include bgfxLib/CMakeFiles/example-21-deferred.dir/flags.make

../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_combine.bin: ../bgfxLib/bgfx/examples/21-deferred/fs_deferred_combine.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Compiling shader 21-deferred/fs_deferred_combine.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_combine.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_combine.bin --platform osx --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_combine.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_combine.bin --platform android --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_combine.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_combine.bin --platform linux --type fragment --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_combine.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_combine.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_combine.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_combine.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_combine.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_combine.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_debug.bin: ../bgfxLib/bgfx/examples/21-deferred/fs_deferred_debug.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Compiling shader 21-deferred/fs_deferred_debug.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_debug.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_debug.bin --platform osx --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_debug.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_debug.bin --platform android --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_debug.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_debug.bin --platform linux --type fragment --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_debug.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_debug.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_debug.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_debug.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_debug.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_debug.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_debug_line.bin: ../bgfxLib/bgfx/examples/21-deferred/fs_deferred_debug_line.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Compiling shader 21-deferred/fs_deferred_debug_line.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_debug_line.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_debug_line.bin --platform osx --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_debug_line.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_debug_line.bin --platform android --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_debug_line.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_debug_line.bin --platform linux --type fragment --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_debug_line.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_debug_line.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_debug_line.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_debug_line.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_debug_line.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_debug_line.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_geom.bin: ../bgfxLib/bgfx/examples/21-deferred/fs_deferred_geom.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Compiling shader 21-deferred/fs_deferred_geom.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_geom.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_geom.bin --platform osx --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_geom.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_geom.bin --platform android --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_geom.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_geom.bin --platform linux --type fragment --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_geom.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_geom.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_geom.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_geom.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_geom.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_geom.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_light.bin: ../bgfxLib/bgfx/examples/21-deferred/fs_deferred_light.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Compiling shader 21-deferred/fs_deferred_light.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_light.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_light.bin --platform osx --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_light.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_light.bin --platform android --type fragment
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/fs_deferred_light.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_light.bin --platform linux --type fragment --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_light.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_light.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_light.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_light.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_light.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_light.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_combine.bin: ../bgfxLib/bgfx/examples/21-deferred/vs_deferred_combine.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Compiling shader 21-deferred/vs_deferred_combine.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_combine.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_combine.bin --platform osx --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_combine.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_combine.bin --platform android --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_combine.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_combine.bin --platform linux --type vertex --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_combine.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_combine.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_combine.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_combine.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_combine.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_combine.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_debug.bin: ../bgfxLib/bgfx/examples/21-deferred/vs_deferred_debug.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Compiling shader 21-deferred/vs_deferred_debug.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_debug.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_debug.bin --platform osx --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_debug.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_debug.bin --platform android --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_debug.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_debug.bin --platform linux --type vertex --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_debug.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_debug.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_debug.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_debug.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_debug.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_debug.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_debug_line.bin: ../bgfxLib/bgfx/examples/21-deferred/vs_deferred_debug_line.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Compiling shader 21-deferred/vs_deferred_debug_line.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_debug_line.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_debug_line.bin --platform osx --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_debug_line.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_debug_line.bin --platform android --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_debug_line.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_debug_line.bin --platform linux --type vertex --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_debug_line.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_debug_line.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_debug_line.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_debug_line.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_debug_line.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_debug_line.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_geom.bin: ../bgfxLib/bgfx/examples/21-deferred/vs_deferred_geom.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Compiling shader 21-deferred/vs_deferred_geom.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_geom.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_geom.bin --platform osx --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_geom.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_geom.bin --platform android --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_geom.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_geom.bin --platform linux --type vertex --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_geom.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_geom.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_geom.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_geom.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_geom.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_geom.bin

../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_light.bin: ../bgfxLib/bgfx/examples/21-deferred/vs_deferred_light.sc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Compiling shader 21-deferred/vs_deferred_light.sc for Metal, GLES, GLSL"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_light.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_light.bin --platform osx --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_light.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_light.bin --platform android --type vertex
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && ./shaderc -f /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/vs_deferred_light.sc -i /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/src -o /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_light.bin --platform linux --type vertex --profile 120

../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_light.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_light.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_light.bin

../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_light.bin: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_light.bin
	@$(CMAKE_COMMAND) -E touch_nocreate ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_light.bin

bgfxLib/CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.o: bgfxLib/CMakeFiles/example-21-deferred.dir/flags.make
bgfxLib/CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.o: ../bgfxLib/bgfx/examples/21-deferred/deferred.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object bgfxLib/CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.o"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.o -c /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/deferred.cpp

bgfxLib/CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.i"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/deferred.cpp > CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.i

bgfxLib/CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.s"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib/bgfx/examples/21-deferred/deferred.cpp -o CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.s

# Object files for target example-21-deferred
example__21__deferred_OBJECTS = \
"CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.o"

# External object files for target example-21-deferred
example__21__deferred_EXTERNAL_OBJECTS =

bgfxLib/example-21-deferred: bgfxLib/CMakeFiles/example-21-deferred.dir/bgfx/examples/21-deferred/deferred.cpp.o
bgfxLib/example-21-deferred: bgfxLib/CMakeFiles/example-21-deferred.dir/build.make
bgfxLib/example-21-deferred: bgfxLib/libexample-common.a
bgfxLib/example-21-deferred: bgfxLib/libbgfx.a
bgfxLib/example-21-deferred: bgfxLib/libbimg.a
bgfxLib/example-21-deferred: bgfxLib/libastc.a
bgfxLib/example-21-deferred: bgfxLib/libedtaa3.a
bgfxLib/example-21-deferred: bgfxLib/libetc1.a
bgfxLib/example-21-deferred: bgfxLib/libetc2.a
bgfxLib/example-21-deferred: bgfxLib/libiqa.a
bgfxLib/example-21-deferred: bgfxLib/libsquish.a
bgfxLib/example-21-deferred: bgfxLib/libnvtt.a
bgfxLib/example-21-deferred: bgfxLib/libpvrtc.a
bgfxLib/example-21-deferred: bgfxLib/libib-compress.a
bgfxLib/example-21-deferred: bgfxLib/libdear-imgui.a
bgfxLib/example-21-deferred: bgfxLib/libbx.a
bgfxLib/example-21-deferred: bgfxLib/CMakeFiles/example-21-deferred.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable example-21-deferred"
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example-21-deferred.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bgfxLib/CMakeFiles/example-21-deferred.dir/build: bgfxLib/example-21-deferred

.PHONY : bgfxLib/CMakeFiles/example-21-deferred.dir/build

bgfxLib/CMakeFiles/example-21-deferred.dir/clean:
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib && $(CMAKE_COMMAND) -P CMakeFiles/example-21-deferred.dir/cmake_clean.cmake
.PHONY : bgfxLib/CMakeFiles/example-21-deferred.dir/clean

bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_combine.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_combine.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_combine.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_debug.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_debug.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_debug.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_debug_line.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_debug_line.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_debug_line.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_geom.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_geom.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_geom.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/fs_deferred_light.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/fs_deferred_light.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/fs_deferred_light.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_combine.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_combine.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_combine.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_debug.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_debug.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_debug.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_debug_line.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_debug_line.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_debug_line.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_geom.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_geom.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_geom.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/metal/vs_deferred_light.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/gles/vs_deferred_light.bin
bgfxLib/CMakeFiles/example-21-deferred.dir/depend: ../bgfxLib/bgfx/examples/runtime/shaders/glsl/vs_deferred_light.bin
	cd /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/bgfxLib /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib /Users/wangcan/WorkSpace/BgfxProj/ProjectPhoenix/build/bgfxLib/CMakeFiles/example-21-deferred.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bgfxLib/CMakeFiles/example-21-deferred.dir/depend

