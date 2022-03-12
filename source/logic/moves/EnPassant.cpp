//
// Created by Георгий Кузнецов on 12.03.2022.
//

#include "../headers/logic.h"

EnPassant::EnPassant() = default;

EnPassant* EnPassant::get_move() {
  if (en_passant_move_ == nullptr) en_passant_move_ = new EnPassant();
  return en_passant_move_;
}

void EnPassant::make_move(int from_row, int from_col, int to_row, int to_col, Position& position) const {
  position.board_[to_row][to_col] = position.board_[from_row][from_col];
  position.board_[from_row][from_col] = Empty::get_piece();
  position.board_[position.last_move_[2]][position.last_move_[3]] = Empty::get_piece();
  position.move_color_ = ((position.move_color_ == BLACK) ? WHITE : BLACK);
  position.position_type_ = NOT_DEFINE;
  position.last_move_ = {from_row, from_col, to_row, to_col};
}