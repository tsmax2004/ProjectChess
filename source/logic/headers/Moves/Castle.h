
#ifndef CASTLE_H_
#define CASTLE_H_

#include "Move.h"

class Castle : Move {
 protected:
  Castle();

  static Castle *castle_;

 public:
  Castle(const Castle &) = delete;

  void operator=(const Castle &) = delete;

  static Castle *get_move();

  void make_move(int from_row, int from_col, int to_row, int to_col, Position &position) const override;

  bool is_valid = true;
};

Castle *Castle::castle_ = nullptr;

#endif
