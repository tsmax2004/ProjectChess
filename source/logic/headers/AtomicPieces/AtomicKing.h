//
// Created by Георгий Кузнецов on 01.05.2022.
//

#ifndef CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICKING_H_
#define CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICKING_H_

#include "../Piece.h"

class AtomicKing : public Piece {
 protected:
  explicit AtomicKing(COLOR color);

  [[nodiscard]] bool CheckCastle(int from_row_,
                                 int from_col_,
                                 int to_row_,
                                 int to_col_,
                                 const Position& position_) const;

  [[nodiscard]] bool CheckBetweenSquaresAreNotUnderAttack(int from_row_,
                                                          int from_col_,
                                                          int to_row_,
                                                          int to_col_,
                                                          const Position& position_) const;

  [[nodiscard]] static bool CheckSimpleMove(int from_row_,
                                            int from_col_,
                                            int to_row_,
                                            int to_col_,
                                            const Position& position_);

  static std::shared_ptr<AtomicKing> white_king_;
  static std::shared_ptr<AtomicKing> black_king_;

 public:
  AtomicKing(const AtomicKing&) = delete;
  void operator=(const AtomicKing&) = delete;

  static std::shared_ptr<AtomicKing> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                                                 int from_col_,
                                                 int to_row_,
                                                 int to_col_,
                                                 const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<AtomicKing> AtomicKing::white_king_ = nullptr;
inline std::shared_ptr<AtomicKing> AtomicKing::black_king_ = nullptr;

#endif //CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICKING_H_
