//
// Created by evgen on 10.03.2022.
//

#include "../../headers/logic.h"
#include <cstdlib>

King::King(COLOR color_) : Piece(color_) {}

std::shared_ptr<King> King::GetPiece(COLOR color) {
  if (color == COLOR::WHITE) {
    if (white_king_ == nullptr) {
      white_king_ = std::shared_ptr<King>(new King(COLOR::WHITE));
    }
    return white_king_;
  }
  if (color == COLOR::BLACK) {
    if (black_king_ == nullptr) {
      black_king_ = std::shared_ptr<King>(new King(COLOR::BLACK));
    }
    return black_king_;
  }
  return nullptr;
}

std::shared_ptr<Move> King::DefineMove(int from_row_,
                                       int from_col_,
                                       int to_row_,
                                       int to_col_,
                                       const Position& position_) const {
  if (!CheckMoveColor(position_)) { return InvalidMove::GetMove(); }
  if (!CheckAttackSquareIsNotFriend(to_row_, to_col_, position_)) { return InvalidMove::GetMove(); }
  if (CheckCastle(from_row_, from_col_, to_row_, to_col_, position_)) { return Castle::GetMove(); }
  if (CheckSimpleMove(from_row_, from_col_, to_row_, to_col_, position_)) { return SimpleMove::GetMove(); }
  return InvalidMove::GetMove();
}

bool King::CheckCastle(int from_row_, int from_col_, int to_row_, int to_col_, const Position& position_) const {
  if (position_.position_type_ != POSITION_TYPE::COMMON) { return false; }
  if (!position_.info_for_castle_[color_ == COLOR::WHITE ? 0 : 3]) { return false; }
  if (from_row_ != to_row_) { return false; }
  if (to_col_ - from_col_ == 2) {
    if (!position_.info_for_castle_[2 + (color_ == COLOR::WHITE ? 0 : 3)]) { return false; }
    if (!CheckBetweenSquaresAreEmpty(from_row_, from_col_, to_row_, to_col_ + 1, position_)) { return false; }
    if (!CheckBetweenSquaresAreNotUnderAttack(from_row_, from_col_, to_row_, to_col_ + 1, position_)) { return false; }
  } else if (to_col_ - from_col_ == -2) {
    if (!position_.info_for_castle_[1 + (color_ == COLOR::WHITE ? 0 : 3)]) { return false; }
    if (!CheckBetweenSquaresAreEmpty(from_row_, from_col_, to_row_, to_col_ - 2, position_)) { return false; }
    if (!CheckBetweenSquaresAreNotUnderAttack(from_row_, from_col_, to_row_, to_col_ - 1, position_)) { return false; }
  } else {
    return false;
  }
  return true;
}

bool King::CheckBetweenSquaresAreNotUnderAttack(int from_row_,
                                                int from_col_,
                                                int to_row_,
                                                int to_col_,
                                                const Position& position_) const {
  int diff_row = (to_row_ - from_row_) / (std::abs(to_row_ - from_row_) != 0 ? std::abs(to_row_ - from_row_) : 1);
  int diff_col = (to_col_ - from_col_) / (std::abs(to_col_ - from_col_) != 0 ? std::abs(to_col_ - from_col_) : 1);
  int between_row = from_row_;
  int between_col = from_col_;
  COLOR attack_color = color_ == COLOR::WHITE ? COLOR::BLACK : COLOR::WHITE;
  for (int i = 1; i < std::max(std::abs(to_row_ - from_row_), std::abs(to_col_ - from_col_)); ++i) {
    between_row += diff_row;
    between_col += diff_col;
    if (position_.SquareIsUnderAttack(between_row, between_col, attack_color)) { return false; }
  }
  return true;
}

bool King::CheckSimpleMove(int from_row_, int from_col_, int to_row_, int to_col_, const Position& position_) {
  if (std::abs(to_row_ - from_row_) >= 2 || std::abs(to_col_ - from_col_) >= 2) { return false; }
  if ((to_row_ == from_row_) && (to_col_ == from_col_)) { return false; }
  return true;
}

PIECE_NAME King::GetPieceName() const {
  return PIECE_NAME::KING;
}

