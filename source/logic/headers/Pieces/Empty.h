
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

  static Empty* GetPiece();

  [[nodiscard]] const Move* DefineMove(int from_row_,
                         int from_col_,
                         int to_row_,
                         int to_col_,
                         const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
  [[nodiscard]] COLOR GetColor() const override;
};

inline Empty* Empty::empty_ = nullptr;

#endif
