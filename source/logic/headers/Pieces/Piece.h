
#ifndef PIECE_H_
#define PIECE_H_

#include "../Enums.h"

class Move;

class Position;

class Piece {
 public:
  COLOR color_;
  PIECE_NAME piece_name_;

  virtual const Move* define_move(int from_row_,
                                  int from_col_,
                                  int to_row_,
                                  int to_col_,
                                  const Position& position_) const = 0;
};

#endif
