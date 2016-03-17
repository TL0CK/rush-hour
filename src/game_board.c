#include <stdio.h>
#include <stdlib.h>
/*
#include "game_board.h"
*/
struct game_board_s {
  char tab[6];
};
/*
game_board new_game_board(){
  game_board game = malloc(6*sizeof(struct game_board_s));
  for(int i = 0; i < 36; i++){
	game -> matrice[i]='.';
    }
  }
  return game;
}

void delete_game(game_board game){
  free(game);
}

/*
void set_pieces(game_board game , int* piece){
    for (int i = 0; i<sizeof(piece)/sizeof(piece[0]);i++){
        add_piece(game, piece[i], i);
    }
}

void add_piece(game_board grid, cpiece p, int piece_num){
    for (int i = get_x(p) ; i < get_width(p); ++i){
        for (int j = get_y(p);j < get_height(p); ++j){
            game -> matrice[i][j] = piece_num + 48; // A MODIFIER , TABLE ASCII + 48 DONNE UNE VALEUR ENTRE 0 et 9
        }
    }
}

void delete_pieces(game_board game, cpiece p, int piece_num){
    for (int i=get_x(p) ; i<get_width(p);++i){
        for (int j=get_y(p);j<get_height(p);++j){
            grid -> matrice[i][j]=piece_num - 48 ; // A MODIFIER , TABLE ASCII + 48 DONNE UNE VALEUR ENTRE 0 et 9
        }
    }
}

*/

void display_game(game_board game)){
  for(int i = 0 ; i < 36 ; i++){
    if ( i%6 == 6 || i%6 == 5 || i%6 == 4 || i%6 == 3 || i%6 == 2 || i%6 == 1 ){
      printf("\n");
    }
    printf(".");
  }
  printf("\nNombre de mouvements : %d\n----------\n\n", game_nb_moves(grid->g));      
}

/*

void move(game_board game, int piece_num, dir d, int distance){
    game g = game->g;
    delete_pieces(game, piece_num);
    if(play_move(g, piece_num, d, distance))
        add_piece(game, piece_num);
    else
        add_piece(game, piece_num);
    show_grid(game);
}

*/


void main (){
  new_game_board();
  display_game (game);
}
