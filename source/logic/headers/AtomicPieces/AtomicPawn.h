//
// Created by Георгий Кузнецов on 01.05.2022.
//

#ifndef CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICPAWN_H_
#define CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICPAWN_H_

#include "../Piece.h"

class AtomicPawn : public Piece {
 protected:
  explicit AtomicPawn(COLOR color_);

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

  [[nodiscard]] static bool CheckPromotion(int from_row_,
                                           int from_col_,
                                           int to_row_,
                                           int to_col_,
                                           const Position& position_);

  static std::shared_ptr<AtomicPawn> white_pawn_;
  static std::shared_ptr<AtomicPawn> black_pawn_;

 public:
  AtomicPawn(const AtomicPawn&) = delete;
  void operator=(const AtomicPawn&) = delete;

  static std::shared_ptr<AtomicPawn> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row,
                                                 int from_col,
                                                 int to_row,
                                                 int to_col,
                                                 const Position& position) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<AtomicPawn> AtomicPawn::white_pawn_ = nullptr;
inline std::shared_ptr<AtomicPawn> AtomicPawn::black_pawn_ = nullptr;


#endif //CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICPAWN_H_
