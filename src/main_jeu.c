#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "game.c"
#include "piece.c"

#define TAILLE 6
#define NB_PIECES 4

piece pieces[NB_PIECES];

void set_up() {
  pieces[0] = new_piece_rh(3, 3, true, true);
  pieces[1] = new_piece_rh(3, 0, true, false);
  pieces[2] = new_piece_rh(4, 1, true, true);
  pieces[3] = new_piece_rh(5, 3, false, false);
}

int main() {
  set_up();
  int choix = -1;
  int p = -1;
  char direction = 'n';
  int distance = 0;
  int width = 6;
  int height = 6;

  char rejouer = 'n';
  bool fin_jeu = false;

  while (fin_jeu == false) {
    while (choix != 0 || choix != 1) {
      printf("\n Sélection du jeu \n\n 0 pour Rush Hour, 1 pour l'Ane Rouge \n");
      scanf("%d", &choix);
    }

    if (choix == 0) {
      printf("---| RUSH HOUR |--- \n\n");
      game g = new_game_hr(NB_PIECES, pieces);
      new_board(g);
      while (game_over_hr(g) == false) {
        while (p<0 || p>=NB_PIECES) {
          printf("Sélectionnez une pièce.\n");
          scanf("%d", &p);
        }
        printf("Vous avez sélectionnez %d.\n Proposez une direction: LEFT, UP, RIGHT, DOWN\n", p);
        scanf("%s", &direction);
        while ((direction != 'L' && direction != 'U' && direction != 'R' && direction != 'P') || can_move(p, direction) != true) {
          printf("Direction invalide.\n Proposez une direction: LEFT, UP, RIGHT, DOWN\n", p);
          scanf("%s", &direction);
        }
        printf("Proposez une distance à parcourir.\n");
        scanf("%d", &distance);
        while (play_move(g, p, direction, distance) == false) {
          printf("Distance invalide. Proposez une distance à parcourir.\n");
          scanf("%d", &distance);
        }
        play_move(g, p, direction, distance);
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
            int choix = -1;
            int p = -1;
            char direction = 'n';
            int distance = 0;
            int width = 6;
            int height = 6;
            delete_game(g);
          } else
            delete_game(g);
        }
      }
    }

    if (choix == 1) {
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
        while (p<0 || p>=NB_PIECES) {
          printf("Sélectionnez une pièce.\n");
          scanf("%d", &p);
        }
        printf("Vous avez sélectionnez %d.\n Proposez une direction: LEFT, UP, RIGHT, DOWN\n", p);
        scanf("%s", &direction);
        while (direction != 'L' && direction != 'U' && direction != 'R' && direction != 'P') {
          printf("Direction invalide.\n Proposez une direction: LEFT, UP, RIGHT, DOWN\n", p);
          scanf("%s", &direction);
        }
        printf("Proposez une distance à parcourir.\n");
        scanf("%d", &distance);
        while (play_move(g, p, direction, distance) == false) {
          printf("Distance invalide. Proposez une distance à parcourir.\n");
          scanf("%d", &distance);
        }
        play_move(g, p, direction, distance);
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
            int choix = -1;
            int p = -1;
            char direction = 'n';
            int distance = 0;
            int width = 6;
            int height = 6;
            delete_game(g);
          } else
            delete_game(g);
        }
      }
    }
  }
}
