//
// Created by Георгий Кузнецов on 01.05.2022.
//

#include "../../headers/logic.h"
#include <cstdlib>

AtomicQueen::AtomicQueen(COLOR color_) : Piece(color_) {}

std::shared_ptr<AtomicQueen> AtomicQueen::GetPiece(COLOR color) {
  if (color == COLOR::WHITE) {
    if (white_queen_ == nullptr) {
      white_queen_ = std::shared_ptr<AtomicQueen>(new AtomicQueen(COLOR::WHITE));
    }
    return white_queen_;
  }
  if (color == COLOR::BLACK) {
    if (black_queen_ == nullptr) {
      black_queen_ = std::shared_ptr<AtomicQueen>(new AtomicQueen(COLOR::BLACK));
    }
    return black_queen_;
  }
  return nullptr;
}

std::shared_ptr<Move> AtomicQueen::DefineMove(int from_row_,
                                        int from_col_,
                                        int to_row_,
                                        int to_col_,
                                        const Position& position_) const {
  if (!CheckMoveColor(position_)) { return InvalidMove::GetMove(); }
  if (!CheckAttackSquareIsNotFriend(to_row_, to_col_, position_)) { return InvalidMove::GetMove(); }
  if (CheckMove(from_row_, from_col_, to_row_, to_col_, position_)) { return AtomicSimpleMove::GetMove(); }
  return InvalidMove::GetMove();
}

bool AtomicQueen::CheckMove(int from_row_, int from_col_, int to_row_, int to_col_, const Position& position_) {
  if (std::abs(to_row_ - from_row_) != (std::abs(to_col_ - from_col_))
      && (to_col_ != from_col_) && (to_row_ != from_row_)) { return false; }
  return CheckBetweenSquaresAreEmpty(from_row_, from_col_, to_row_, to_col_, position_);
}

PIECE_NAME AtomicQueen::GetPieceName() const {
  return PIECE_NAME::QUEEN;
}
