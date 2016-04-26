#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "solveur.h"
#include "piece.h"
#include "game.h"

struct tree_solve_s{ 			//struct for our tree of game 
	game base;
	tree_solve *children;
	int indice_children;
};

struct game_s {
	int nb_pieces;
	int nb_moves;
	int height;
	int width;
	piece *pieces;
};

game get_base(tree_solve t){ 		//get the base of the tree
	return t->base;
}

tree_solve create_tree(game g){		//create a new tree
	tree_solve t = malloc(sizeof (struct tree_solve_s));
	t->base = g;
	t->children = malloc(4*game_nb_pieces(g)*sizeof (struct game_s));
	t->indice_children = -1;
	return t;
}

bool has_child(tree_solve t){			//True if the tree have child 		
	return (t->indice_children > -1);
}

int get_nb_child(tree_solve t){			//return the number of child
	return t->indice_children+1;
}

tree_solve get_child(tree_solve t, int i){
	return t->children[i];
}

void add_child(tree_solve t, game g){		//Add a child in the tree
	tree_solve tmp = create_tree(g);
	t->indice_children += 1;
	t->children[t->indice_children] = tmp;
}

game solve_game(tree_solve t, int indice){
	game g = new_game_hr(0,NULL);
	game gL = new_game_hr(0,NULL);
	game gR = new_game_hr(0,NULL);
	game gU = new_game_hr(0,NULL);
	game gD = new_game_hr(0,NULL);
	copy_game(get_base(t), g);
	for (int p = 0; p < game_nb_pieces(g); ++p){ 			// Make every move if they are possible for each pieces and return a child for each mouvement done
		copy_game(g, gL);
		copy_game(g, gR);
		copy_game(g, gU);
		copy_game(g, gD);

		if (play_move(gL, p, LEFT, 1, g->width,g->height)){
			add_child(t, gL);
			if (game_over_hr(gL)){
				return gL;
			}			
		}
		if (play_move(gR, p, RIGHT, 1, g->width,g->height)){
			add_child(t, gR);
			if (game_over_hr(gR)){
				return gR;
			}		
		}				
		if (play_move(gU, p, UP, 1, g->width,g->height)){
			add_child(t, gU);
			if (game_over_hr(gU)){
				return gU;
			}	
		}
		if (play_move(gD, p, DOWN, 1, g->width,g->height)){
			add_child(t, gD);
			if (game_over_hr(gD)){
				return gD;
			}	
		}		
	}
	if(has_child(t)){
		indice++;
		for (int i = 0; i < get_nb_child(t);++i){
			solve_game(t->children[i], indice);
		}
   	}
}

int solve(game g){
	tree_solve t;
	t = create_tree(g);
	game solved = NULL;
	solved = solve_game(t, -1);

	if (solved == NULL){
		return -1;
	}
	return game_nb_moves(solved);
}
