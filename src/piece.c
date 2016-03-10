#include <stdlib.h>
#include <stdio.h>

#include "piece.h"

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
//à faire
}

bool intersect(cpiece p1, cpiece p2){
return false;
//à faire
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
