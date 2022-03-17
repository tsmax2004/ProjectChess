
#ifndef King_H_
#define King_H_

#include "Piece.h"

class King : public Piece {
 protected:
  King(COLOR color);

  static King* white_king_;
  static King* black_king_;

 public:
  King(const King&) = delete;
  void operator=(const King&) = delete;

  static King* get_piece(COLOR color);

  const Move* define_move(int from_row_,
                          int from_col_,
                          int to_row_,
                          int to_col_,
                          const Position& position_) const override;

  PIECE_NAME get_piece_name() const override;
  COLOR get_color() const override;

  COLOR color_;
};

inline King* King::white_king_ = nullptr;
inline King* King::black_king_ = nullptr;

#endif
