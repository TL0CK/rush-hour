# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_SOURCE_DIR = /home/valentin/Documents/rush-hour/rush-hour

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/valentin/Documents/rush-hour/rush-hour/build

# Include any dependencies generated for this target.
include CMakeFiles/main_game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main_game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_game.dir/flags.make

CMakeFiles/main_game.dir/src/main_game.c.o: CMakeFiles/main_game.dir/flags.make
CMakeFiles/main_game.dir/src/main_game.c.o: ../src/main_game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentin/Documents/rush-hour/rush-hour/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main_game.dir/src/main_game.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/main_game.dir/src/main_game.c.o   -c /home/valentin/Documents/rush-hour/rush-hour/src/main_game.c

CMakeFiles/main_game.dir/src/main_game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_game.dir/src/main_game.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/valentin/Documents/rush-hour/rush-hour/src/main_game.c > CMakeFiles/main_game.dir/src/main_game.c.i

CMakeFiles/main_game.dir/src/main_game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_game.dir/src/main_game.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/valentin/Documents/rush-hour/rush-hour/src/main_game.c -o CMakeFiles/main_game.dir/src/main_game.c.s

CMakeFiles/main_game.dir/src/main_game.c.o.requires:

.PHONY : CMakeFiles/main_game.dir/src/main_game.c.o.requires

CMakeFiles/main_game.dir/src/main_game.c.o.provides: CMakeFiles/main_game.dir/src/main_game.c.o.requires
	$(MAKE) -f CMakeFiles/main_game.dir/build.make CMakeFiles/main_game.dir/src/main_game.c.o.provides.build
.PHONY : CMakeFiles/main_game.dir/src/main_game.c.o.provides

CMakeFiles/main_game.dir/src/main_game.c.o.provides.build: CMakeFiles/main_game.dir/src/main_game.c.o


CMakeFiles/main_game.dir/src/game.c.o: CMakeFiles/main_game.dir/flags.make
CMakeFiles/main_game.dir/src/game.c.o: ../src/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentin/Documents/rush-hour/rush-hour/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main_game.dir/src/game.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/main_game.dir/src/game.c.o   -c /home/valentin/Documents/rush-hour/rush-hour/src/game.c

CMakeFiles/main_game.dir/src/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_game.dir/src/game.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/valentin/Documents/rush-hour/rush-hour/src/game.c > CMakeFiles/main_game.dir/src/game.c.i

CMakeFiles/main_game.dir/src/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_game.dir/src/game.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/valentin/Documents/rush-hour/rush-hour/src/game.c -o CMakeFiles/main_game.dir/src/game.c.s

CMakeFiles/main_game.dir/src/game.c.o.requires:

.PHONY : CMakeFiles/main_game.dir/src/game.c.o.requires

CMakeFiles/main_game.dir/src/game.c.o.provides: CMakeFiles/main_game.dir/src/game.c.o.requires
	$(MAKE) -f CMakeFiles/main_game.dir/build.make CMakeFiles/main_game.dir/src/game.c.o.provides.build
.PHONY : CMakeFiles/main_game.dir/src/game.c.o.provides

CMakeFiles/main_game.dir/src/game.c.o.provides.build: CMakeFiles/main_game.dir/src/game.c.o


CMakeFiles/main_game.dir/src/piece.c.o: CMakeFiles/main_game.dir/flags.make
CMakeFiles/main_game.dir/src/piece.c.o: ../src/piece.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentin/Documents/rush-hour/rush-hour/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main_game.dir/src/piece.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/main_game.dir/src/piece.c.o   -c /home/valentin/Documents/rush-hour/rush-hour/src/piece.c

CMakeFiles/main_game.dir/src/piece.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_game.dir/src/piece.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/valentin/Documents/rush-hour/rush-hour/src/piece.c > CMakeFiles/main_game.dir/src/piece.c.i

CMakeFiles/main_game.dir/src/piece.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_game.dir/src/piece.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/valentin/Documents/rush-hour/rush-hour/src/piece.c -o CMakeFiles/main_game.dir/src/piece.c.s

CMakeFiles/main_game.dir/src/piece.c.o.requires:

