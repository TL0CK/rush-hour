#include <stdlib.h> 
#include <time.h>
#include <stdio.h>
#include <stdbool.h>


int *set_board(){
  int width = 6;
  int height = 6;
  
  int *game_board = (int *)malloc(sizeof(int)*width*height);
  for (int x = 0 ; x < width ; x++){
    for (int y = 0 ; y < height ; y++){
      game_board[x+y*height] = 1;
    }
  }
  return game_board;
}
 

void free_board( int** game_board){
  int height = 6;
  for (int i = 0 ; i < height ; i ++){
    free(game_board[i]);
  }
  free (game_board);
}

void main(){
  int i,j,k;
  int width = 6;
  int height = 6;
  
  int *game_board = (int *)malloc(sizeof(int)*width*height);
  for (int x = 0 ; x < width ; x++){
    for (int y = 0 ; y < height ; y++){
      game_board[x+y*height] = -1;
    }
  }
  for (int i = 0 ; i < NB_PIECES ; i++){
    piece p;
    p = pieces[i];
    for (int j = get_x(p) ; j < get_width(p) ; j++){
      for (int k = get_y(p) ; k < get_height(p) ; k++){
        game_board[j][k] = i;
      }
    }
  
  
  for (i=0;i<width;i++){
    printf("+---");
  }
  printf("+\n");
  for (i=0;i < width;i++) {
    for(j=0;j < height;j++) {
      printf("| %d ", game_board[i+j*height]);
    }
    printf("|\n");
    for(k=0;k<width;k++){
      printf("+---");
    }
    printf("+\n");
  }
}
