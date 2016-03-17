#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "game.c"
#include "piece.c"

#define TAILLE 6
#define NB_PIECES 4

int a[TAILLE][TAILLE];

int main(){
  int choix = -1;
  int p = -1;
  char direction = n;
  int distance = 0;

  while (choix != 0 || choix != 1){
    printf("\n Sélection du jeu \n\n 0 pour Rush Hour, 1 pour l'Ane Rouge \n");
    scanf("%d", &choix);
  }

  if (choix == 0){
    printf("---| RUSH HOUR |--- \n\n");
    game g = new_game_hr(NB_PIECE, pieces);
    new_board(g);
    while (game_over_hr(g) == false){
      while (p<0 || p>NB_PIECE){
        printf("Sélectionnez une pièce.\n");
        scanf("%d", &p);
      }
      printf("Vous avez sélectionnez %d.\n Proposez une direction à parcourir: LEFT, UP, RIGHT, DOWN\n", p);
      scanf("%s", &direction);
      while ((direction != L && direction != U && direction != R && direction != P) || can_move(p, direction)){
        printf("Direction invalide.\n Proposez une direction à parcourir: LEFT, UP, RIGHT, DOWN\n", p);
        scanf("%s", &direction);
      }
      printf("Proposez une distance à parcourir\n", p);
      scanf("%d", &distance);  
    }
  }

  if (choix == 1){
    printf("~~~{ L'Ane Rouge }~~~\n\n");
    printf ("Sélectionnez la largeur, puis la hauteur du tableau.\n");
    while (width<6 || width>10 || height<6 || height>10){
      printf ("Limite comprise entre 6 et 10.\n");
      scanf("%d %d", %width, %height);
    }
    game g = new_game(width, height, 4, pieces);
    new_board(g);
    while (game_over_hr(g) == false){
      while (p<0 || p>NB_PIECE){
        printf("Sélectionnez une pièce.\n");
        scanf("%d", &p);
      }
      printf("Vous avez sélectionnez %d.\n Proposez une direction à parcourir: LEFT, UP, RIGHT, DOWN\n", p);
      scanf("%s", &direction);
      while (direction != L && direction != U && direction != R && direction != P){
        printf("Direction invalide.\n Proposez une direction à parcourir: LEFT, UP, RIGHT, DOWN\n", p);
        scanf("%s", &direction);
      }
      printf("Proposez une distance à parcourir\n", p);
      scanf("%d", &distance);
    }
  }
}
