
#ifndef BISHOP_H_
#define BISHOP_H_

#include "Piece.h"

// Singleton + Bridge patterns
class Bishop : public Piece {
 protected:
  Bishop(COLOR color_);

  static Bishop* white_bishop_;
  static Bishop* black_bishop_;

 public:
  Bishop(const Bishop&) = delete;
  void operator=(const Bishop&) = delete;

  static Bishop* get_piece(COLOR color);

  const Move* define_move(int from_row_,
                          int from_col_,
                          int to_row_,
                          int to_col_,
                          const Position& position_) const override;

  COLOR color_;
  PIECE_NAME piece_name_ = BISHOP;
};

inline Bishop* Bishop::white_bishop_ = nullptr;
inline Bishop* Bishop::black_bishop_ = nullptr;

#endif
