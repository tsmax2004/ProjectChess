
#ifndef INPASSING_H_
#define INPASSING_H_

#include "Move.h"

class InPassing: Move {
 protected:
  InPassing();
  static InPassing* in_passing_move_;

 public:
  InPassing(const InPassing&) = delete;
  void operator=(const InPassing&) = delete;

  static InPassing* get_move();
  void make_move(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  bool is_valid = true;
};

InPassing* InPassing::in_passing_move_ = nullptr;

#endif
