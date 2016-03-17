#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct game_s{
  int **game_board;
    int nb_pieces;
    int nb_moves;
    int height;
    int width;
    piece *piece;
};

/* Create a board for the game "Rush Hour" and allocate memory
   Reset nb_move, assign nb_pieces to g and put *pieces on the board
   Create the first piece at [0][3] in the board*/
game new_game_hr (int nb_pieces, piece *pieces){
  game g = malloc(sizeof(struct game_s));
 
  g->width = 6;
  g->height = 6;

  g->game_board = malloc(sizeof(int)*g->width);

  for(int i= 0; 1< g->width; ++i)
    g->game_board[i] = malloc(sizeof(int)*g->height);

  g->game_board[0][3] = 0;
  g->nb_pieces = nb_pieces;
  g->nb_moves = 0;
  g->piece = pieces;

  return g;
}

/* Create a board at the dimension (width, height) for the game "Ane Rouge" and allocate memory
   Reset nb_move, assign nb_pieces to g and put *pieces on the board
   Create the first piece at [0][3] in the board*/

game new_game(int width, int height, int nb_pieces, piece *pieces){
  game g = malloc(sizeof(struct game_s));
 
  g->width = width;
  g->height = height;

  g->game_board = malloc(sizeof(int)*g->width);

  for(int i= 0; 1< g->width; ++i)
    g->game_board[i] = malloc(sizeof(int)*g->height);

  g->game_board[0][3] = 0;
  g->nb_pieces = nb_pieces;
  g->nb_moves = 0;
  g->piece = pieces;

  return g;
}

// Take all parameter of dst and copy all of them in src
void copy_game(cgame src, game dst){
    dst->nb_moves = src->nb_moves;
    dst->height = src->height;
    dst->width = src->width;
    dst->nb_pieces = src->nb_pieces;
    for (int i = 0; i<dst->nb_pieces; ++i){
        copy_piece(src->piece[i], dst->piece[i]);
    }
    for (int i = 0; i<src->width; ++i){
        for (int j = 0; j<src->height; ++i){
            dst->game_board[i][j] = src->game_board[i][j];
        }
    }
}

// Free memory allocated to g
void delete_game (game g){
    free(g);
}

// Return nb_piece of g
int game_nb_pieces(cgame g){
  return g->nb_pieces;
}

// Return nb_move of g
int game_nb_moves(cgame g){
  return g->nb_moves;
}

// Return the width of the g's board
int game_width(cgame g){
  return g->width;
}

// Return the height of the g's board
int game_height(cgame g){
  return g->height;
}

/* Return the number of piece located in the square ((0,0) , (x,y))
   If this square hasn't any piece, return -1 */
int game_square_piece (game g, int x, int y){
  int nb_piece = 0;
  for (int i = 0; i<x; ++i){
    for (int j = 0; j<y; ++j){
      if (g->game_board[i][j] != -1)
        nb_piece += 1;
    }
  }
  if (nb_piece == 0)
    return -1;
  return nb_piece;
}

/* Test if the game is over
   True if the game is won, false if not */
bool game_over_hr(cgame g){
    if (g->game_board[4][3] == 0)
        return true;
    return false;
}

// Return the number of piece_num located in g
cpiece game_piece(cgame g, int piece_num){
    return g->piece[piece_num];
}

/* Find the piece_num in the game's board of g
   Then test if this piece can move in the direction d
   Move the piece in this direction with the distance of parameter */
bool play_move(game g, int piece_num, dir d, int distance){
  int b = 0 , c = 0;
  for (int i = 0; i<g->width; ++i){
    for (int j = 0; j<g->height; ++j){
      if (g->game_board[i][j] == piece_num){
        b = i;
        c = j;
        break;
      }
    }
  }
  printf(" b: %d, c: %d \n", b, c);
  
  bool small, horizontal;
  if (g->game_board[b+2][c]!=piece_num && g->game_board[b][c+2]!=piece_num)
    small=true;
  if (g->game_board[b][c+1]==piece_num)
    horizontal=true;

  if (small == true && horizontal == true){
    if(d == 'l'){
      g->game_board[b][c] = 0;
      g->game_board[b][c+1] = 0;
      g->game_board[b][c-distance] = piece_num;
      g->game_board[b][c-distance+1] = piece_num;
    }
    if(d == 'r'){
      g->game_board[b][c] = 0;
      g->game_board[b][c+1] = 0;
      g->game_board[b][c+distance] = piece_num;
      g->game_board[b][c+distance+1] = piece_num;
    }
  }
  if (small == false && horizontal == true){
    if(d == 'l'){
      g->game_board[b][c] = 0;
      g->game_board[b][c+1] = 0;
      g->game_board[b][c+2] = 0;
      g->game_board[b][c-distance] = piece_num;
      g->game_board[b][c-distance+1] = piece_num;
      g->game_board[b][c-distance+2] = piece_num;
    }
    if(d == 'r'){
      g->game_board[b][c] = 0;
      g->game_board[b][c+1] = 0;
      g->game_board[b][c+2] = 0;
      g->game_board[b][c+distance] = piece_num;
      g->game_board[b][c+distance+1] = piece_num;
      g->game_board[b][c+distance+2] = piece_num;
    }
  }
  if (small == true && horizontal == false){
    if(d == 'u'){
      g->game_board[b][c] = 0;
      g->game_board[b+1][c] = 0;
      g->game_board[b-distance][c] = piece_num;
      g->game_board[b-distance+1][c] = piece_num;
    }
    if(d == 'd'){
      g->game_board[b][c] = 0;
      g->game_board[b+1][c] = 0;
      g->game_board[b+distance][c] = piece_num;
      g->game_board[b+distance+1][c] = piece_num;
    }
  }
  if (small == false && horizontal == false){
    if(d == 'u'){
      g->game_board[b][c] = 0;
      g->game_board[b+1][c] = 0;
      g->game_board[b+2][c] = 0;
      g->game_board[b-distance][c] = piece_num;
      g->game_board[b-distance+1][c] = piece_num;
      g->game_board[b-distance+2][c] = piece_num;
    }
    if(d == 'd'){
      g->game_board[b][c] = 0;
      g->game_board[b+1][c] = 0;
      g->game_board[b+2][c] = 0;
      g->game_board[b+distance][c] = piece_num;
      g->game_board[b+distance+1][c] = piece_num;
      g->game_board[b+distance+2][c] = piece_num;
    }
  }
}
