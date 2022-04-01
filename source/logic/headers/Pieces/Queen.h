
#ifndef QUEEN_H_
#define QUEEN_H_

#include "Piece.h"

class Queen : public Piece {
 protected:
  explicit Queen(COLOR color_);

  static Queen* white_queen_;
  static Queen* black_queen_;

 public:
  Queen(const Queen&) = delete;
  void operator=(const Queen&) = delete;

  static Queen* GetPiece(COLOR color);

  [[nodiscard]] const Move* DefineMove(int from_row_,
                         int from_col_,
                         int to_row_,
                         int to_col_,
                         const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
  [[nodiscard]] COLOR GetColor() const override;

  COLOR color_;
};

inline Queen* Queen::white_queen_ = nullptr;
inline Queen* Queen::black_queen_ = nullptr;

#endif
