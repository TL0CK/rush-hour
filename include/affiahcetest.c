#include <stdio.h>
#include <stdlib.h>

int display_game(){
  for(int i = 0 ; i < 36 ; i++){
    for ( int j = 1 ; j <= 6 ; j++){
      if ( i == 6*j ){
        printf("\n");
      }
    }
    printf(".");
  }
  printf("\n");
  return EXIT_SUCCESS;
}

int main(){

}
