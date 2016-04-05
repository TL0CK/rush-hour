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
    p->move_x = true;
    p->move_y = false;
  }
  else{
    p->move_x = false;
    p->move_y = true;
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
    return true;
  if ( (d == LEFT || d == RIGHT) && can_move_x(p))
    return true;
  return false;
}

// Move the piece p in direction d and the distance from parameter
void move_piece(piece p, dir d, int distance){
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

bool intersect(cpiece A , cpiece B ){
	if (is_horizontal(A) && is_horizontal(B)){
	  if (get_x(A) != get_x(B)){
	    return false;
	  }
	  for (int i = get_x(A) ; i < get_x(A) + get_width(A) - 1 ; i++){
	    if ( i == get_x(B) ) {
	      return true;
	    }
	  }
	  return false;
	}
	
	if (is_horizontal(A) && !is_horizontal(B)){
	  for (int j = get_x(A) ; j < get_x(A) + get_width(A) - 1 ; j++){
	    for (int k = get_y(B) ; k < get_y(B) + get_height(B)-1 ; k++){
	      if (j + get_y(A)*6 == k*6 + get_x(B)){
	        return true;
	      }
	    }
	  }
	}
	
	if(is_horizontal(B) && !is_horizontal(A)){
	 for (int j = get_x(B) ; j < get_x(B) + get_width(B) - 1 ; j++){
	    for (int k = get_y(A) ; k < get_y(A) + get_height(A)-1 ; k++){
	      if (j + get_y(B)*6 == k*6 + get_x(A)){
	        return true;
	      }
	    }
	  }
	}
	return false;

/*


A: (x1, y1)
B: (x2, y2) 
C: (x3, y3) 
D: (x4, y4) 


	int x1 = get_x(A);
	int y1 = get_y(A);
	int x2 = x1 + get_width(A) -1;
	int y2 = y1 + get_height(A) -1;
	int x3 = get_x(B);
	int y3 = get_y(B);
	int x4 = x2 - get_width(B) -1;
	int y4 = y2 + get_height(B) -1;
	
	
	float a1;
	float b1;
	float a2;
	float b2;
	
	
	y1 = a1 * x1 + b1
	y2 = a1 * x2 + b1
	y3 = a2 * x3 + b2
	y4 = a2 * x4 + b2
	
	
	if (x1 == x2){
	 a1 = (y2 - y1);
	}
	
	if (x4==x3){
	 a2 = (y4 - y3);
	}
	
	if (x1!=x2 && x3!=x4){
	  a1 = (y2 - y1) / (x2 - x1);
	  a2 = (y4 - y3) / (x4 - x3);
	}
	
	b1 = y1 - (a1 * x1);
	b2 = y3 - (a2 * x3);

	if (a1 == a2){
	  if (y1 != y3){
	      return false;
	  }
	  return true;
	}
	
	int xcommun=(b2-b1)/(a1-a2) ;
	
	if (x1 <= xcommun && xcommun <= x2 && x3 <= xcommun && xcommun <= x4){
	  return false;
	}
	return true;
	
	*/
	/*
		int Ax = get_x(A);
		int Ay = get_y(A);
		int Bx = Ax + get_width(A) -1;
		int By = Ay - get_height(A) -1;
		int Cx = get_x(B);
		int Cy = get_y(B);
		int Dx = Bx + get_width(B) -1;
		int Dy = By - get_height(B) -1;
 
		double Sx;
		double Sy;
 
		if(Ax==Bx){
			if(Cx==Dx) 
			  return false;
			else{
				double pCD = (Cy-Dy)/(Cx-Dx);
				Sx = Ax;
				Sy = pCD*(Ax-Cx)+Cy;
			}
		}
		else{
			if(Cx==Dx){
				double pAB = (Ay-By)/(Ax-Bx);
				Sx = Cx;
				Sy = pAB*(Cx-Ax)+Ay;
			}
			else{
				double pCD = (Cy-Dy)/(Cx-Dx);
				double pAB = (Ay-By)/(Ax-Bx);
				double oCD = Cy-pCD*Cx;
				double oAB = Ay-pAB*Ax;
				Sx = (oAB-oCD)/(pCD-pAB);
				Sy = pCD*Sx+oCD;
			}
		}
		if((Sx<Ax && Sx<Bx)|| (Sx>Ax && Sx>Bx) || (Sx<Cx && Sx<Dx) ||(Sx>Cx && Sx>Dx) || (Sy<Ay && Sy<By) ||(Sy>Ay && Sy>By) || (Sy<Cy && Sy<Dy)|(Sy>Cy && Sy>Dy)) 
		  return false;
		return true; 
	*/


/*

for (int i=1; i<get_width(p1); ++i) {
        for (int j=1; j<get_height(p1); ++j) {
            for (int k=1; k<get_width(p2); ++k) {
                for (int l=1; l<get_height(p2); ++l) {
                    if((p1->x)+i == (p2->x)+k && (p1->y)+j == (p2->y)+l)
                        return true;
                }
            }
        }
    }
    return false;
*/
/*

  int maxgauche = max(get_x(p1),get_x(p2));
  int mindroit = min(get_x(p1) + get_width(p1) , get_x(p2) + get_width(p2));
  int maxbas = max(get_y(p1) ,  get_y(p2));
  int minhaut = min( get_y(p1) + get_height(p1) , get_y(p2) + get_height(p2));

  if ((maxgauche < mindroit) && (maxbas < minhaut))
    return true;
  return false;
  */
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

bool is_small(cpiece p){
  return (p->width < 3 && p->height < 3);
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
