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
include tst/CMakeFiles/Client_tst.dir/depend.make

# Include the progress variables for this target.
include tst/CMakeFiles/Client_tst.dir/progress.make

# Include the compile flags for this target's objects.
include tst/CMakeFiles/Client_tst.dir/flags.make

tst/CMakeFiles/Client_tst.dir/SocketClientTest.o: tst/CMakeFiles/Client_tst.dir/flags.make
tst/CMakeFiles/Client_tst.dir/SocketClientTest.o: ../tst/SocketClientTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tst/CMakeFiles/Client_tst.dir/SocketClientTest.o"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/tst" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client_tst.dir/SocketClientTest.o -c "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/tst/SocketClientTest.cpp"

tst/CMakeFiles/Client_tst.dir/SocketClientTest.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client_tst.dir/SocketClientTest.i"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/tst" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/tst/SocketClientTest.cpp" > CMakeFiles/Client_tst.dir/SocketClientTest.i

tst/CMakeFiles/Client_tst.dir/SocketClientTest.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client_tst.dir/SocketClientTest.s"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/tst" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/tst/SocketClientTest.cpp" -o CMakeFiles/Client_tst.dir/SocketClientTest.s

tst/CMakeFiles/Client_tst.dir/main.o: tst/CMakeFiles/Client_tst.dir/flags.make
tst/CMakeFiles/Client_tst.dir/main.o: ../tst/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tst/CMakeFiles/Client_tst.dir/main.o"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/tst" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client_tst.dir/main.o -c "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/tst/main.cpp"

tst/CMakeFiles/Client_tst.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client_tst.dir/main.i"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/tst" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/tst/main.cpp" > CMakeFiles/Client_tst.dir/main.i

tst/CMakeFiles/Client_tst.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client_tst.dir/main.s"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/tst" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/tst/main.cpp" -o CMakeFiles/Client_tst.dir/main.s

# Object files for target Client_tst
Client_tst_OBJECTS = \
"CMakeFiles/Client_tst.dir/SocketClientTest.o" \
"CMakeFiles/Client_tst.dir/main.o"

# External object files for target Client_tst
Client_tst_EXTERNAL_OBJECTS =

tst/Client_tst: tst/CMakeFiles/Client_tst.dir/SocketClientTest.o
tst/Client_tst: tst/CMakeFiles/Client_tst.dir/main.o
tst/Client_tst: tst/CMakeFiles/Client_tst.dir/build.make
tst/Client_tst: src/libClient_lib.a
tst/Client_tst: lib/libgtestd.a
tst/Client_tst: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
tst/Client_tst: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
tst/Client_tst: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
tst/Client_tst: tst/CMakeFiles/Client_tst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Client_tst"
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/tst" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client_tst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tst/CMakeFiles/Client_tst.dir/build: tst/Client_tst

.PHONY : tst/CMakeFiles/Client_tst.dir/build

tst/CMakeFiles/Client_tst.dir/clean:
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/tst" && $(CMAKE_COMMAND) -P CMakeFiles/Client_tst.dir/cmake_clean.cmake
.PHONY : tst/CMakeFiles/Client_tst.dir/clean

tst/CMakeFiles/Client_tst.dir/depend:
	cd "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client" "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/tst" "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage" "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/tst" "/home/luispedro/Documents/TEC/Semestre III/Algoritmos y Estructuras de Datos 2/Tarea 1/Client/cmake-build-debug-coverage/tst/CMakeFiles/Client_tst.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tst/CMakeFiles/Client_tst.dir/depend
