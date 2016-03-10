cmake_minimum_required (VERSION 3.3)

project (rush_hour)

add_definitions (-std=c99 -g)

set (CMAKE_INSTALL_PREFIX .)

include_directories (
	include/
)
#j'aime bien les commentaires


add_subdirectory (src)
add_subdirectory (test)
