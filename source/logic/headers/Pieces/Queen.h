
#ifndef QUEEN_H_
#define QUEEN_H_

#include "Piece.h"

// Singleton + Bridge patterns
class Queen : public Piece {
 protected:
  Queen(COLOR color_);

  static Queen* white_queen_;
  static Queen* black_queen_;

 public:
  Queen(const Queen&) = delete;
  void operator=(const Queen&) = delete;

  static Queen* get_piece(COLOR color);

  const Move* define_move(int from_row_,
                          int from_col_,
                          int to_row_,
                          int to_col_,
                          const Position& position_) const override;

  COLOR color_;
  PIECE_NAME piece_name_ = QUEEN;
};

Queen* Queen::white_queen_ = nullptr;
Queen* Queen::black_queen_ = nullptr;

#endif
