add_executable (jeu main.c)

target_link_libraries (jeu game)

install (TARGETS jeu RUNTIME DESTINATION bin)
