
#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "Piece.h"

// Singleton + Bridge patterns
class Knight : Piece {
 protected:
  Knight(COLOR color);

  static Knight *white_knight_;
  static Knight *black_knight_;

 public:
  Knight(const Knight &) = delete;

  void operator=(const Knight &) = delete;

  static Knight *get_piece(COLOR color);

  const Move *define_move(int from_row, int from_col, int to_row, int to_col, Position &position) const override;

  COLOR color_;
  PIECE_NAME piece_name_ = KNIGHT;
};

Knight *Knight::white_knight_ = nullptr;
Knight *Knight::black_knight_ = nullptr;

#endif
