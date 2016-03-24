#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "game.h"
#include "piece.h"


#define TAILLE 6
#define NB_PIECES 4

piece pieces[NB_PIECES];

void set_up() {
  pieces[0] = new_piece_rh(0, 2, true, true);
  pieces[1] = new_piece_rh(3, 3, true, true);
  pieces[2] = new_piece_rh(3, 0, true, false);
  pieces[3] = new_piece_rh(4, 1, true, true);
  pieces[4] = new_piece_rh(5, 3, false, false);
}


void new_board(game g) {
  int i,j,k;
  int width = 6;
  int height = 6;

  int *game_board = (int *)malloc(sizeof(int)*width*height);
  for (int y = 0 ; y < height ; y++) {
    for (int x = 0 ; x < width ; x++) {
      game_board[x+y*height] = -1;
    }
  }

  for (int i = 0 ; i <= NB_PIECES ; i++) {
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

void free_board(game g , int** game_board) {
  int height = game_height(g);
  for (int i = 0 ; i < height ; i ++) {
    free(game_board[i]);
  }
  free (game_board);
}

int main() {
  set_up();
  char choix = 'n';
  int p = -1;
  char direction = 'n';
  dir d;
  int distance = 0;
  int width = 6;
  int height = 6;
  int nb_moves = 0;
  char rejouer = 'n';
  bool fin_jeu = false;

  while (fin_jeu == false) {
    while (choix != 'A' || choix != 'R') {
      printf("\n Selection du jeu \n\n R pour Rush Hour, A pour l'Ane Rouge \n");
      scanf("%s", &choix);
      if (choix != 'A' && choix != 'R') {
        printf("Choix impossible : R pour Rush Hour , A pour l'Ane Rouge \n");
      }
      if (choix == 'A' || choix == 'R') {
        break;
      }
    }
    if (choix == 'R') {
      printf("---| RUSH HOUR |--- \n\n");
      game g = new_game_hr(NB_PIECES, pieces);
      new_board(g);
      while (game_over_hr(g) == false) {
        printf("Selectionnez une piece.\n");
        scanf("%d", &p);
        printf("Vous avez selectionnez %d.\n Proposez une direction: LEFT : L, UP : U, RIGHT : R, DOWN D\n", p);
        scanf("%s", &direction);
        while ((direction != 'L' && direction != 'U' && direction != 'R' && direction != 'D') || !play_move(g, p, direction, 0)) {
          printf("Direction invalide.\n Proposez une direction: LEFT, UP, RIGHT, DOWN\n");
          scanf("%s", &direction);
        }
        if(direction == 'U' || direction == 'R' || direction == 'D' || direction == 'L')
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
        printf("Proposez une distance à parcourir.\n");
        scanf("%d", &distance);
        while (play_move(g, p, direction, distance) == false) {
          printf("Distance invalide. Proposez une distance à parcourir.\n");
          scanf("%d", &distance);
        }
	
        if(play_move(g, p, direction, distance)){
          move_piece(pieces[p], direction ,distance);
          nb_moves+=1;
          new_board(g);
        }
        }
        if (game_over_hr(g) == true) {
          printf("Vous avez fini en %d coups. Voulez-vous rejouer? O/N \n", game_nb_moves(g));
          scanf("%s", &rejouer);
          /*while (rejouer != 'O' || rejouer != 'N') {
            printf("Voulez-vous rejouer? O/N");
            scanf("%s", &rejouer);
            if (rejouer == 'O') {
              fin_jeu = false;
              set_up();
              choix = -1;
              p = -1;
              direction = 'n';
              distance = 0;
              width = 6;
              height = 6;
              delete_game(g);
          } else
*/
            delete_game(g);

        }
      }
      //free(g);
    }

/*
    if (choix == 'A') {
      printf("~~~{ L'Ane Rouge }~~~\n\n");
      printf ("Sélectionnez la largeur, puis la hauteur du tableau.\n");
      printf ("Limite comprise entre 6 et 10.\n");
      scanf("%d %d", &width, &height);
      while (width<6 || width>10 || height<6 || height>10) {
        printf ("Limite comprise entre 6 et 10.\n");
        scanf("%d %d", &width, &height);
      }
      game g = new_game(width, height, NB_PIECES, pieces);
      new_board(g);
      while (game_over_hr(g) == false) {
        while (test<0 || test>=NB_PIECES) {
          printf("Sélectionnez une pièce.\n");
          scanf("%d", &test);
        }
        printf("Vous avez sélectionnez %d.\n Proposez une direction: LEFT, UP, RIGHT, DOWN\n", test);
        scanf("%s", &direction);
        while (direction != 'L' && direction != 'U' && direction != 'R' && direction != 'P') {
          printf("Direction invalide.\n Proposez une direction: LEFT, UP, RIGHT, DOWN\n");
          scanf("%s", &direction);
        }
        printf("Proposez une distance à parcourir.\n");
        scanf("%d", &distance);
        while (play_move(g, test, direction, distance) == false) {
          printf("Distance invalide. Proposez une distance à parcourir.\n");
          scanf("%d", &distance);
        }
        play_move(g, test, direction, distance);
        if (game_over_hr(g) == true) {
          printf("Vous avez fini en %d coups. Voulez-vous rejouer? O/N \n", game_nb_moves(g));
          scanf("%s", &rejouer);
          while (rejouer != 'O' || rejouer != 'N') {
            printf("Voulez-vous rejouer? O/N");
            scanf("%s", &rejouer);
          }
          if (rejouer == 'O') {
            fin_jeu = false;
            set_up();
            choix = -1;
            test = -1;
            direction = 'n';
            distance = 0;
            width = 6;
            height = 6;
            delete_game(g);
          } else
            delete_game(g);
        }
        free(g);
      }
    */}
 
