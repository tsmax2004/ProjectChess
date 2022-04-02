//
// Created by Георгий Кузнецов on 11.03.2022.
//

#include "../headers/logic.h"

Castle::Castle() = default;
std::shared_ptr<Castle> Castle::GetMove() {
  if (castle_ == nullptr) {
    castle_ = std::shared_ptr<Castle>(new Castle());
  }
  return castle_;
}
void Castle::MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const {
  position.info_for_castle_[position.at(from_row, from_col)->GetColor() == COLOR::WHITE ? 0 : 3] = false;
  if (from_col - to_col > 0) {
    position.board_[from_row][from_col - 1] = position.at(from_row, 0);
    position.board_[from_row][0] = Empty::GetPiece();
  } else {
    position.board_[from_row][from_col + 1] = position.at(from_row, position.board_[0].size() - 1);
    position.board_[to_row][position.board_[0].size() - 1] = Empty::GetPiece();
  }
  position.board_[to_row][to_col] = position.at(from_row, from_col);
  position.board_[from_row][from_col] = Empty::GetPiece();
  position.move_color_ = (position.move_color_ == COLOR::WHITE ? COLOR::BLACK : COLOR::WHITE);
  position.last_move_ = {from_row, from_col, to_row, to_col};
  position.position_type_ = POSITION_TYPE::NOT_DEFINED;
}

bool Castle::IsValid() const {
  return true;
}
