
#ifndef BISHOP_H_
#define BISHOP_H_

#include "Piece.h"

// Singleton + Bridge patterns
class Bishop : public Piece {
 protected:
  Bishop(COLOR color);

  static Bishop* white_bishop_;
  static Bishop* black_bishop_;

 public:
  Bishop(const Bishop&) = delete;
  void operator=(const Bishop&) = delete;

  static Bishop* get_piece(COLOR color);

  const Move* define_move(int from_row, int from_col, int to_row, int to_col, const Position& position) const override;

  COLOR color_;
  PIECE_NAME piece_name_ = BISHOP;
};

Bishop* Bishop::white_bishop_ = nullptr;
Bishop* Bishop::black_bishop_ = nullptr;

#endif
