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
  position.board_[from_row][from_col] = Empty::get_piece();
  position.board_[to_row][to_col] = Queen::get_piece(position.at(from_row, from_col)->get_color());
  position.last_move_ = {from_row, from_col, to_row, to_col};
  position.move_color_ = {position.move_color_ == WHITE ? BLACK : WHITE};
}

bool Promotion::is_valid() const {
  return true;
}