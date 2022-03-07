
#ifndef King_H_
#define King_H_

#include "Piece.h"

// Singleton + Bridge patterns
class King: Piece {
 protected:
  King(COLOR color);

  static King* white_king_;
  static King* black_king_;

 public:
  King(const King&) = delete;
  void operator=(const King&) = delete;

  static King* get_piece(COLOR color);
  Move* define_move(int from_row, int from_col, int to_row, int to_col, Position& position) override;

  COLOR color_;
  PIECE_NAME piece_name_ = KING;
};

King* King::white_king_ = nullptr;
King* King::black_king_ = nullptr;

#endif
