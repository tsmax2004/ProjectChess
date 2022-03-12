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
  COLOR pawn_color_ = position.at(from_row, from_col)->color_;
  position.at(from_row, from_col)->piece_name_ = EMPTY;
  position.at(position.last_move_[2], position.last_move_[2])->piece_name_ = EMPTY;
  position.at(position.last_move_[2], position.last_move_[2])->color_ = pawn_color_;
  position.at(to_row, to_col)->piece_name_ = PAWN;
  position.at(to_row, to_col)->color_ = pawn_color_;
  position.last_move_ = {from_row, from_col, to_row, to_col};
}