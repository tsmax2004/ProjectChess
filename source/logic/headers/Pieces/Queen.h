
#ifndef QUEEN_H_
#define QUEEN_H_

#include "Piece.h"

// Singleton + Bridge patterns
class Queen : Piece {
 protected:
  Queen(COLOR color);

  static Queen* white_queen_;
  static Queen* black_queen_;

 public:
  Queen(const Queen&) = delete;
  void operator=(const Queen&) = delete;

  static Queen* get_piece(COLOR color);

  const Move* define_move(int from_row, int from_col, int to_row, int to_col, const Position& position) const override;

  COLOR color_;
  PIECE_NAME piece_name_ = QUEEN;
};

Queen* Queen::white_queen_ = nullptr;
Queen* Queen::black_queen_ = nullptr;

#endif
