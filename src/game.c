#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAILLE 6

struct game_s{
    int **game_board; /** tableau a initialiser depuis en bas a gauche, la il est en haut a gauche, aka la case en bas a droite doit etre 0 0 et la c'est 5 0 */
    int nb_pieces;
    int nb_moves;
    piece *piece;
};

/**
 * @brief Creates a new game given a starting position defined by a set of pieces.
 * The pieces of the created game are copies of the ones given as argument.
 * The number of moves of the game is set to 0.
 * @param nb_pieces number of pieces g
 * @param pieces array of pieces. The pieces given here are not modified by this function.
 * @return a pointer toward the generated game
 */
game new_game_hr (int nb_pieces, piece *pieces){
  game g = malloc(sizeof(struct game_s));

  g->game_board = malloc(sizeof(int)*TAILLE);
  for(int i= 0; 1<TAILLE; ++i)
    g->game_board[i] = malloc(sizeof(int)*TAILLE);

  g->game_board[0][3] = 0;
  g->piece = pieces;
  g->nb_pieces = nb_pieces;
  g->nb_moves = 0;

  return g;
}

/**new board, place 4 pieces random adans boucle avec intersect*/
/** reset nb pieces nb moves */

void delete_game (game g){
    free(g);
}

/**
 * @brief Return the number of pieces on the game board g
*/
int game_nb_pieces(cgame g){
  return g->nb_pieces;
}

/**
 * @brief Test is the game is over (i.e. if the piece 0 has reached the exit).
 * @return true if the piece number 0 has coordinates (4,3)
*/
bool game_over_hr(cgame g){
    if (g->game_board[4][3]==0)
        return true;
    return false;
}

/** Parcourir tableau pour trouver voiture a deplacer
  * test si la voiture peut etre deplacer sans depasser le bord du tableau
  * deplacer la voiture et modifier les valeurs du tableau
  * si c'est trop long ou complique, reviser le code pour faire des pointeurs?
**/
bool play_move(game g, int piece_num, dir d, int distance){
    //localisation piece
  int b=0 , c=0;
  for (int i=0; i<TAILLE; ++i){
    for (int j=0; j<TAILLE; ++j){
      if (g->game_board[i][j] == piece_num){
        b=i;
        c=j;
        break;
      }
    }
  }
  printf(" b: %d, c: %d \n", b, c);
  //test piece small horizontal
  bool small, horizontal;
  if (g->game_board[b+2][c]!=piece_num && g->game_board[b][c+2]!=piece_num)
    small=true;
  if (g->game_board[b][c+1]==piece_num)
    horizontal=true;

    //mouvement piece
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

/**
 * @brief Return the number of moves this the beginning of the game g.
 * Remind that move of a single piece of k cells in a single direction counts for k.
 */
int game_nb_moves(cgame g){
  return g->nb_moves;
}
