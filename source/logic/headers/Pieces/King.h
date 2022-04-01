
#ifndef King_H_
#define King_H_

#include "Piece.h"

class King : public Piece {
 protected:
  explicit King(COLOR color);

  static King* white_king_;
  static King* black_king_;

 public:
  King(const King&) = delete;
  void operator=(const King&) = delete;

  static King* GetPiece(COLOR color);

  [[nodiscard]] const Move* DefineMove(int from_row_,
                         int from_col_,
                         int to_row_,
                         int to_col_,
                         const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
  [[nodiscard]] COLOR GetColor() const override;

  COLOR color_;
};

inline King* King::white_king_ = nullptr;
inline King* King::black_king_ = nullptr;

#endif
