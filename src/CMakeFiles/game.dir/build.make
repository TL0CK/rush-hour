# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /net/cremi/vviguier/projet_rush_hour/rush-hour

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /net/cremi/vviguier/projet_rush_hour/rush-hour

# Include any dependencies generated for this target.
include src/CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/game.dir/flags.make

src/CMakeFiles/game.dir/game.c.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/game.c.o: src/game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/net/cremi/vviguier/projet_rush_hour/rush-hour/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/game.dir/game.c.o"
	cd /net/cremi/vviguier/projet_rush_hour/rush-hour/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/game.c.o   -c /net/cremi/vviguier/projet_rush_hour/rush-hour/src/game.c

src/CMakeFiles/game.dir/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/game.c.i"
	cd /net/cremi/vviguier/projet_rush_hour/rush-hour/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /net/cremi/vviguier/projet_rush_hour/rush-hour/src/game.c > CMakeFiles/game.dir/game.c.i

src/CMakeFiles/game.dir/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/game.c.s"
	cd /net/cremi/vviguier/projet_rush_hour/rush-hour/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /net/cremi/vviguier/projet_rush_hour/rush-hour/src/game.c -o CMakeFiles/game.dir/game.c.s

src/CMakeFiles/game.dir/game.c.o.requires:

.PHONY : src/CMakeFiles/game.dir/game.c.o.requires

src/CMakeFiles/game.dir/game.c.o.provides: src/CMakeFiles/game.dir/game.c.o.requires
	$(MAKE) -f src/CMakeFiles/game.dir/build.make src/CMakeFiles/game.dir/game.c.o.provides.build
.PHONY : src/CMakeFiles/game.dir/game.c.o.provides

src/CMakeFiles/game.dir/game.c.o.provides.build: src/CMakeFiles/game.dir/game.c.o


src/CMakeFiles/game.dir/piece.c.o: src/CMakeFiles/game.dir/flags.make
src/CMakeFiles/game.dir/piece.c.o: src/piece.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/net/cremi/vviguier/projet_rush_hour/rush-hour/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/game.dir/piece.c.o"
	cd /net/cremi/vviguier/projet_rush_hour/rush-hour/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/piece.c.o   -c /net/cremi/vviguier/projet_rush_hour/rush-hour/src/piece.c

src/CMakeFiles/game.dir/piece.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/piece.c.i"
	cd /net/cremi/vviguier/projet_rush_hour/rush-hour/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /net/cremi/vviguier/projet_rush_hour/rush-hour/src/piece.c > CMakeFiles/game.dir/piece.c.i

src/CMakeFiles/game.dir/piece.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/piece.c.s"
	cd /net/cremi/vviguier/projet_rush_hour/rush-hour/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /net/cremi/vviguier/projet_rush_hour/rush-hour/src/piece.c -o CMakeFiles/game.dir/piece.c.s

src/CMakeFiles/game.dir/piece.c.o.requires:

.PHONY : src/CMakeFiles/game.dir/piece.c.o.requires

src/CMakeFiles/game.dir/piece.c.o.provides: src/CMakeFiles/game.dir/piece.c.o.requires
	$(MAKE) -f src/CMakeFiles/game.dir/build.make src/CMakeFiles/game.dir/piece.c.o.provides.build
.PHONY : src/CMakeFiles/game.dir/piece.c.o.provides

src/CMakeFiles/game.dir/piece.c.o.provides.build: src/CMakeFiles/game.dir/piece.c.o


# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/game.c.o" \
"CMakeFiles/game.dir/piece.c.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

src/libgame.a: src/CMakeFiles/game.dir/game.c.o
src/libgame.a: src/CMakeFiles/game.dir/piece.c.o
src/libgame.a: src/CMakeFiles/game.dir/build.make
src/libgame.a: src/CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/net/cremi/vviguier/projet_rush_hour/rush-hour/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libgame.a"
	cd /net/cremi/vviguier/projet_rush_hour/rush-hour/src && $(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean_target.cmake
	cd /net/cremi/vviguier/projet_rush_hour/rush-hour/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/game.dir/build: src/libgame.a

.PHONY : src/CMakeFiles/game.dir/build

src/CMakeFiles/game.dir/requires: src/CMakeFiles/game.dir/game.c.o.requires
src/CMakeFiles/game.dir/requires: src/CMakeFiles/game.dir/piece.c.o.requires

.PHONY : src/CMakeFiles/game.dir/requires

src/CMakeFiles/game.dir/clean:
	cd /net/cremi/vviguier/projet_rush_hour/rush-hour/src && $(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/game.dir/clean

src/CMakeFiles/game.dir/depend:
	cd /net/cremi/vviguier/projet_rush_hour/rush-hour && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /net/cremi/vviguier/projet_rush_hour/rush-hour /net/cremi/vviguier/projet_rush_hour/rush-hour/src /net/cremi/vviguier/projet_rush_hour/rush-hour /net/cremi/vviguier/projet_rush_hour/rush-hour/src /net/cremi/vviguier/projet_rush_hour/rush-hour/src/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/game.dir/depend

