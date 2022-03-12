
#ifndef ROOK_H_
#define ROOK_H_

#include "Piece.h"

// Singleton + Bridge patterns
class Rook : public Piece {
 protected:
  Rook(COLOR color_);

  static Rook* white_rook_;
  static Rook* black_rook_;

 public:
  Rook(const Rook&) = delete;
  void operator=(const Rook&) = delete;

  static Rook* get_piece(COLOR color);

  const Move* define_move(int from_row_,
                          int from_col_,
                          int to_row_,
                          int to_col_,
                          const Position& position_) const override;

  PIECE_NAME get_piece_name() const override;
  COLOR get_color() const override;

  COLOR color_;
};

inline Rook* Rook::white_rook_ = nullptr;
inline Rook* Rook::black_rook_ = nullptr;

#endif
