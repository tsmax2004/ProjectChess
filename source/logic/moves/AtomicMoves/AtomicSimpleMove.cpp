//
// Created by evgen on 10.03.2022.
//
#include "../../headers/logic.h"

AtomicSimpleMove::AtomicSimpleMove() = default;

std::shared_ptr<AtomicSimpleMove> AtomicSimpleMove::GetMove() {
  if (simple_move_ == nullptr) {
    simple_move_ = std::shared_ptr<AtomicSimpleMove>(new AtomicSimpleMove());
  }
  return simple_move_;
}

void AtomicSimpleMove::MakeMove(int from_row, int from_col, int to_row, int to_col, Position& position) const {
  if (position.at(from_row, from_col)->GetPieceName() == PIECE_NAME::ROOK) {
    if (position.at(from_row, from_col)->GetColor() == COLOR::WHITE) {
      if (from_row == 0 && from_col == 0) {
        position.info_for_castle_[1] = false;
      }
      if (from_row == 0 && from_col == position.cnt_cols - 1) {
        position.info_for_castle_[2] = false;
      }
    }
    if (position.at(from_row, from_col)->GetColor() == COLOR::BLACK) {
      if (from_row == position.cnt_rows - 1 && from_col == 0) {
        position.info_for_castle_[4] = false;
      }
      if (from_row == position.cnt_rows - 1 && from_col == position.cnt_cols - 1) {
        position.info_for_castle_[5] = false;
      }
    }
  }
  if (position.at(from_row, from_col)->GetPieceName() == PIECE_NAME::KING) {
    position.info_for_castle_[(position.at(from_row, from_col)->GetColor() == COLOR::WHITE ? 0 : 3)] = false;
  }
  bool does_capture = position.at(to_row, to_col)->GetPieceName() != PIECE_NAME::EMPTY;
  if (does_capture) {
    for (int i = to_row - 1; i <= to_row + 1; ++i) {
      for (int j = to_col - 1; j <= to_col + 1; ++j) {
        if ((i >= 0) && (j >= 0) && (i < position.cnt_rows) && (j < position.cnt_cols)){
          if (position.at(i, j)->GetPieceName() != PIECE_NAME::PAWN)
            position.board_[i][j] = Empty::GetPiece();
        }
      }
    }
  }
  else{
    position.board_[to_row][to_col] = position.at(from_row, from_col);
  }
  position.board_[from_row][from_col] = Empty::GetPiece();

  position.move_color_ = (position.move_color_ == COLOR::WHITE ? COLOR::BLACK : COLOR::WHITE);
  position.last_move_ = {from_row, from_col, to_row, to_col};
  position.position_type_ = POSITION_TYPE::NOT_DEFINED;
}

bool AtomicSimpleMove::IsValid() const {
  return true;
}
