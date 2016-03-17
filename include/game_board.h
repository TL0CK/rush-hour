#ifndef _GAME_BOAARD_H_
#define _GAME_BOARD_H_

#include <stdbool.h>
#include "piece.h"
#include "game.h"


game_board new_game_board(int* piece);

void delete_game(game_board game);

void set_pieces(game_board game , int* piece);

void add_piece(game_board grid, cpiece p, int piece_num);

void delete_pieces(game_board game, cpiece p, int piece_num);

void display_game(game_board grid);

void move(game_board game, int piece_num, dir d, int distance);

#endif


// FAIRE VALGRIND EXEC
