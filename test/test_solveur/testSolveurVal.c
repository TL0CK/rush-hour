#include <stdio.h>
#include <stdlib.h>

#include "main_jeu.c"

int solveur(game g , int piece_num){
	for (int i = 1 ; i <= distance ; i++){
         	move_piece(piece_num, RIGHT , 1);
    		for (int j = 0 ; j < game_nb_pieces(g) ; j++){
     			if (intersect(piecetest,g->pieces[j])){ 
       				if (piece_num !=j){
					

  for (int i = 0; i < 93; ++i){
    for (int num_piece = 0; num_piece < game_nb_pieces(g); ++num_piece){
      for (int dir = 0; dir <= 3; ++dir){
        switch(dir){
          case 0 :
            dir = UP;
            break;
          case 1 :
            dir = LEFT;
            break;
          case 2 :
            dir = DOWN;
            break;
          case 3 :
            dir = RIGHT;
            break;
        }
        while (play_move(g, num_piece, dir, 1, game_width(g), game_height(g)))
        if (game_over_hr(g))
          printf("Solution en %d coups", i);
          return 1;
      }
    }
  }
  printf("Rien");
  return 0;
}

void main (){



}
