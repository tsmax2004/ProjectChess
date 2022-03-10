
#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "Piece.h"

// Singleton + Bridge patterns
class Knight : Piece {
 protected:
  Knight(COLOR color);

  static Knight* white_knight_;
  static Knight* black_knight_;

 public:
  Knight(const Knight&) = delete;
  void operator=(const Knight&) = delete;

  static Knight* get_piece(COLOR color);

  const Move* define_move(int from_row_,
                          int from_col_,
                          int to_row_,
                          int to_col_,
                          const Position& position_) const override;

  COLOR color_;
  static const PIECE_NAME piece_name_ = KNIGHT;
};

Knight* Knight::white_knight_ = nullptr;
Knight* Knight::black_knight_ = nullptr;

#endif
