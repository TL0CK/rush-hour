add_library (game game.c piece.c)

install (TARGETS game ARCHIVE DESTINATION lib)
