add_executable (test_piece test_piece1.c)

target_link_libraries (test_piece game)

install (TARGETS test_piece RUNTIME DESTINATION bin)
