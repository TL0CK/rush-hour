#include "game.h"
#include "piece.h"
#include <stdio.h>
#include <stdlib.h>

#define TAILLE 6

struct game_s{
    int **game_board; /** tableau a initiliasiser depuis en bas a gauche, la il est en haut a gauche, aka la case en bas a droite doit etre 0 0 et la c'est 5 0 */
    int nb_pieces;
    int nb_moves;
    piece *piece;
};


game new_game_hr (int nb_pieces, piece *pieces){
  game g = malloc(sizeof(struct game_s));
  g->game_board = malloc(sizeof(int)*TAILLE);
  for(int i= 0; 1<TAILLE; ++i)
    g->game_board[i] = malloc(sizeof(int)*TAILLE);
  g->game_board[0][3] = 0;
  int x;
  int y;
  for (int i = 0; i<3; ++i)
    do{
      x = rand()%6;
      y = rand()%6;
    } while (g->game_board[x][y] == -1);
  
  g->nb_pieces = nb_pieces;
  g->nb_moves = 0;

  return g;
}
/**new board, place 4 pieces random adans boucle avec intersect*/
/** reset nb pieces nb moves */

void delete_game (game g){
    free(g);
}

int game_nb_pieces(cgame g){
  return g->nb_pieces;
}

bool game_over_hr(cgame g){
    if (g->game_board[4][3]==0)
        return true;
    return false;
}

bool play_move(game g, int piece_num, dir d, int distance){ /** je fais ca */
  if (is_horizontal(game_piece(g,piece_num)))
  /** parcourir tableau pour trouver voiture a deplacer
   * test si la voiture peut etre deplacer sans depasser le bord du tableau
   *deplacer la voiture et modifier les valeurs du tableau
   *si c'est trop long ou complique, reviser le code pour faire des pointeurs?
   **/
    for (int i = 0 ; i<6; i++)
      for (int j = 0; j<6; j++)
	if (g->game_board[i][j] == piece_num)
	  g->nb_moves += 1;
}

int game_nb_moves(cgame g){
  return g->nb_moves;
}
