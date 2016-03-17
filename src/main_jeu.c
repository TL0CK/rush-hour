#include <stdlib.h> 
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "game.h"
#include "piece.h"

#define TAILLE 6
#define NB_PIECES 4

int new_board(game g){
    int i,j,k;
    int w = game_width(g) , h = game_height(g);
    for (i=0;i < w;i++){
      printf("+---");
      printf("+\n");
    }
    for (i=0;i< w; i++){
        for(j=0;j< h ; j++){
            printf("| %d ", game_square_piece (g, i, j));
        }
        printf("|\n");
        for(k=0;k < h;k++){
            printf("+---");
        }
        printf("+\n");
    }
}

int main(){
    game g = new_game_hr(4,pieces);
    new_board(g);
    return EXIT_SUCCESS;
}

/*

void set_piece(int game_board


void placer_piece(int a[TAILLE][TAILLE])
{
    srand(time(NULL));
    int i=2+NB_PIECES;
    while (i>2)
    {
        int x=rand()%5;
        int y=rand()%5;
        int small=rand()%2;
        int horizontal=rand()%2;
        if (horizontal==1 && small==1 && y!=3 && a[x][y]==0 && a[x+1][y]==0)
        {
            a[x][y]=i;
            a[x+1][y]=i;
            i--;
        }
        if (horizontal ==1 && small==0 && y!=3 && x<5 && y<5 && a[x][y]==0 && a[x+1][y]==0 && a[x+2][y]==0)
        {
            a[x][y]=i;
            a[x+1][y]=i;
            a[x+2][y]=i;
            i--;
        }
        if (horizontal==0 && small==1 && a[x][y]==0 && a[x][y+1]==0)
        {
            a[x][y]=i;
            a[x][y+1]=i;
            i--;
        }
        if (horizontal ==0 && small==0 && x<5 && y<5 && a[x][y]==0 && a[x][y+1]==0 && a[x][y+2]==0)
        {
            a[x][y]=i;
            a[x][y+1]=i;
            a[x][y+2]=i;
            i--;
        }
    }
}

void move(int piece, char direction, int distance, int a[TAILLE][TAILLE])
{
    //localisation piece
    int b=0 , c=0, i=0, j=0;
    for (i=0; i<TAILLE;i++)
    {
        for (j=0;j<TAILLE;j++)
        {
            if (a[i][j]==piece)
            {
                b=i;
                c=j;
                break;

            }
        }
    }
    printf(" b: %d, c: %d \n", b, c);
    //test piece small horizontal
    bool small, horizontal;
    if (a[b+2][c]!=piece && a[b][c+2]!=piece)
        small=true;
    if (a[b][c+1]==piece)
        horizontal=true;

    //mouvement piece
    if (small==true && horizontal ==true)
    {
        if(direction=='l')
        {
            a[b][c]=0;
            a[b][c+1]=0;
            a[b][c-distance]=piece;
            a[b][c-distance+1]=piece;
        }
        if(direction=='r')
        {
            a[b][c]=0;
            a[b][c+1]=0;
            a[b][c+distance]=piece;
            a[b][c+distance+1]=piece;
        }
    }
    if (small==false && horizontal ==true)
    {
        if(direction=='l')
        {
            a[b][c]=0;
            a[b][c+1]=0;
            a[b][c+2]=0;
            a[b][c-distance]=piece;
            a[b][c-distance+1]=piece;
            a[b][c-distance+2]=piece;
        }
        if(direction=='r')
        {
            a[b][c]=0;
            a[b][c+1]=0;
            a[b][c+2]=0;
            a[b][c+distance]=piece;
            a[b][c+distance+1]=piece;
            a[b][c+distance+2]=piece;
        }
    }
    if (small==true && horizontal ==false)
    {
        if(direction=='u')
        {
            a[b][c]=0;
            a[b+1][c]=0;
            a[b-distance][c]=piece;
            a[b-distance+1][c]=piece;
        }
        if(direction=='d')
        {
            a[b][c]=0;
            a[b+1][c]=0;
            a[b+distance][c]=piece;
            a[b+distance+1][c]=piece;
        }
    }
    if (small==false && horizontal ==false)
    {
        if(direction=='u')
        {
            a[b][c]=0;
            a[b+1][c]=0;
            a[b+2][c]=0;
            a[b-distance][c]=piece;
            a[b-distance+1][c]=piece;
            a[b-distance+2][c]=piece;
        }
        if(direction=='d')
        {
            a[b][c]=0;
            a[b+1][c]=0;
            a[b+2][c]=0;
            a[b+distance][c]=piece;
            a[b+distance+1][c]=piece;
            a[b+distance+2][c]=piece;
        }
    }
}


bool game_not_over( int a[TAILLE][TAILLE])
{
  return (a[3][6]==1);
}
int main()
{
    a[3][0]=1;
    a[3][1]=1;
    int piece, distance;
    char direction;
    printf("\n Actualisation du jeu \n \n");
    placer_piece(a);
    new_board(a);
    while (game_not_over(a)== false)
    {
        printf("Donnez les specificitées du mouvement: n°piece 1ere lettre du mouvement distance ");
        scanf("%d %s %d", &piece, &direction, &distance );
        move(piece, direction, distance, a);
        new_board(a);
    }
    new_board(a);
    printf("Bravo! \n");
    return 0;
}

*/
