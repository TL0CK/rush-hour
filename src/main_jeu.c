#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "game.h"
#include "piece.h"


#define TAILLE 6
#define NB_PIECES 5

piece pieces[NB_PIECES];

void set_up_rh() {
	pieces[0] = new_piece_rh(0, 2, true, true);
	pieces[1] = new_piece_rh(3, 3, true, true);
	pieces[2] = new_piece_rh(3, 0, true, false);
	pieces[3] = new_piece_rh(4, 1, true, true);
	pieces[4] = new_piece_rh(5, 3, false, false);
}

void set_up_rh2() {
	pieces[0] = new_piece_rh(0, 2, true, true);
	pieces[1] = new_piece_rh(2, 1, false, false);
	pieces[2] = new_piece_rh(1, 4, true, true);
	pieces[3] = new_piece_rh(3, 2, true, false);
	pieces[4] = new_piece_rh(3, 1, false, true);
}

void set_up_rh3() {
	pieces[0] = new_piece_rh(0, 2, true, true);
	pieces[1] = new_piece_rh(0, 3, false, false);
	pieces[2] = new_piece_rh(3, 0, false, false);
	pieces[3] = new_piece_rh(1, 5, false, true);
	pieces[4] = new_piece_rh(3, 4, false, true);
}

void set_up_a() {
	pieces[0] = new_piece(0, 2, 2, 1, true, true);
	pieces[1] = new_piece(4, 3, 2, 3, true, true);
	pieces[2] = new_piece(1, 0, 3, 2, true, true);
	pieces[3] = new_piece(4, 1, 2, 1, true, true);
	pieces[4] = new_piece(2, 6, 2, 2, true, true);
}


void new_board_rh(game g) {
	int i,j,k;
	int width = 6;
	int height = 6;

	int *game_board = (int *)malloc(sizeof(int)*width*height);
	for (int y = 0 ; y < height ; y++) {
		for (int x = 0 ; x < width ; x++) {
			game_board[x+y*height] = -1;
		}
	}

	for (int i = 0 ; i < NB_PIECES ; i++) {
		piece p;
		p = pieces[i];
		if (can_move_x(p)) {
			for (int j = 0 ; j < get_height(p) ; j++){
				game_board[(get_x(p)+j)+(height-1-get_y(p))*height] = i;
			}
		}
		if (can_move_y(p)) {
			for (int j = 0 ; j < get_height(p) ; j++){
				game_board[(get_x(p))+(height-1-get_y(p)-j)*height] = i;
			}
		}
	}

	for (i = 0; i<width; ++i) {
		printf("+---");
	}
	printf("+\n");
	for(j = 0; j < height; ++j) {
		for (i = 0; i < width; ++i) {
			if (game_board[i+j*height] == -1)
				printf("|   ");
			else
				printf("| %d ", game_board[i+j*height]);
		}
		printf("|\n");
		for(k = 0; k<width; ++k) {
			printf("+---");
		}
		printf("+\n");
	}
}

void new_board_a(game g) {
	int i,j,k;
	int width = game_width(g);
	int height = game_height(g);

	int *game_board = (int *)malloc(sizeof(int)*width*height);
	for (int y = 0 ; y < height ; y++) {
		for (int x = 0 ; x < width ; x++) {
			game_board[x+y*height] = -1;
		}
	}

	for (int i = 0 ; i < NB_PIECES ; i++) {
		piece p;
		p = pieces[i];
		for (int j = 0 ; j < get_height(p) ; j++){
			for (int k = 0 ; k < get_width(p) ; k++){
				game_board[(get_x(p)+k)+(height-1-get_y(p)-j)*height] = i;
				//game_board[get_x(p)+(height*get_y(p)+j+k*height)] = i;
			}
		}
	}
	for (i = 0; i<width; ++i) {
		printf("+---");
	}
	printf("+\n");
	for(j = 0; j < height; ++j) {
		for (i = 0; i < width; ++i) {
			if (game_board[i+j*height] == -1)
				printf("|   ");
			else
				printf("| %d ", game_board[i+j*height]);
		}
		printf("|\n");
		for(k = 0; k<width; ++k) {
			printf("+---");
		}
		printf("+\n");
	}
}

void free_board(game g , int** game_board) {
	int height = game_height(g);
	for (int i = 0 ; i < height ; i ++) {
		free(game_board[i]);
	}
	free (game_board);
}


