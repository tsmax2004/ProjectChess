//
// Created by Георгий Кузнецов on 10.03.2022.
//

#include "../headers/logic.h"
#include <cstdlib>

Bishop::Bishop(COLOR color_) : Piece(color_) {}

std::shared_ptr<Bishop> Bishop::GetPiece(COLOR color) {
  if (color == COLOR::WHITE) {
    if (white_bishop_ == nullptr) {
      white_bishop_ = std::shared_ptr<Bishop>(new Bishop(COLOR::WHITE));
    }
    return white_bishop_;
  }
  if (color == COLOR::BLACK) {
    if (black_bishop_ == nullptr) {
      black_bishop_ = std::shared_ptr<Bishop>(new Bishop(COLOR::BLACK));
    }
    return black_bishop_;
  }
  return nullptr;
}

std::shared_ptr<Move> Bishop::DefineMove(int from_row_,
                                         int from_col_,
                                         int to_row_,
                                         int to_col_,
                                         const Position& position_) const {
  if (!CheckMoveColor(position_)) { return InvalidMove::GetMove(); }
  if (!CheckAttackSquareIsNotFriend(to_row_, to_col_, position_)) { return InvalidMove::GetMove(); }
  if (CheckMove(from_row_, from_col_, to_row_, to_col_, position_)) { return SimpleMove::GetMove(); }
  return InvalidMove::GetMove();
}

bool Bishop::CheckMove(int from_row_, int from_col_, int to_row_, int to_col_, const Position& position_) {
  if (std::abs(from_row_ - to_row_) != std::abs(from_col_ - to_col_)) { return false; }
  if (from_row_ == to_row_) { return false; }
  return CheckBetweenSquaresAreEmpty(from_row_, from_col_, to_row_, to_col_, position_);
}

PIECE_NAME Bishop::GetPieceName() const {
  return PIECE_NAME::BISHOP;
}