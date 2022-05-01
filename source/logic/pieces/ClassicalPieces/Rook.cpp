//
// Created by evgen on 10.03.2022.
//

#include "../../headers/logic.h"

Rook::Rook(COLOR color_) : Piece(color_) {}

std::shared_ptr<Rook> Rook::GetPiece(COLOR color) {
  if (color == COLOR::WHITE) {
    if (white_rook_ == nullptr) {
      white_rook_ = std::shared_ptr<Rook>(new Rook(COLOR::WHITE));
    }
    return white_rook_;
  }
  if (color == COLOR::BLACK) {
    if (black_rook_ == nullptr) {
      black_rook_ = std::shared_ptr<Rook>(new Rook(COLOR::BLACK));
    }
    return black_rook_;
  }
  return nullptr;
}

std::shared_ptr<Move> Rook::DefineMove(int from_row_,
                                       int from_col_,
                                       int to_row_,
                                       int to_col_,
                                       const Position& position_) const {
  if (!CheckMoveColor(position_)) { return InvalidMove::GetMove(); }
  if (!CheckAttackSquareIsNotFriend(to_row_, to_col_, position_)) { return InvalidMove::GetMove(); }
  if (CheckMove(from_row_, from_col_, to_row_, to_col_, position_)) { return SimpleMove::GetMove(); }
  return InvalidMove::GetMove();
}

bool Rook::CheckMove(int from_row_, int from_col_, int to_row_, int to_col_, const Position& position_) {
  if ((to_col_ != from_col_) && (to_row_ != from_row_)) { return false; }
  return CheckBetweenSquaresAreEmpty(from_row_, from_col_, to_row_, to_col_, position_);
}

PIECE_NAME Rook::GetPieceName() const {
  return PIECE_NAME::ROOK;
}
