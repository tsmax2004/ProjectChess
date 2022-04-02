
#ifndef QUEEN_H_
#define QUEEN_H_

#include "Piece.h"

class Queen : public Piece {
 protected:
  explicit Queen(COLOR color_);

  [[nodiscard]] bool CheckMove(int from_row_,
                               int from_col_,
                               int to_row_,
                               int to_col_,
                               const Position& position_) const;

  static std::shared_ptr<Queen> white_queen_;
  static std::shared_ptr<Queen> black_queen_;

 public:
  Queen(const Queen&) = delete;
  void operator=(const Queen&) = delete;

  static std::shared_ptr<Queen> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                         int from_col_,
                         int to_row_,
                         int to_col_,
                         const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<Queen> Queen::white_queen_ = nullptr;
inline std::shared_ptr<Queen> Queen::black_queen_ = nullptr;

#endif
