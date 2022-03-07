
#ifndef PIECE_H_
#define PIECE_H_

#include "../Enums.h"
class Move;
class Position;

class Piece {
 public:
  COLOR color;
  PIECE_NAME piece_name_;
  virtual Move* define_move(int from_row, int from_col, int to_row, int to_col, Position& position) = 0;
};

#endif
