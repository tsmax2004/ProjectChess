
#ifndef EMPTY_H_
#define EMPTY_H_

#include "Piece.h"

class Empty : public Piece {
 protected:
  Empty();

  static Empty* empty_;

 public:
  Empty(const Empty&) = delete;
  void operator=(const Empty&) = delete;

  static Empty* get_piece();

  const Move* define_move(int from_row_,
                          int from_col_,
                          int to_row_,
                          int to_col_,
                          const Position& position_) const override;

  PIECE_NAME get_piece_name() const override;
  COLOR get_color() const override;
};

inline Empty* Empty::empty_ = nullptr;

#endif
