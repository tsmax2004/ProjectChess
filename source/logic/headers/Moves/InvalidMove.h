
#ifndef InvalidMove_H_
#define InvalidMove_H_

#include "Move.h"

class InvalidMove : public Move {
 protected:
  InvalidMove();

  static InvalidMove* invalid_move_;

 public:
  InvalidMove(const InvalidMove&) = delete;
  void operator=(const InvalidMove&) = delete;

  static InvalidMove* get_move();

  void make_move(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  bool is_valid = false;
};

inline InvalidMove* InvalidMove::invalid_move_ = nullptr;

#endif
