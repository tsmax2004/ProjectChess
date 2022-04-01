
#ifndef PAWN_H_
#define PAWN_H_

#include "Piece.h"

class Pawn : public Piece {
 protected:
  explicit Pawn(COLOR color_);

  static Pawn* white_pawn_;
  static Pawn* black_pawn_;

 public:
  Pawn(const Pawn&) = delete;
  void operator=(const Pawn&) = delete;

  static Pawn* GetPiece(COLOR color);

  [[nodiscard]] const Move* DefineMove(int from_row_,
                         int from_col_,
                         int to_row_,
                         int to_col_,
                         const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
  [[nodiscard]] COLOR GetColor() const override;

  COLOR color_;
};

inline Pawn* Pawn::white_pawn_ = nullptr;
inline Pawn* Pawn::black_pawn_ = nullptr;

#endif
