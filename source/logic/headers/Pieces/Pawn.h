
#ifndef PAWN_H_
#define PAWN_H_

#include "Piece.h"

class Pawn : public Piece {
 protected:
  explicit Pawn(COLOR color_);

  [[nodiscard]] bool CheckMoveOnTwoSquares(int from_row_,
                                           int from_col_,
                                           int to_row_,
                                           int to_col_,
                                           const Position& position_) const;

  [[nodiscard]] bool CheckMoveOnOneSquare(int from_row_,
                                          int from_col_,
                                          int to_row_,
                                          int to_col_,
                                          const Position& position_) const;

  [[nodiscard]] bool CheckEnPassant(int from_row_,
                                    int from_col_,
                                    int to_row_,
                                    int to_col_,
                                    const Position& position_) const;

  [[nodiscard]] bool CheckPromotion(int from_row_,
                                    int from_col_,
                                    int to_row_,
                                    int to_col_,
                                    const Position& position_) const;

  static std::shared_ptr<Pawn> white_pawn_;
  static std::shared_ptr<Pawn> black_pawn_;

 public:
  Pawn(const Pawn&) = delete;
  void operator=(const Pawn&) = delete;

  static std::shared_ptr<Pawn> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row,
                                                 int from_col,
                                                 int to_row,
                                                 int to_col,
                                                 const Position& position) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<Pawn> Pawn::white_pawn_ = nullptr;
inline std::shared_ptr<Pawn> Pawn::black_pawn_ = nullptr;

#endif
