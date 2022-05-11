//
// Created by Георгий Кузнецов on 01.05.2022.
//

#ifndef CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICQUEEN_H_
#define CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICQUEEN_H_

#include "../Piece.h"

class AtomicQueen : public Piece {
 protected:
  explicit AtomicQueen(COLOR color_);

  [[nodiscard]] static bool CheckMove(int from_row_,
                                      int from_col_,
                                      int to_row_,
                                      int to_col_,
                                      const Position& position_);

  static std::shared_ptr<AtomicQueen> white_queen_;
  static std::shared_ptr<AtomicQueen> black_queen_;

 public:
  AtomicQueen(const AtomicQueen&) = delete;
  void operator=(const AtomicQueen&) = delete;

  static std::shared_ptr<AtomicQueen> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                                                 int from_col_,
                                                 int to_row_,
                                                 int to_col_,
                                                 const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<AtomicQueen> AtomicQueen::white_queen_ = nullptr;
inline std::shared_ptr<AtomicQueen> AtomicQueen::black_queen_ = nullptr;

#endif //CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICQUEEN_H_
