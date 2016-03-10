#include "piece.h"

struct piece_s{
    int x;
    int y;
    bool small;
    bool horizontal;
};

piece new_piece_rh (int x, int y, bool small, bool horizontal){
  piece *new_piece=(struct piece*)malloc(sizeof(piece));
  new_piece->x= x;    
  /* Si marche pas, essayer new_piece ->x=malloc(sizeof(x)); ou demander prof */
  new_piece->y= y;
  new_piece->small= small;
  new_piece->horizontal= horizontal;
  return new_piece;
}

void delete_piece (piece p){
  free (p);
}

/**
 * @brief Clones the piece src into the piece dst.
 * @param[out] src the piece to copy
 * @param[in]  dst the copied piece
 */
void copy_piece (cpiece src, piece dst){ /* deferencing pointer to incomplete type error*/
  dst->x=src->x;
  dst->y=src->y;
  dst->small=src->small;
  dst->horizontal=src->horizontal;
}

void move_piece (piece p, dir d, int distance); /** je fais ca */

/**
 * @brief tests whether or not pieces p1 and p2 overlap.
 * @return true if pieces p1 and p2 have at least one cell in common and false otherwise.
 */
bool intersect(cpiece p1, cpiece p2); /** je fais ca */
if

/**
 * @brief Returns the abscissa of leftmost point of the piece p.
 */
int get_x(cpiece p){
  return p->x;
}
/**
 * @brief Returns the ordinate of lowest point of the piece p.
 */
int get_y(cpiece p){
  return p->y;

/**
 * @brief Returns the different of ordinates of the uppermost and the lowest points of the piece p.
 */
int get_height(cpiece p){
  if (p->horizontal)
    return 1;
  else:
    if (p->small)
      return 2;
  return 3;
}

/**
 * @brief Returns the different of abscissas of the leftmost and the rightmost points of the piece p.
 */
int get_width(cpiece p){
  if (p->horizontal)
    if (p->small)
      return 2;
    else:
      return 3;
  return 1;
}

/**
 * @brief Returns true if the piece is
 */
bool is_horizontal(cpiece p){
  return p->horizontal;
}
