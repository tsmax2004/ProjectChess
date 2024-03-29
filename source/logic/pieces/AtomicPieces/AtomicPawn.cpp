//
// Created by Георгий Кузнецов on 01.05.2022.
//

#include "../../headers/logic.h"
#include <cstdlib>

AtomicPawn::AtomicPawn(COLOR color_) : Piece(color_) {}

std::shared_ptr<AtomicPawn> AtomicPawn::GetPiece(COLOR color) {
  if (color == COLOR::WHITE) {
    if (white_pawn_ == nullptr) {
      white_pawn_ = std::shared_ptr<AtomicPawn>(new AtomicPawn(COLOR::WHITE));
    }
    return white_pawn_;
  }
  if (color == COLOR::BLACK) {
    if (black_pawn_ == nullptr) {
      black_pawn_ = std::shared_ptr<AtomicPawn>(new AtomicPawn(COLOR::BLACK));
    }
    return black_pawn_;
  }
  return nullptr;
}

std::shared_ptr<Move> AtomicPawn::DefineMove(int from_row,
                                       int from_col,
                                       int to_row,
                                       int to_col,
                                       const Position& position) const {
  if (!CheckMoveColor(position)) { return InvalidMove::GetMove(); }
  if (!CheckAttackSquareIsNotFriend(to_row, to_col, position)) { return InvalidMove::GetMove(); }
  if (CheckMoveOnTwoSquares(from_row, from_col, to_row, to_col, position)) { return SimpleMove::GetMove(); }
  if (CheckEnPassant(from_row, from_col, to_row, to_col, position)) { return AtomicEnPassant::GetMove(); }
  if (CheckMoveOnOneSquare(from_row, from_col, to_row, to_col, position)) {
    if (CheckPromotion(from_row, from_col, to_row, to_col, position)) { return AtomicPromotion::GetMove(); }
    return AtomicSimpleMove::GetMove();
  }
  return InvalidMove::GetMove();
}

bool AtomicPawn::CheckMoveOnTwoSquares(int from_row_,
                                 int from_col_,
                                 int to_row_,
                                 int to_col_,
                                 const Position& position_) const {
  if (color_ == COLOR::WHITE && from_row_ != 1) { return false; }
  if (color_ == COLOR::BLACK && from_row_ != position_.cnt_rows - 2) { return false; }
  if (to_row_ - from_row_ != (color_ == COLOR::WHITE ? 2 : -2)) { return false; }
  if (from_col_ != to_col_) { return false; }
  if (position_.at(to_row_, to_col_)->GetPieceName() != PIECE_NAME::EMPTY) { return false; }
  return CheckBetweenSquaresAreEmpty(from_row_, from_col_, to_row_, to_col_, position_);
}

bool AtomicPawn::CheckMoveOnOneSquare(int from_row_,
                                int from_col_,
                                int to_row_,
                                int to_col_,
                                const Position& position_) const {
  if (to_row_ - from_row_ != (color_ == COLOR::WHITE ? 1 : -1)) { return false; }
  if (from_col_ == to_col_ && position_.at(to_row_, to_col_)->GetPieceName() == PIECE_NAME::EMPTY) { return true; }
  return (std::abs(from_col_ - to_col_) == 1 && position_.at(to_row_, to_col_)->GetPieceName() != PIECE_NAME::EMPTY);
}

bool AtomicPawn::CheckEnPassant(int from_row_, int from_col_, int to_row_, int to_col_, const Position& position_) const {
  if (position_.last_move_.empty()) { return false; }
  if (std::abs(from_row_ - to_row_) != 1 || std::abs(from_col_ - to_col_) != 1) { return false; }
  if (color_ == COLOR::WHITE && from_row_ != position_.cnt_rows - 4) { return false; }
  if (color_ == COLOR::BLACK && from_row_ != 3) { return false; }
  int attacked_pawn_row = to_row_ + (color_ == COLOR::WHITE ? -1 : 1);
  int attacked_pawn_col = to_col_;
  if (position_.at(attacked_pawn_row, attacked_pawn_col)->GetPieceName() != PIECE_NAME::PAWN) { return false; }
  if (position_.at(attacked_pawn_row, attacked_pawn_col)->GetColor() == color_) { return false; }
  std::vector<int> correct_last_move = {attacked_pawn_row, attacked_pawn_col, attacked_pawn_row, attacked_pawn_col};
  correct_last_move[0] += (color_ == COLOR::WHITE ? 2 : -2);
  return position_.last_move_ == correct_last_move;
}

bool AtomicPawn::CheckPromotion(int from_row_, int from_col_, int to_row_, int to_col_, const Position& position_) {
  return ((to_row_ == 0) || (to_row_ == position_.cnt_rows - 1));
}

PIECE_NAME AtomicPawn::GetPieceName() const {
  return PIECE_NAME::PAWN;
}
