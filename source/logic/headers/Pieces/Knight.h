
#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "Piece.h"

class Knight : public Piece {
 protected:
  explicit Knight(COLOR color_);

  static Knight* white_knight_;
  static Knight* black_knight_;

 public:
  Knight(const Knight&) = delete;
  void operator=(const Knight&) = delete;

  static Knight* GetPiece(COLOR color);

  [[nodiscard]] const Move* DefineMove(int from_row_,
                         int from_col_,
                         int to_row_,
                         int to_col_,
                         const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
  [[nodiscard]] COLOR GetColor() const override;

  COLOR color_;
};

inline Knight* Knight::white_knight_ = nullptr;
inline Knight* Knight::black_knight_ = nullptr;

#endif
