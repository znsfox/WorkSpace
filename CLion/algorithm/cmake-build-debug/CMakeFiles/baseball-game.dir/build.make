# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\fox\Desktop\WorkSpace\CLion\algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\fox\Desktop\WorkSpace\CLion\algorithm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/baseball-game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/baseball-game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/baseball-game.dir/flags.make

CMakeFiles/baseball-game.dir/baseball-game.c.obj: CMakeFiles/baseball-game.dir/flags.make
CMakeFiles/baseball-game.dir/baseball-game.c.obj: ../baseball-game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\fox\Desktop\WorkSpace\CLion\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/baseball-game.dir/baseball-game.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\baseball-game.dir\baseball-game.c.obj   -c C:\Users\fox\Desktop\WorkSpace\CLion\algorithm\baseball-game.c

CMakeFiles/baseball-game.dir/baseball-game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/baseball-game.dir/baseball-game.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\fox\Desktop\WorkSpace\CLion\algorithm\baseball-game.c > CMakeFiles\baseball-game.dir\baseball-game.c.i

CMakeFiles/baseball-game.dir/baseball-game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/baseball-game.dir/baseball-game.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\fox\Desktop\WorkSpace\CLion\algorithm\baseball-game.c -o CMakeFiles\baseball-game.dir\baseball-game.c.s

# Object files for target baseball-game
baseball__game_OBJECTS = \
"CMakeFiles/baseball-game.dir/baseball-game.c.obj"

# External object files for target baseball-game
baseball__game_EXTERNAL_OBJECTS =

baseball-game.exe: CMakeFiles/baseball-game.dir/baseball-game.c.obj
baseball-game.exe: CMakeFiles/baseball-game.dir/build.make
baseball-game.exe: CMakeFiles/baseball-game.dir/linklibs.rsp
baseball-game.exe: CMakeFiles/baseball-game.dir/objects1.rsp
baseball-game.exe: CMakeFiles/baseball-game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\fox\Desktop\WorkSpace\CLion\algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable baseball-game.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\baseball-game.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/baseball-game.dir/build: baseball-game.exe

.PHONY : CMakeFiles/baseball-game.dir/build

CMakeFiles/baseball-game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\baseball-game.dir\cmake_clean.cmake
.PHONY : CMakeFiles/baseball-game.dir/clean

CMakeFiles/baseball-game.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\fox\Desktop\WorkSpace\CLion\algorithm C:\Users\fox\Desktop\WorkSpace\CLion\algorithm C:\Users\fox\Desktop\WorkSpace\CLion\algorithm\cmake-build-debug C:\Users\fox\Desktop\WorkSpace\CLion\algorithm\cmake-build-debug C:\Users\fox\Desktop\WorkSpace\CLion\algorithm\cmake-build-debug\CMakeFiles\baseball-game.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/baseball-game.dir/depend

