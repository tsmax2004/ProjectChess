#include "../headers/logic.h"
#include <cstdlib>

Piece::Piece(COLOR color) : color_(color) {}

bool Piece::CheckAttackSquareIsNotFriend(int to_row, int to_col, const Position& position) const {
  if (position.at(to_row, to_col)->GetPieceName() == PIECE_NAME::EMPTY) { return true; }
  if (position.at(to_row, to_col)->GetColor() != color_) { return true; }
  return false;
}

bool Piece::CheckMoveColor(const Position& position) const {
  return color_ == position.move_color_;
}

bool Piece::CheckBetweenSquaresAreEmpty(int from_row,
                                        int from_col,
                                        int to_row,
                                        int to_col,
                                        const Position& position) {
  int diff_row = (to_row - from_row) / (std::abs(to_row - from_row) != 0 ? std::abs(to_row - from_row) : 1);
  int diff_col = (to_col - from_col) / (std::abs(to_col - from_col) != 0 ? std::abs(to_col - from_col) : 1);
  int between_row = from_row;
  int between_col = from_col;
  for (int i = 1; i < std::max(std::abs(to_row - from_row), std::abs(to_col - from_col)); ++i) {
    between_row += diff_row;
    between_col += diff_col;
    if (position.at(between_row, between_col)->GetPieceName() != PIECE_NAME::EMPTY) { return false; }
  }
  return true;
}

COLOR Piece::GetColor() const {
  return color_;
}
