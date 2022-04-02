//
// Created by evgen on 10.03.2022.
//

#include "../headers/logic.h"

InvalidMove::InvalidMove() = default;

std::shared_ptr<InvalidMove> InvalidMove::GetMove() {
  if (invalid_move_ == nullptr) {
    invalid_move_ = std::shared_ptr<InvalidMove>(new InvalidMove());
  }
  return invalid_move_;
}

void InvalidMove::MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const {}

bool InvalidMove::IsValid() const {
  return false;
}
