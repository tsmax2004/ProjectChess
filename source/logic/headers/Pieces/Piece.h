
#ifndef PIECE_H_
#define PIECE_H_

#include "../Enums.h"

class Move;

class Position;

class Piece {
 public:
  virtual const Move* define_move(int from_row_,
                                  int from_col_,
                                  int to_row_,
                                  int to_col_,
                                  const Position& position_) const = 0;
  virtual PIECE_NAME get_piece_name() const = 0;
  virtual COLOR get_color() const = 0;
};

#endif
