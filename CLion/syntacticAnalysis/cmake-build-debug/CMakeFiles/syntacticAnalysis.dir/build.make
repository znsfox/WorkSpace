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
CMAKE_SOURCE_DIR = C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/syntacticAnalysis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/syntacticAnalysis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/syntacticAnalysis.dir/flags.make

CMakeFiles/syntacticAnalysis.dir/main.c.obj: CMakeFiles/syntacticAnalysis.dir/flags.make
CMakeFiles/syntacticAnalysis.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/syntacticAnalysis.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\syntacticAnalysis.dir\main.c.obj   -c C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\main.c

CMakeFiles/syntacticAnalysis.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/syntacticAnalysis.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\main.c > CMakeFiles\syntacticAnalysis.dir\main.c.i

CMakeFiles/syntacticAnalysis.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/syntacticAnalysis.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\main.c -o CMakeFiles\syntacticAnalysis.dir\main.c.s

CMakeFiles/syntacticAnalysis.dir/test.c.obj: CMakeFiles/syntacticAnalysis.dir/flags.make
CMakeFiles/syntacticAnalysis.dir/test.c.obj: ../test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/syntacticAnalysis.dir/test.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\syntacticAnalysis.dir\test.c.obj   -c C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\test.c

CMakeFiles/syntacticAnalysis.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/syntacticAnalysis.dir/test.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\test.c > CMakeFiles\syntacticAnalysis.dir\test.c.i

CMakeFiles/syntacticAnalysis.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/syntacticAnalysis.dir/test.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\test.c -o CMakeFiles\syntacticAnalysis.dir\test.c.s

# Object files for target syntacticAnalysis
syntacticAnalysis_OBJECTS = \
"CMakeFiles/syntacticAnalysis.dir/main.c.obj" \
"CMakeFiles/syntacticAnalysis.dir/test.c.obj"

# External object files for target syntacticAnalysis
syntacticAnalysis_EXTERNAL_OBJECTS =

syntacticAnalysis.exe: CMakeFiles/syntacticAnalysis.dir/main.c.obj
syntacticAnalysis.exe: CMakeFiles/syntacticAnalysis.dir/test.c.obj
syntacticAnalysis.exe: CMakeFiles/syntacticAnalysis.dir/build.make
syntacticAnalysis.exe: CMakeFiles/syntacticAnalysis.dir/linklibs.rsp
syntacticAnalysis.exe: CMakeFiles/syntacticAnalysis.dir/objects1.rsp
syntacticAnalysis.exe: CMakeFiles/syntacticAnalysis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable syntacticAnalysis.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\syntacticAnalysis.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/syntacticAnalysis.dir/build: syntacticAnalysis.exe

.PHONY : CMakeFiles/syntacticAnalysis.dir/build

CMakeFiles/syntacticAnalysis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\syntacticAnalysis.dir\cmake_clean.cmake
.PHONY : CMakeFiles/syntacticAnalysis.dir/clean

CMakeFiles/syntacticAnalysis.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\cmake-build-debug C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\cmake-build-debug C:\Users\fox\Desktop\WorkSpace\CLion\syntacticAnalysis\cmake-build-debug\CMakeFiles\syntacticAnalysis.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/syntacticAnalysis.dir/depend
