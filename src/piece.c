#include <stdlib.h>
#include <stdio.h>

#include "piece.h"

#define TAILLE 6

struct piece_s{
    int x;
    int y;
    int width;
    int height;
    bool move_x;
    bool move_y;
};


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
    p->move_x = true;
    p->move_y = false;
  }
  else{
    p->move_x = false;
    p->move_y = true; 
  } 
  return p;
}

void delete_piece (piece p){
  free(p);
}

void copy_piece (cpiece src, piece dst){
  dst -> x = src->x;
  dst -> y = src->y;
  dst -> height = src -> height;
  dst -> width = src -> width;
  dst -> move_x = src -> move_x;
  dst -> move_y = src -> move_y;
}

bool can_move ( piece p , dir d){
  if ( (d == UP || d == DOWN)  && p->move_x && !p->move_y)
    return false;
  if ( (d == LEFT || d == RIGHT) && !p->move_x && p->move_y)
    return false;
  return true; 
}


void move_piece (piece p, dir d, int distance){
  if(can_move(p ,d))
  switch(d){
    case UP :
      p->y+=distance;
      break;
    case LEFT :
      p->x-=distance;
      break;
    case DOWN :
      p->y-=distance;
      break;
    case RIGHT :
      p->x+=distance;
      break;
    default :
      break;
  }
}

int max(int a , int b){
  if (a<b)
    return b;
  return a;
}

int min(int a , int b){
  if (a<b)
    return a;
  return b;
}

bool intersect(cpiece p1 , cpiece p2){
  int maxgauche = max(get_x(p1),get_x(p2));
  int mindroit = min(get_x(p1) + get_width(p1) , get_x(p2) + get_width(p2));
  int maxbas = max(get_y(p1) , get_y(p2));
  int minhaut = min(get_y(p1) + get_height(p1) , get_y(p2) + get_height(p2));
  
  if ((maxgauche < mindroit) && (maxbas < minhaut))
    return true;
  return false;
}

int get_x(cpiece p){
  return p->x;
}

int get_y(cpiece p){
  return p->y;
}

int get_height(cpiece p){
  return p -> height;
}

int get_width(cpiece p){
 return p -> width;
}

bool is_horizontal(cpiece p){
  return (p->move_x && !p->move_y);
}

bool can_move_x(cpiece p){
  return p->move_x;
}

bool can_move_y(cpiece p){
  return p->move_y;
}

piece new_piece (int x, int y, int width, int height, bool move_x, bool move_y){
  piece p = malloc(sizeof(struct piece_s));
  p -> x = x;
  p -> y = y;
  p -> height = height;
  p -> width = width;
  p -> move_x = move_x;
  p -> move_y = move_y;
  return p;
}

