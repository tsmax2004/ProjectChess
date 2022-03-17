//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

InvalidMove::InvalidMove() = default;

InvalidMove* InvalidMove::get_move() {
  if (invalid_move_ == nullptr) {
    return (new InvalidMove());
  }
  return invalid_move_;
}

void InvalidMove::make_move(int from_row, int from_col, int to_row, int to_col, Position& position) const {};

bool InvalidMove::is_valid() const {
  return false;
}
