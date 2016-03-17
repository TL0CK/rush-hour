#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "game.c"
#include "piece.c"

#define TAILLE 6
#define NB_PIECES 4

int a[TAILLE][TAILLE];

int new_board(int a[TAILLE][TAILLE]){
    int i, j, k;
    for (i = 0; i<TAILLE; ++i)
    printf("+---");
    printf("+\n");
    for (i = 0; i<TAILLE; ++i){
        for(j = 0; j<TAILLE; ++j)
            printf("| %d ", a[i][j])
        printf("|\n");
        for(k = 0; k<TAILLE; ++k)
            printf("+---");
        printf("+\n");
    }
}


void put_piece(int a[TAILLE][TAILLE]){
    srand(time(NULL));
    int i = 2+NB_PIECES;
    while (i>2){
        int x = rand()%5;
        int y = rand()%5;
        int small = rand()%2;
        int horizontal = rand()%2;
        if (horizontal == 1 && small == 1 && y != 3 && a[x][y] == 0 && a[x+1][y] == 0){
            a[x][y] = i;
            a[x+1][y] = i;
            i--;
        }
        if (horizontal == 1 && small == 0 && y != 3 && x<5 && y<5 && a[x][y] == 0 && a[x+1][y] == 0 && a[x+2][y] == 0){
            a[x][y] = i;
            a[x+1][y] = i;
            a[x+2][y] = i;
            i--;
        }
        if (horizontal == 0 && small == 1 && a[x][y] == 0 && a[x][y+1] == 0){
            a[x][y] = i;
            a[x][y+1] = i;
            i--;
        }
        if (horizontal == 0 && small == 0 && x<5 && y<5 && a[x][y] == 0 && a[x][y+1] == 0 && a[x][y+2] == 0){
            a[x][y]=i;
            a[x][y+1]=i;
            a[x][y+2]=i;
            i--;
        }
    }
}

int main()
{
    a[3][0]=1;
    a[3][1]=1;
    int piece, distance;
    char direction;
    printf("\n Actualisation du jeu \n \n");
    put_piece(a);
    new_board(a);
    while (game_over(a) == false){
      printf("Donnez les specificitées du mouvement: n°piece 1ere lettre du mouvement distance ");
      scanf("%d %s %d", &piece, &direction, &distance );
      move(piece, direction, distance, a);
      new_board(a);
    }
    new_board(a);
    printf("Bravo! \n");
    return 0;
}
