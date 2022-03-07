
#ifndef PAWN_H_
#define PAWN_H_

#include "Piece.h"

// Singleton + Bridge patterns
class Pawn: Piece {
 private:
  Pawn(COLOR color);

  static Pawn* white_pawn_;
  static Pawn* black_pawn_;

 public:
  Pawn(const Pawn&) = delete;
  void operator=(const Pawn&) = delete;

  static Pawn* get_piece(COLOR color);
  const Move* define_move(int from_row, int from_col, int to_row, int to_col, const Position& position) override;

  COLOR color_;
};

Pawn* Pawn::white_pawn_ = nullptr;
Pawn* Pawn::black_pawn_ = nullptr;

#endif
