//
// Created by Георгий Кузнецов on 01.05.2022.
//

#ifndef CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICROOK_H_
#define CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICROOK_H_

#include "../Piece.h"

class AtomicRook : public Piece {
 protected:
  explicit AtomicRook(COLOR color_);

  [[nodiscard]] static bool CheckMove(int from_row_,
                                      int from_col_,
                                      int to_row_,
                                      int to_col_,
                                      const Position& position_);

  static std::shared_ptr<AtomicRook> white_rook_;
  static std::shared_ptr<AtomicRook> black_rook_;

 public:
  AtomicRook(const AtomicRook&) = delete;
  void operator=(const AtomicRook&) = delete;

  static std::shared_ptr<AtomicRook> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                                                 int from_col_,
                                                 int to_row_,
                                                 int to_col_,
                                                 const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<AtomicRook> AtomicRook::white_rook_ = nullptr;
inline std::shared_ptr<AtomicRook> AtomicRook::black_rook_ = nullptr;

#endif //CHESSPROJECT_SOURCE_LOGIC_HEADERS_ATOMICPIECES_ATOMICROOK_H_
