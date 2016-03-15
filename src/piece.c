#include <stdlib.h>
#include <stdio.h>

#include "piece.h"

#define TAILLE 6

struct piece_s{
    int x;
    int y;
    bool small;
    bool horizontal;
};

piece new_piece_rh (int x, int y, bool small, bool horizontal){
  piece p = malloc(sizeof(struct piece_s));
  p -> x = x;    
  p -> y = y;
  p -> small = small;
  p -> horizontal = horizontal;
  return p;
}

void delete_piece (piece p){
  free(p);
}

void copy_piece (cpiece src, piece dst){ /* deferencing pointer to incomplete type error*/
  dst->x=src->x;
  dst->y=src->y;
  dst->small=src->small;
  dst->horizontal=src->horizontal;
}

void move_piece (piece p, dir d, int distance){
  switch(d){
    
    case UP :
      if (p->horizontal){
        break;
      }
      p->y+=distance;
    case LEFT :
      if (!p->horizontal){
        break;
      }
      p->x-=distance;
    case DOWN :
      if (p->horizontal){
        break;
      }
      p->y-=distance;
    case RIGHT :
      if (!p->horizontal){
        break;
      }
      p->x+=distance;
    default :
      break;
  }
}

bool intersect(cpiece p1, cpiece p2){
  if (p1->horizontal && p2->horizontal){
    for (int i =0;i<get_width(p1);i++){
      for (int j=0;j<get_width(p2);j++){
        if ((p1->x)+i==(p2->x)+j && p1->y==p2->y)
          return true;
      }   
    }
  } 
  if (p1->horizontal && !p2->horizontal){
    for (int i =0;i<get_width(p1);i++){
      for (int j=0;j<get_height(p2);j++){
        if ((p1->x)+i==p2->x && p1->y==(p2->y)+j)
          return true;
      }   
    }
  } 
  else if (!p1->horizontal && !p2->horizontal){
    for (int i =0;i<get_height(p1);i++){
      for (int j=0;j<get_height(p2);j++){
        if (p1->x==p2->x && (p1->y)+i==(p2->y)+j)
          return true;
      }   
    }
  }
  else if (!p1->horizontal && p2->horizontal){
    for (int i =0;i<get_height(p1);i++){
      for (int j=0;j<get_width(p2);j++){
        if (p1->x==(p2->x)+j && (p1->y)+i==p2->y)
          return true;
      }   
    }
  }
  return false;
}

int get_x(cpiece p){
  return p->x;
}

int get_y(cpiece p){
  return p->y;
}

int get_height(cpiece p){
if (p->horizontal)
  return 1;
if (p->small)
  return 2;
return 3;
}

int get_width(cpiece p){
if (!(p->horizontal))
  return 1;
if (p->small)
  return 2;
return 3;
}

bool is_horizontal(cpiece p){
return p->horizontal;
}
