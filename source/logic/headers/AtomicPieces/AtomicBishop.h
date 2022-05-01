//
// Created by Георгий Кузнецов on 01.05.2022.
//

#ifndef CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICBISHOP_H_
#define CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICBISHOP_H_

#include "../Piece.h"

class AtomicBishop : public Piece {
 protected:
  explicit AtomicBishop(COLOR color_);

  [[nodiscard]] static bool CheckMove(int from_row_,
                                      int from_col_,
                                      int to_row_,
                                      int to_col_,
                                      const Position& position_);

  static std::shared_ptr<AtomicBishop> white_bishop_;
  static std::shared_ptr<AtomicBishop> black_bishop_;

 public:
  AtomicBishop(const AtomicBishop&) = delete;
  void operator=(const AtomicBishop&) = delete;

  static std::shared_ptr<AtomicBishop> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                                                 int from_col_,
                                                 int to_row_,
                                                 int to_col_,
                                                 const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<AtomicBishop> AtomicBishop::white_bishop_ = nullptr;
inline std::shared_ptr<AtomicBishop> AtomicBishop::black_bishop_ = nullptr;


#endif //CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICBISHOP_H_