int main() {

	char choix = 'n';
	int p = -1 , p_choix = 0;
	char direction_choix;
	char direction = 'n';
	int distance = 0 , width = 6 , height = 6 ,nb_moves = 0;
	char lvl_choice , lvl;
	bool fin_jeu = false;

	while (fin_jeu == false) {
		printf("\e[2J\e[H");//clean the shell
		// A huge thanks for the Camille AUSSIGNAC's group who gives us this priceless printf !
		while (choix != 'A' || choix != 'R') {
			printf("\nSelection du jeu \n\nR pour Rush Hour, A pour l'Ane Rouge \n");
			scanf("%s", &choix);
			if (choix != 'A' && choix != 'R') {
				printf("Choix impossible : R pour Rush Hour , A pour l'Ane Rouge \n");
			}
			if (choix == 'A' || choix == 'R') {
				break;
			}
		}
		if (choix == 'A') {
			printf("\e[2J\e[H");//clean the shell
			printf("---| ANE ROUGE |--- \n\n");
			game g = new_game(6, 8, NB_PIECES, pieces);
			set_up_a();
			new_board_a(g);
			while (game_over_hr(g) == false) {
				printf("Selectionnez une piece.\n");
				scanf("%d", &p_choix);
				p = p_choix;
				while ( p < 0 || p > NB_PIECES){
					printf("Selectionnez une piece.\n");
					scanf("%d", &p_choix);
					p = p_choix;
				}
				printf("Vous avez selectionnez %d.\nProposez une direction: LEFT : L, UP : U, RIGHT : R, DOWN D\n", p);
				scanf("%s", &direction_choix);
				direction = direction_choix;
				switch(direction) {
				case 'U' :
					direction = UP;
					break;
				case 'L' :
					direction = LEFT;
					break;
				case 'D' :
					direction = DOWN;
					break;
				case 'R' :
					direction = RIGHT;
					break;
				}
				while (direction != RIGHT && direction != UP && direction != DOWN && direction != LEFT) {
					printf("Direction invalide.\n Proposez une direction: LEFT, UP, RIGHT, DOWN\n");
					scanf("%s", &direction_choix); 
					direction = direction_choix;
					switch(direction) {
					case 'U' :
						direction = UP;
						break;
					case 'L' :
						direction = LEFT;
						break;
					case 'D' :
						direction = DOWN;
						break;
					case 'R' :
						direction = RIGHT;
						break;
					}
				}
				printf("Proposez une distance à parcourir.\n");
				scanf("%d", &distance);
				while (play_move_an(g, p, direction, distance, width, height) == false) {
					printf("Proposez une distance à parcourir.\n");
					scanf("%d", &distance);
				}
				printf("\e[2J\e[H");//clean the shell
				new_board_a(g);

				nb_moves+=1;
			}
			if (game_over_hr(g) == true) {
				printf("Vous avez fini en %d coups. Bravo ! \n", nb_moves);
				return EXIT_SUCCESS;
			}
		}
		if (choix == 'R') {
			printf("\e[2J\e[H");//clean the shell
			printf("---| RUSH HOUR |--- \n\n");
			printf("Selectionnez un niveau : Tuto , T / Facile , F / Normal , N / Difficile , D.\n");
			scanf("%s", &lvl_choice);
			lvl = lvl_choice;
			game g = new_game_hr(NB_PIECES, pieces);
			while (lvl != 'T' && lvl != 'F' && lvl != 'N' && lvl != 'D') {
				printf("Niveau invalide.\n Selectionnez un niveau : Tuto , T / Facile , F / Normal , N / Difficile , D.\n");
				scanf("%s", &lvl_choice);
				lvl = lvl_choice;
			}
			printf("\e[2J\e[H");//clean the shell
			switch(lvl) {
			case 'T' :
				set_up_rh();
				new_board_rh(g);
				break;
			case 'F' :
				set_up_rh2();
				new_board_rh(g);
				break;
			case 'N' :
				set_up_rh3();
				new_board_rh(g);
				break;
			case 'D' :
				set_up_rh2();
				new_board_rh(g);
				break;
			}
			while (game_over_hr(g) == false) {
				printf("Selectionnez une piece.\n");
				scanf("%d", &p_choix);
				p = p_choix;
				printf("\nVous avez selectionnez %d.\n\nProposez une direction: LEFT : L, UP : U, RIGHT : R, DOWN D\n", p);
				scanf("%s", &direction_choix);
				direction = direction_choix;
				switch(direction) {
				case 'U' :
					direction = UP;
					break;
				case 'L' :
					direction = LEFT;
					break;
				case 'D' :
					direction = DOWN;
					break;
				case 'R' :
					direction = RIGHT;
					break;
				}
				while ((direction != RIGHT && direction != UP && direction != DOWN && direction != LEFT) || !can_move(pieces[p], direction)) {
					if (!can_move(pieces[p], direction))
						printf("\nCette pièce ne peut pas aller dans cette direction.\n");
					if (direction != RIGHT && direction != UP && direction != DOWN && direction != LEFT)
						printf("\nDirection invalide !");
					printf("\nProposez une direction: LEFT, UP, RIGHT, DOWN\n");
					scanf("%s", &direction_choix); 
					direction = direction_choix;
					switch(direction) {
					case 'U' :
						direction = UP;
						break;
					case 'L' :
						direction = LEFT;
						break;
					case 'D' :
						direction = DOWN;
						break;
					case 'R' :
						direction = RIGHT;
						break;
					}
				}
				printf("Proposez une distance à parcourir.\n");
				scanf("%d", &distance);
				while (play_move(g, p, direction, distance, width, height) == false) {
					printf("Proposez une distance à parcourir.\n");
					scanf("%d", &distance);
				}
				printf("\e[2J\e[H");//clean the shell
				new_board_rh(g);

				nb_moves+=1;
			}
			if (game_over_hr(g) == true) {
				printf("Vous avez fini en %d coups. Bravo ! \n", nb_moves);
				return EXIT_SUCCESS;
			}
		}
		/*
         while (rejouer != 'O' || rejouer != 'N') {
           printf("Voulez-vous rejouer? O/N");
           scanf("%s", &rejouer_choix);
           rejouer = rejouer_choix;
         }
         if (rejouer == 'O') {
           fin_jeu = false;
           delete_game(g);
           set_up();
           new_board(g);
           choix = -1;
           p = -1;
           direction = 'n';
           distance = 0;
           width = 6;
           height = 6;
         } 
         else{
           delete_game(g);
         }


		 */

		//free(g);
	}
}




