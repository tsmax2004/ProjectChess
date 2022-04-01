
#ifndef BISHOP_H_
#define BISHOP_H_

#include "Piece.h"

class Bishop : public Piece {
 protected:
  explicit Bishop(COLOR color_);

  static Bishop* white_bishop_;
  static Bishop* black_bishop_;

 public:
  Bishop(const Bishop&) = delete;
  void operator=(const Bishop&) = delete;

  static Bishop* GetPiece(COLOR color);

  [[nodiscard]] const Move* DefineMove(int from_row_,
                         int from_col_,
                         int to_row_,
                         int to_col_,
                         const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
  [[nodiscard]] COLOR GetColor() const override;

  COLOR color_;
};

inline Bishop* Bishop::white_bishop_ = nullptr;
inline Bishop* Bishop::black_bishop_ = nullptr;

#endif
