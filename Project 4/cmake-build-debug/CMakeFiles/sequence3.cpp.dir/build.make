# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\danis\CLionProjects\Project 4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\danis\CLionProjects\Project 4\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/sequence3.cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sequence3.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sequence3.cpp.dir/flags.make

CMakeFiles/sequence3.cpp.dir/sequence3_exam.cpp.obj: CMakeFiles/sequence3.cpp.dir/flags.make
CMakeFiles/sequence3.cpp.dir/sequence3_exam.cpp.obj: ../sequence3_exam.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\danis\CLionProjects\Project 4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sequence3.cpp.dir/sequence3_exam.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sequence3.cpp.dir\sequence3_exam.cpp.obj -c "C:\Users\danis\CLionProjects\Project 4\sequence3_exam.cpp"

CMakeFiles/sequence3.cpp.dir/sequence3_exam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sequence3.cpp.dir/sequence3_exam.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\danis\CLionProjects\Project 4\sequence3_exam.cpp" > CMakeFiles\sequence3.cpp.dir\sequence3_exam.cpp.i

CMakeFiles/sequence3.cpp.dir/sequence3_exam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sequence3.cpp.dir/sequence3_exam.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\danis\CLionProjects\Project 4\sequence3_exam.cpp" -o CMakeFiles\sequence3.cpp.dir\sequence3_exam.cpp.s

# Object files for target sequence3.cpp
sequence3_cpp_OBJECTS = \
"CMakeFiles/sequence3.cpp.dir/sequence3_exam.cpp.obj"

# External object files for target sequence3.cpp
sequence3_cpp_EXTERNAL_OBJECTS =

sequence3.cpp.exe: CMakeFiles/sequence3.cpp.dir/sequence3_exam.cpp.obj
sequence3.cpp.exe: CMakeFiles/sequence3.cpp.dir/build.make
sequence3.cpp.exe: CMakeFiles/sequence3.cpp.dir/linklibs.rsp
sequence3.cpp.exe: CMakeFiles/sequence3.cpp.dir/objects1.rsp
sequence3.cpp.exe: CMakeFiles/sequence3.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\danis\CLionProjects\Project 4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sequence3.cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sequence3.cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sequence3.cpp.dir/build: sequence3.cpp.exe

.PHONY : CMakeFiles/sequence3.cpp.dir/build

CMakeFiles/sequence3.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sequence3.cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sequence3.cpp.dir/clean

CMakeFiles/sequence3.cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\danis\CLionProjects\Project 4" "C:\Users\danis\CLionProjects\Project 4" "C:\Users\danis\CLionProjects\Project 4\cmake-build-debug" "C:\Users\danis\CLionProjects\Project 4\cmake-build-debug" "C:\Users\danis\CLionProjects\Project 4\cmake-build-debug\CMakeFiles\sequence3.cpp.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/sequence3.cpp.dir/depend
