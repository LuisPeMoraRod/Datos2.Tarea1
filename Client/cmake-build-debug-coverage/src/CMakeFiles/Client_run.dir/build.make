# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage"

# Include any dependencies generated for this target.
include src/CMakeFiles/Client_run.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Client_run.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Client_run.dir/flags.make

src/CMakeFiles/Client_run.dir/main.cpp.o: src/CMakeFiles/Client_run.dir/flags.make
src/CMakeFiles/Client_run.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Client_run.dir/main.cpp.o"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client_run.dir/main.cpp.o -c "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/src/main.cpp"

src/CMakeFiles/Client_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client_run.dir/main.cpp.i"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/src/main.cpp" > CMakeFiles/Client_run.dir/main.cpp.i

src/CMakeFiles/Client_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client_run.dir/main.cpp.s"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/src/main.cpp" -o CMakeFiles/Client_run.dir/main.cpp.s

src/CMakeFiles/Client_run.dir/socketclient.cpp.o: src/CMakeFiles/Client_run.dir/flags.make
src/CMakeFiles/Client_run.dir/socketclient.cpp.o: ../src/socketclient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/Client_run.dir/socketclient.cpp.o"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client_run.dir/socketclient.cpp.o -c "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/src/socketclient.cpp"

src/CMakeFiles/Client_run.dir/socketclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client_run.dir/socketclient.cpp.i"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/src/socketclient.cpp" > CMakeFiles/Client_run.dir/socketclient.cpp.i

src/CMakeFiles/Client_run.dir/socketclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client_run.dir/socketclient.cpp.s"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/src/socketclient.cpp" -o CMakeFiles/Client_run.dir/socketclient.cpp.s

src/CMakeFiles/Client_run.dir/window.cpp.o: src/CMakeFiles/Client_run.dir/flags.make
src/CMakeFiles/Client_run.dir/window.cpp.o: ../src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/Client_run.dir/window.cpp.o"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client_run.dir/window.cpp.o -c "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/src/window.cpp"

src/CMakeFiles/Client_run.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client_run.dir/window.cpp.i"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/src/window.cpp" > CMakeFiles/Client_run.dir/window.cpp.i

src/CMakeFiles/Client_run.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client_run.dir/window.cpp.s"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/src/window.cpp" -o CMakeFiles/Client_run.dir/window.cpp.s

# Object files for target Client_run
Client_run_OBJECTS = \
"CMakeFiles/Client_run.dir/main.cpp.o" \
"CMakeFiles/Client_run.dir/socketclient.cpp.o" \
"CMakeFiles/Client_run.dir/window.cpp.o"

# External object files for target Client_run
Client_run_EXTERNAL_OBJECTS =

src/Client_run: src/CMakeFiles/Client_run.dir/main.cpp.o
src/Client_run: src/CMakeFiles/Client_run.dir/socketclient.cpp.o
src/Client_run: src/CMakeFiles/Client_run.dir/window.cpp.o
src/Client_run: src/CMakeFiles/Client_run.dir/build.make
src/Client_run: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
src/Client_run: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
src/Client_run: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
src/Client_run: src/CMakeFiles/Client_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Client_run"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Client_run.dir/build: src/Client_run

.PHONY : src/CMakeFiles/Client_run.dir/build

src/CMakeFiles/Client_run.dir/clean:
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" && $(CMAKE_COMMAND) -P CMakeFiles/Client_run.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Client_run.dir/clean

src/CMakeFiles/Client_run.dir/depend:
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client" "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/src" "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage" "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src" "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/src/CMakeFiles/Client_run.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/Client_run.dir/depend

