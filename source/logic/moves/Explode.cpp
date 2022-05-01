//
// Created by Георгий Кузнецов on 01.05.2022.
//

#include "../headers/logic.h"
#include <iostream>

ExplodeMove::ExplodeMove() = default;

std::shared_ptr<ExplodeMove> ExplodeMove::GetMove(std::shared_ptr<Move> move) {
  move_ = move;
  if (move_ref_ == nullptr) {
    move_ref_ = std::shared_ptr<ExplodeMove>(new ExplodeMove());
  }
  return move_ref_;
}

void ExplodeMove::MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const {
  if (!move_->IsValid()) return;
  bool does_capture = position.at(to_row, to_col)->GetPieceName() != PIECE_NAME::EMPTY;
  move_->MakeMove(from_row, from_col, to_row, to_col, position);
  std::cerr << from_row << from_col << to_row << to_col << '\n';
  std::cerr << does_capture << '\n';
  for (int i = to_row - 1; i <= to_row + 1; ++i) {
    for (int j = to_col - 1; j <= to_col + 1; ++j) {
      if (i == to_row && j == to_col) {
        if (does_capture)
          position.board_[i][j] = Empty::GetPiece();
      }
      else if ((to_row >= 0) && (to_row < position.cnt_rows) && (to_col >= 0) && (to_col < position.cnt_cols)) {
        if (position.at(i, j)->GetPieceName() != PIECE_NAME::PAWN)
          position.board_[i][j] = Empty::GetPiece();
      }
    }
  }
}

bool ExplodeMove::IsValid() const {
  return move_->IsValid();
}