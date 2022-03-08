
#ifndef ROOK_H_
#define ROOK_H_

#include "Piece.h"

// Singleton + Bridge patterns
class Rook : public Piece {
 protected:
  Rook(COLOR color);

  static Rook* white_rook_;
  static Rook* black_rook_;

 public:
  Rook(const Rook&) = delete;
  void operator=(const Rook&) = delete;

  static Rook* get_piece(COLOR color);

  const Move* define_move(int from_row, int from_col, int to_row, int to_col, const Position& position) const override;

  COLOR color_;
  PIECE_NAME piece_name_ = ROOK;
};

Rook* Rook::white_rook_ = nullptr;
Rook* Rook::black_rook_ = nullptr;

#endif
