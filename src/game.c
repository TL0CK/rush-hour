#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "piece.h"
#include "game.h"

struct game_s {
  // int **game_board; //tableau a initialiser depuis en bas a gauche, la il est en haut a gauche, aka la case en bas à
  int nb_pieces;   //droite doit etre 0 0 et la c'est 5 0
  int nb_moves;
  int height;
  int width;
  piece *pieces;
};

/* Create a board for the game "Rush Hour" and allocate memory
   Reset nb_move, assign nb_pieces to g and put *pieces on the board
   Create the first piece at [0][3] in the board*/

game new_game_hr (int nb_pieces, piece *pieces) {
  game g = malloc(sizeof(struct game_s));

  g->width = 6;
  g->height = 6;
  g->nb_pieces = nb_pieces;
  g->nb_moves = 0;
  g->pieces = pieces;

  return g;
}

/* Create a board at the dimension (width, height) for the game "Ane Rouge" and allocate memory
   Reset nb_move, assign nb_pieces to g and put *pieces on the board
   Create the first piece at [0][3] in the board*/

game new_game(int width, int height, int nb_pieces, piece *pieces) {
  game g = malloc(sizeof(struct game_s));

  g->width = width;
  g->height = height;
  g->nb_pieces = nb_pieces;
  g->nb_moves = 0;
  g->pieces = pieces;

  return g;
}

// Take all parameter of dst and copy all of them in src
void copy_game(cgame src, game dst) {
  dst->nb_moves = src->nb_moves;
  dst->height = src->height;
  dst->width = src->width;
  dst->nb_pieces = src->nb_pieces;
  for (int i = 0; i<dst->nb_pieces; ++i) {
    copy_piece(src->pieces[i], dst->pieces[i]);
  }
}

// Free memory allocated to g
void delete_game (game g) {
  free(g);
}

// Return nb_piece of g
int game_nb_pieces(cgame g) {
  return g->nb_pieces;
}

// Return nb_move of g
int game_nb_moves(cgame g) {
  return g->nb_moves;
}

// Return the width of the g's board
int game_width(cgame g) {
  return g->width;
}

// Return the height of the g's board
int game_height(cgame g) {
  return g->height;
}

/* Return the number of piece located in the square ((0,0) , (x,y))
   If this square hasn't any piece, return -1 */
int game_square_piece (game g, int x, int y) {
  for (int i = 0; i<g->nb_pieces; ++i) {
    piece p = g->pieces[i];
    for (int w=0; w<get_width(p); ++w) {
      for (int h = 0; h<get_height(p); ++h) {
        if (get_x(p)+w == x && get_y(p)+h == y)
          return i;
      }
    }
  }
  return -1;
}

/* Test if the game is over
   True if the game is won, false if not */
bool game_over_hr(cgame g) {
  return (get_x(g->pieces[0])==4) && (get_y(g->pieces[0])==2);
}

// Return the number of piece_num located in g
cpiece game_piece(cgame g, int piece_num) {
  return g->pieces[piece_num];
}

/* Find the piece_num in the game's board of g
   Then test if this piece can move in the direction d
   Move the piece in this direction with the distance of parameter */
int conversion_x (piece p , int width , int height){
  int i = get_x(p)+1;
  int j = get_y(p);
  int tab = i + (height-1-j)*height;
  int i_conversion =  (tab%(height));
  return i_conversion;
}

int conversion_y (piece p , int width , int height){
  int i = get_x(p)+1;
  int j = get_y(p);
  int tab = i + (height-1-j)*height;
  int j_conversion = height - j;
  return j_conversion;
}

bool play_move(game g , int piece_num, dir d , int distance , int width , int height) {
  /*
  int new_x = conversion_x (g->pieces[piece_num] , width , height);
  int new_y = conversion_y (g->pieces[piece_num] , width , height);
  piece piecetest = new_piece_rh( new_x, new_y, is_small(g->pieces[piece_num]) , is_horizontal(g->pieces[piece_num]));
  */
  piece piecetest = new_piece_rh( get_x(g->pieces[piece_num]), get_y(g->pieces[piece_num]), is_small(g->pieces[piece_num]) , is_horizontal(g->pieces[piece_num]));
  //printf("new_x = %d et new_y = %d\n" , new_x , new_y);
  
  if ((d == UP || d == DOWN) && !can_move_y(piecetest) ){
    printf("Cette piece ne peut bouger que dans le sens de droite et de gauche.\n");
    return false;
  }
  if ((d == LEFT || d == RIGHT) && !can_move_x(piecetest)){
      printf("Cette piece ne peut bouger que dans le sens de haut en bas.\n");
      return false;
  }
  
  
  for (int i = 1 ; i <= distance ; i++){
    move_piece(piecetest, d, 1);
    for (int j = 0 ; j < game_nb_pieces(g) ; j++){
      /*
      int new_x_temp = conversion_x (g->pieces[j] , width , height);
      int new_y_temp = conversion_y (g->pieces[j] , width , height);
      */
      //printf("new_x_temp = %d et new_y_temp = %d\n" , new_x_temp , new_y_temp);
      
      //piece piecetemp = new_piece_rh( get_x(g->pieces[j]), get_y(g->pieces[j]), is_small(g->pieces[j]) , is_horizontal(g->pieces[j]));
	
	printf("x%d = %d y%d = %d , x%d = %d y%d = %d\n" , piece_num , get_x(piecetest) , piece_num ,get_y(piecetest) , j , get_x(g->pieces[j]) , j , get_y(g->pieces[j]));
      if (intersect(piecetest,g->pieces[j])){ 
        if (piece_num !=j){
         printf("Intersect avec %d\n" , j);
         return false;
        }
      }
    }
  }
/*
  move_piece(g->pieces[piece_num], d, distance);
  return true;
  
  }
*/
  move_piece(g->pieces[piece_num], d, distance);
  if (get_x(g->pieces[piece_num]) < 0 || get_x(g->pieces[piece_num])+get_width(g->pieces[piece_num]) > game_width(g) || get_y(g->pieces[piece_num]) < 0 || get_y(g->pieces[piece_num])+get_height(g->pieces[piece_num]) > game_width(g)){
    move_piece(g->pieces[piece_num], d, -distance);
    return false;
  }
  return true;

}