.PHONY : CMakeFiles/main_game.dir/src/piece.c.o.requires

CMakeFiles/main_game.dir/src/piece.c.o.provides: CMakeFiles/main_game.dir/src/piece.c.o.requires
	$(MAKE) -f CMakeFiles/main_game.dir/build.make CMakeFiles/main_game.dir/src/piece.c.o.provides.build
.PHONY : CMakeFiles/main_game.dir/src/piece.c.o.provides

CMakeFiles/main_game.dir/src/piece.c.o.provides.build: CMakeFiles/main_game.dir/src/piece.c.o


CMakeFiles/main_game.dir/src/solveurV3.c.o: CMakeFiles/main_game.dir/flags.make
CMakeFiles/main_game.dir/src/solveurV3.c.o: ../src/solveurV3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/valentin/Documents/rush-hour/rush-hour/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main_game.dir/src/solveurV3.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/main_game.dir/src/solveurV3.c.o   -c /home/valentin/Documents/rush-hour/rush-hour/src/solveurV3.c

CMakeFiles/main_game.dir/src/solveurV3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main_game.dir/src/solveurV3.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/valentin/Documents/rush-hour/rush-hour/src/solveurV3.c > CMakeFiles/main_game.dir/src/solveurV3.c.i

CMakeFiles/main_game.dir/src/solveurV3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main_game.dir/src/solveurV3.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/valentin/Documents/rush-hour/rush-hour/src/solveurV3.c -o CMakeFiles/main_game.dir/src/solveurV3.c.s

CMakeFiles/main_game.dir/src/solveurV3.c.o.requires:

.PHONY : CMakeFiles/main_game.dir/src/solveurV3.c.o.requires

CMakeFiles/main_game.dir/src/solveurV3.c.o.provides: CMakeFiles/main_game.dir/src/solveurV3.c.o.requires
	$(MAKE) -f CMakeFiles/main_game.dir/build.make CMakeFiles/main_game.dir/src/solveurV3.c.o.provides.build
.PHONY : CMakeFiles/main_game.dir/src/solveurV3.c.o.provides

CMakeFiles/main_game.dir/src/solveurV3.c.o.provides.build: CMakeFiles/main_game.dir/src/solveurV3.c.o


# Object files for target main_game
main_game_OBJECTS = \
"CMakeFiles/main_game.dir/src/main_game.c.o" \
"CMakeFiles/main_game.dir/src/game.c.o" \
"CMakeFiles/main_game.dir/src/piece.c.o" \
"CMakeFiles/main_game.dir/src/solveurV3.c.o"

# External object files for target main_game
main_game_EXTERNAL_OBJECTS =

main_game: CMakeFiles/main_game.dir/src/main_game.c.o
main_game: CMakeFiles/main_game.dir/src/game.c.o
main_game: CMakeFiles/main_game.dir/src/piece.c.o
main_game: CMakeFiles/main_game.dir/src/solveurV3.c.o
main_game: CMakeFiles/main_game.dir/build.make
main_game: CMakeFiles/main_game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/valentin/Documents/rush-hour/rush-hour/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable main_game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_game.dir/build: main_game

.PHONY : CMakeFiles/main_game.dir/build

CMakeFiles/main_game.dir/requires: CMakeFiles/main_game.dir/src/main_game.c.o.requires
CMakeFiles/main_game.dir/requires: CMakeFiles/main_game.dir/src/game.c.o.requires
CMakeFiles/main_game.dir/requires: CMakeFiles/main_game.dir/src/piece.c.o.requires
CMakeFiles/main_game.dir/requires: CMakeFiles/main_game.dir/src/solveurV3.c.o.requires

.PHONY : CMakeFiles/main_game.dir/requires

CMakeFiles/main_game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_game.dir/clean

CMakeFiles/main_game.dir/depend:
	cd /home/valentin/Documents/rush-hour/rush-hour/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/valentin/Documents/rush-hour/rush-hour /home/valentin/Documents/rush-hour/rush-hour /home/valentin/Documents/rush-hour/rush-hour/build /home/valentin/Documents/rush-hour/rush-hour/build /home/valentin/Documents/rush-hour/rush-hour/build/CMakeFiles/main_game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_game.dir/depend

