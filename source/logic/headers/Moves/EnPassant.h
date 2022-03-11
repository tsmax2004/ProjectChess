
#ifndef INPASSING_H_
#define INPASSING_H_

#include "Move.h"

class EnPassant : public Move {
 protected:
  EnPassant();

  static EnPassant* in_passing_move_;

 public:
  EnPassant(const EnPassant&) = delete;
  void operator=(const EnPassant&) = delete;

  static EnPassant* get_move();

  void make_move(int from_row, int from_col, int to_row, int to_col, Position& position) const override;

  bool is_valid = true;
};

EnPassant* EnPassant::in_passing_move_ = nullptr;

#endif
