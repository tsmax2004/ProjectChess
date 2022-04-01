
#ifndef ROOK_H_
#define ROOK_H_

#include "Piece.h"

class Rook : public Piece {
 protected:
  explicit Rook(COLOR color_);

  static Rook* white_rook_;
  static Rook* black_rook_;

 public:
  Rook(const Rook&) = delete;
  void operator=(const Rook&) = delete;

  static Rook* GetPiece(COLOR color);

  [[nodiscard]] const Move* DefineMove(int from_row_,
                         int from_col_,
                         int to_row_,
                         int to_col_,
                         const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
  [[nodiscard]] COLOR GetColor() const override;

  COLOR color_;
};

inline Rook* Rook::white_rook_ = nullptr;
inline Rook* Rook::black_rook_ = nullptr;

#endif
