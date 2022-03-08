
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

  const Move* define_move(int from_row, int from_col, int to_row, int to_col, const Position& position) const override;

  PIECE_NAME piece_name_ = EMPTY;
};

Empty* Empty::empty_ = nullptr;

#endif
