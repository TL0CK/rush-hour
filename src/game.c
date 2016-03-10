#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAILLE 6

struct game_s{
  int **game_board; //tableau a initialiser depuis en bas a gauche, la il est en haut a gauche, aka la case en basa
    int nb_pieces;   //droite doit etre 0 0 et la c'est 5 0
    int nb_moves;
    piece *piece;
};

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


int game_nb_moves(cgame g){
  return g->nb_moves;
}
