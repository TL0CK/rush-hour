#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool play_move(game g , int piece_num, dir d , int distance) {
  piece p = g->pieces[piece_num];
  if ((d == UP || d == DOWN) && !can_move_y(p) ){
    printf("Cette piece ne peut bouger que dans le sens de droite et de gauche.\n");
    return false;
  }
  else { 
    if ((d == LEFT || d == RIGHT) && !can_move_x(p) ){
      printf("Cette piece ne peut bouger que dans le sens de haut en bas.\n");
      return false;
    }
    return true;
}
  int travel = 0;
  while (distance != 0) {
    move_piece(p, d, 1);
    g->nb_moves += 1;
    distance--;
    travel++;
    for (int i = 0; i<game_nb_pieces(g); ++i) {
      if (p == g->pieces[i]) {
        i++;
        if (i >= game_nb_pieces(g))
          break;
      }
      if (intersect(p, game_piece(g, i))){
        printf("Unauthorized move: Piece %d is preventing %d from moving.\n\n", i, piece_num);
        move_piece(p, d, travel*-1);
        g->nb_moves -= travel;
        return false;
      }
    }
  }
  return true;
}
