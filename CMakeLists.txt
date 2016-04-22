cmake_minimum_required (VERSION 3.3)

project (rush_hour)


add_definitions (-std=c99 -Wall -g)

include_directories (
	include/
)

add_library (game src/game.c src/piece.c src/solveurV3.c)
install (TARGETS game ARCHIVE DESTINATION build)

add_executable (test_piece test/test_piece1.c)
target_link_libraries (test_piece game)
install (TARGETS test_piece RUNTIME DESTINATION ..)

add_executable (main_jeu src/main_jeu.c src/game.c src/piece.c src/solveurV3.c)
install (TARGETS main_jeu RUNTIME DESTINATION ..)

