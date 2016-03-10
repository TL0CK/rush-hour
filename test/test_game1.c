#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "game.h"

#define NB_PIECES 4

/**
 * @brief test if value is equal to expected; if not, displays an error message containing msg to standard error output
 * @return true if expected==value
 */
bool test_equality_int(int expected, int value, char * msg) {
  if (expected != value)
    fprintf(stderr,"ERR: value expected %d ; value computed %d. %s\n", expected, value, msg);
  return expected == value;
}

/**
 * @brief test if value is equal to expected; if not, displays an error message containing msg to standard error output
 */
bool test_equality_bool(bool expected, bool value, char * msg) {
  if (expected != value)
    fprintf(stderr,"ERR: value expected %d ; value computed %d. %s\n", expected, value, msg);
  return expected == value;
}

piece pieces[NB_PIECES];
/* configue de test
.....3
.....3
...003
......
...122
...1..
 */
void set_up() {
  pieces[0] = new_piece_rh(3, 3, true, true);
  pieces[1] = new_piece_rh(3, 0, true, false);
  pieces[2] = new_piece_rh(4, 1, true, true);
  pieces[3] = new_piece_rh(5, 3, false, false);
}
void tear_down() {
  for (int i = 0 ; i < NB_PIECES; i++)
    delete_piece(pieces[i]);
}

bool test_new_game() {
  bool result = true;
  game g = new_game_hr(NB_PIECES, pieces);
  result = result && test_equality_int(NB_PIECES, game_nb_pieces(g),"game_nb_piece(g)");
  result = result && test_equality_int(0, game_nb_moves(g)),"game_nb_moves(g)");
  delete_game(g);
  return result;
}

bool test_game_over() {
  bool result = true;
  game g = new_game_hr(NB_PIECES, pieces);
  set_up();
  result = result && test_equality_bool(false, game_over_hr(g)),"game_over_hr");
  pieces[0] = new_piece_rh(4, 3, true, true);
  result = result && test_equality_bool(true, game_over_hr(g)),"game_over_hr");
  tear_down();
  return result;
}

bool test_play_move() {
  bool result = true;
  piece p = new_piece_rh(0, 0, true, true);
  pieces[0] = p;
  game g = new_game_hr(NB_PIECES, pieces);
  result = result && test_equality_bool(-1, game_board[3][0],"play_move");
  play_move(g, 0, r, 3)
  result = result && test_equality_bool(0, game_board[3][0],"play_move");
  tear_down();
  return result
