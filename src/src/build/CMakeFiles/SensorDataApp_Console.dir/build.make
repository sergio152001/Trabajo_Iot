# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sergio/Trabajo_Iot/src/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sergio/Trabajo_Iot/src/src/build

# Include any dependencies generated for this target.
include CMakeFiles/SensorDataApp_Console.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SensorDataApp_Console.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SensorDataApp_Console.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SensorDataApp_Console.dir/flags.make

CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.o: CMakeFiles/SensorDataApp_Console.dir/flags.make
CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.o: ../main_consulta.cpp
CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.o: CMakeFiles/SensorDataApp_Console.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergio/Trabajo_Iot/src/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.o -MF CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.o.d -o CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.o -c /home/sergio/Trabajo_Iot/src/src/main_consulta.cpp

CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergio/Trabajo_Iot/src/src/main_consulta.cpp > CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.i

CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergio/Trabajo_Iot/src/src/main_consulta.cpp -o CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.s

CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.o: CMakeFiles/SensorDataApp_Console.dir/flags.make
CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.o: ../base_datos.cpp
CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.o: CMakeFiles/SensorDataApp_Console.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergio/Trabajo_Iot/src/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.o -MF CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.o.d -o CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.o -c /home/sergio/Trabajo_Iot/src/src/base_datos.cpp

CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergio/Trabajo_Iot/src/src/base_datos.cpp > CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.i

CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergio/Trabajo_Iot/src/src/base_datos.cpp -o CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.s

CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.o: CMakeFiles/SensorDataApp_Console.dir/flags.make
CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.o: ../sensores.cpp
CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.o: CMakeFiles/SensorDataApp_Console.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergio/Trabajo_Iot/src/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.o -MF CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.o.d -o CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.o -c /home/sergio/Trabajo_Iot/src/src/sensores.cpp

CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergio/Trabajo_Iot/src/src/sensores.cpp > CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.i

CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergio/Trabajo_Iot/src/src/sensores.cpp -o CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.s

# Object files for target SensorDataApp_Console
SensorDataApp_Console_OBJECTS = \
"CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.o" \
"CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.o" \
"CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.o"

# External object files for target SensorDataApp_Console
SensorDataApp_Console_EXTERNAL_OBJECTS =

SensorDataApp_Console: CMakeFiles/SensorDataApp_Console.dir/main_consulta.cpp.o
SensorDataApp_Console: CMakeFiles/SensorDataApp_Console.dir/base_datos.cpp.o
SensorDataApp_Console: CMakeFiles/SensorDataApp_Console.dir/sensores.cpp.o
SensorDataApp_Console: CMakeFiles/SensorDataApp_Console.dir/build.make
SensorDataApp_Console: /usr/lib/x86_64-linux-gnu/libsqlite3.so
SensorDataApp_Console: CMakeFiles/SensorDataApp_Console.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergio/Trabajo_Iot/src/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable SensorDataApp_Console"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SensorDataApp_Console.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SensorDataApp_Console.dir/build: SensorDataApp_Console
.PHONY : CMakeFiles/SensorDataApp_Console.dir/build

CMakeFiles/SensorDataApp_Console.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SensorDataApp_Console.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SensorDataApp_Console.dir/clean

CMakeFiles/SensorDataApp_Console.dir/depend:
	cd /home/sergio/Trabajo_Iot/src/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergio/Trabajo_Iot/src/src /home/sergio/Trabajo_Iot/src/src /home/sergio/Trabajo_Iot/src/src/build /home/sergio/Trabajo_Iot/src/src/build /home/sergio/Trabajo_Iot/src/src/build/CMakeFiles/SensorDataApp_Console.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SensorDataApp_Console.dir/depend

