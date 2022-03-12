
#ifndef EMPTY_H_
#define EMPTY_H_

#include "Piece.h"

// Singleton + Bridge patterns
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

  PIECE_NAME piece_name_ = EMPTY;
};

inline Empty* Empty::empty_ = nullptr;

#endif
