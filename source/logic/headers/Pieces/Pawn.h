
#ifndef PAWN_H_
#define PAWN_H_

#include "Piece.h"

class Pawn : public Piece {
 protected:
  Pawn(COLOR color_);

  static Pawn* white_pawn_;
  static Pawn* black_pawn_;

 public:
  Pawn(const Pawn&) = delete;
  void operator=(const Pawn&) = delete;

  static Pawn* get_piece(COLOR color);

  const Move* define_move(int from_row_,
                          int from_col_,
                          int to_row_,
                          int to_col_,
                          const Position& position_) const override;

  PIECE_NAME get_piece_name() const override;
  COLOR get_color() const override;

  COLOR color_;
};

inline Pawn* Pawn::white_pawn_ = nullptr;
inline Pawn* Pawn::black_pawn_ = nullptr;

#endif
