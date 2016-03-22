#include <stdlib.h>
#include <stdio.h>

#include "piece.h"

struct piece_s{
    int x;
    int y;
    int width;
    int height;
    bool move_x;
    bool move_y;
};

/* Create new piece for the game "Rush Hour" and allocate memory for her
   Use x and y as position, and small and horizontal as shape*/
piece new_piece_rh (int x, int y, bool small, bool horizontal){
  piece p = malloc(sizeof(struct piece_s));
  p -> x = x;
  p -> y = y;
  if (small){
    if(horizontal){
      p->height = 1;
      p->width = 2;
    }
    p->height = 2;
    p->width = 1;
  }
  else{
    if(horizontal){
      p->height = 1;
      p->width = 3;
    }
    p->height = 3;
    p->width = 1;
  }
  if (horizontal){
    p->move_x = false;
    p->move_y = true;
  }
  else{
    p->move_x = true;
    p->move_y = false;
  }
  return p;
}

// Free the memory of p
void delete_piece (piece p){
  free(p);
}

// Copy all parameter of dst and attribute all of them to src
void copy_piece (cpiece src, piece dst){
  dst -> x = src->x;
  dst -> y = src->y;
  dst -> height = src -> height;
  dst -> width = src -> width;
  dst -> move_x = src -> move_x;
  dst -> move_y = src -> move_y;
}

// Test if the piece p can move in the direction d
bool can_move ( piece p , dir d){
  if ( (d == UP || d == DOWN)  && can_move_y(p))
    return false;
  if ( (d == LEFT || d == RIGHT) && can_move_x(p))
    return false;
  return true;
}

// Move the piece p in direction d and the distance from parameter
void move_piece(piece p, dir d, int distance){
  if(can_move(p ,d))
  switch(d){
    case UP :
      p->x+=distance;
      break;
    case LEFT :
      p->y-=distance;
      break;
    case DOWN :
      p->x-=distance;
      break;
    case RIGHT :
      p->y+=distance;
      break;
    default :
      break;
  }
}

// Return the higthest value between a and b
int max(int a , int b){
  if (a<b)
    return b;
  return a;
}

// Return the lowest value between a and b
int min(int a , int b){
  if (a<b)
    return a;
  return b;
}

/* Test if the piece p1 and p2 have any intersection between them
   True if they have one, false if not*/
bool intersect(cpiece p1 , cpiece p2){
  int maxgauche = max(get_x(p1),get_x(p2));
  int mindroit = min(get_x(p1) + get_width(p1) , get_x(p2) + get_width(p2));
  int maxbas = max(get_y(p1) , get_y(p2));
  int minhaut = min(get_y(p1) + get_height(p1) , get_y(p2) + get_height(p2));

  if ((maxgauche < mindroit) && (maxbas < minhaut))
    return true;
  return false;
}

// Return the x of the piece p
int get_x(cpiece p){
  return p->x;
}

// Return the y of the piece p
int get_y(cpiece p){
  return p->y;
}

// Return the height of the piece p
int get_height(cpiece p){
  return p->height;
}

// Return the weigth of the piece p
int get_width(cpiece p){
 return p->width;
}

// Test if the piece p is horizontal
bool is_horizontal(cpiece p){
  return (p->move_x && !p->move_y);
}

// Test if the piece can move upper and downer
bool can_move_x(cpiece p){
  return p->move_x;
}

// Test if the piece can move in right and left direction
bool can_move_y(cpiece p){
  return p->move_y;
}

/* Create new piece for the game "Ane Rouge" and allocate memory for her
   Use x and y as position, width and height as dimension, and small and horizontal as shape*/
piece new_piece (int x, int y, int width, int height, bool move_x, bool move_y){
  piece p = malloc(sizeof(struct piece_s));
  p -> x = x;
  p -> y = y;
  p -> width = width;
  p -> height = height;
  p -> move_x = move_x;
  p -> move_y = move_y;
  return p;
}
