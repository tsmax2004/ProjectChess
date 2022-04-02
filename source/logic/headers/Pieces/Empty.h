
#ifndef EMPTY_H_
#define EMPTY_H_

#include "Piece.h"

class Empty : public Piece {
 protected:
  Empty();

  static std::shared_ptr<Empty> empty_;

 public:
  Empty(const Empty&) = delete;
  void operator=(const Empty&) = delete;

  static std::shared_ptr<Empty> GetPiece();

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                         int from_col_,
                         int to_row_,
                         int to_col_,
                         const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<Empty> Empty::empty_ = nullptr;

#endif
