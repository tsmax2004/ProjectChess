//
// Created by Георгий Кузнецов on 10.03.2022.
//

#include "../headers/logic.h"
#include <cstdlib>

Knight::Knight(COLOR color_) : Piece(color_) {}

std::shared_ptr<Knight> Knight::GetPiece(COLOR color) {
  if (color == COLOR::WHITE) {
    if (white_knight_ == nullptr) {
      white_knight_ = std::shared_ptr<Knight>(new Knight(COLOR::WHITE));
    }
    return white_knight_;
  }
  if (color == COLOR::BLACK) {
    if (black_knight_ == nullptr) {
      black_knight_ = std::shared_ptr<Knight>(new Knight(COLOR::BLACK));
    }
    return black_knight_;
  }
  return nullptr;
}

std::shared_ptr<Move> Knight::DefineMove(int from_row_,
                               int from_col_,
                               int to_row_,
                               int to_col_,
                               const Position& position_) const {
  if (!CheckMoveColor(position_)) { return InvalidMove::GetMove(); }
  if (!CheckAttackSquareIsNotFriend(to_row_, to_col_, position_)) { return InvalidMove::GetMove(); }
  if (CheckMove(from_row_, from_col_, to_row_, to_col_, position_)) { return SimpleMove::GetMove(); }
  return InvalidMove::GetMove();
}

bool Knight::CheckMove(int from_row_, int from_col_, int to_row_, int to_col_, const Position& position_) const {
  auto mov_ = std::pair<int, int>(std::abs(to_row_ - from_row_), std::abs(to_col_ - from_col_));
  auto cor_mov_ = std::pair<int, int>(1, 2);
  if ((mov_ != cor_mov_) && (mov_.first != cor_mov_.second || mov_.second != cor_mov_.first)) { return false; }
  return true;
}

PIECE_NAME Knight::GetPieceName() const {
  return PIECE_NAME::KNIGHT;
}
