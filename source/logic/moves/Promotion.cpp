//
// Created by Георгий Кузнецов on 12.03.2022.
//

#include "../headers/logic.h"

Promotion::Promotion() = default;

Promotion* Promotion::get_move() {
  if (promotion_move_ == nullptr) promotion_move_ = new Promotion;
  return promotion_move_;
}

void Promotion::make_move(int from_row, int from_col, int to_row, int to_col, Position& position) const {
  position.at(from_row, from_col)->piece_name_ = EMPTY;
  position.at(to_row, to_col)->piece_name_ = QUEEN;
  position.at(to_row, to_col)->color_ = position.at(from_row, from_col)->color_;
  position.last_move_ = {from_row, from_col, to_row, to_col};
  position.move_color_ = {position.move_color_ == WHITE ? BLACK : WHITE};
}