
#ifndef SIMPLEMOVE_H_
#define SIMPLEMOVE_H_

#include "Move.h"

class SimpleMove : Move {
 protected:
  SimpleMove();

  static SimpleMove *simple_move_;

 public:
  SimpleMove(const SimpleMove &) = delete;

  void operator=(const SimpleMove &) = delete;

  static SimpleMove *get_move();

  void make_move(int from_row, int from_col, int to_row, int to_col, Position &position) const override;

  bool is_valid = true;
};

SimpleMove *SimpleMove::simple_move_ = nullptr;

#endif
