//
// Created by Георгий Кузнецов on 12.03.2022.
//

#include "../../headers/logic.h"

AtomicEnPassant::AtomicEnPassant() = default;

std::shared_ptr<AtomicEnPassant> AtomicEnPassant::GetMove() {
  if (en_passant_move_ == nullptr) {
    en_passant_move_ = std::shared_ptr<AtomicEnPassant>(new AtomicEnPassant());
  }
  return en_passant_move_;
}

void AtomicEnPassant::MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const {
  position.board_[to_row][to_col] = position.board_[from_row][from_col];
  position.board_[from_row][from_col] = Empty::GetPiece();
  position.board_[position.last_move_[2]][position.last_move_[3]] = Empty::GetPiece();
  position.move_color_ = ((position.move_color_ == COLOR::BLACK) ? COLOR::WHITE : COLOR::BLACK);
  position.position_type_ = POSITION_TYPE::NOT_DEFINED;
  position.last_move_ = {from_row, from_col, to_row, to_col};
}

bool AtomicEnPassant::IsValid() const {
  return true;
}
