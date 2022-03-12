
#ifndef MOVE_H_
#define MOVE_H_

#include "../Enums.h"

class Position;

class Move {
 public:
  virtual void make_move(int from_row, int from_col, int to_row, int to_col, Position& position) const = 0;
  virtual bool is_valid() const = 0;
};

#endif
