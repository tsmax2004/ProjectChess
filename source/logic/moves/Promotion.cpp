//
// Created by Георгий Кузнецов on 12.03.2022.
//

#include "../headers/logic.h"

Promotion::Promotion() = default;

std::shared_ptr<Promotion> Promotion::GetMove() {
  if (promotion_move_ == nullptr) {
    promotion_move_ = std::shared_ptr<Promotion>(new Promotion());
  }
  return promotion_move_;
}

void Promotion::MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const {
  position.board_[to_row][to_col] = Queen::GetPiece(position.at(from_row, from_col)->GetColor());
  position.board_[from_row][from_col] = Empty::GetPiece();
  position.last_move_ = {from_row, from_col, to_row, to_col};
  position.move_color_ = {position.move_color_ == COLOR::WHITE ? COLOR::BLACK : COLOR::WHITE};
  position.position_type_ = POSITION_TYPE::NOT_DEFINED;
}

bool Promotion::IsValid() const {
  return true;
}
