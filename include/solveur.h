#ifndef _SOLVEUR_H_
#define _SOLVEUR_H_

#include <stdbool.h>
#include "piece.h"
#include "game.h"

typedef struct tree_solve_s* tree_solve;

typedef struct game_s* game;

game get_base(tree_solve t);

tree_solve create_tree(game g);

bool has_child(tree_solve t);

int get_nb_children(tree_solve t);

tree_solve get_child(tree_solve t, int i);

void add_child(tree_solve t, game g);

game solve_game(tree_solve t, int indice);

void usage(char *name);

int solve(game g);

#endif
