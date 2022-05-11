//
// Created by Георгий Кузнецов on 01.05.2022.
//

#ifndef CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICKNIGHT_H_
#define CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICKNIGHT_H_

#include "../Piece.h"

class AtomicKnight : public Piece {
 protected:
  explicit AtomicKnight(COLOR color_);

  [[nodiscard]] static bool CheckMove(int from_row_,
                                      int from_col_,
                                      int to_row_,
                                      int to_col_,
                                      const Position& position_);

  static std::shared_ptr<AtomicKnight> white_knight_;
  static std::shared_ptr<AtomicKnight> black_knight_;

 public:
  AtomicKnight(const AtomicKnight&) = delete;
  void operator=(const AtomicKnight&) = delete;

  static std::shared_ptr<AtomicKnight> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                                                 int from_col_,
                                                 int to_row_,
                                                 int to_col_,
                                                 const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<AtomicKnight> AtomicKnight::white_knight_ = nullptr;
inline std::shared_ptr<AtomicKnight> AtomicKnight::black_knight_ = nullptr;

#endif //CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICKNIGHT_H_
