
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

  PIECE_NAME get_piece_name() const override;
  COLOR get_color() const override;

  COLOR color_;
};

inline Bishop* Bishop::white_bishop_ = nullptr;
inline Bishop* Bishop::black_bishop_ = nullptr;

#endif
