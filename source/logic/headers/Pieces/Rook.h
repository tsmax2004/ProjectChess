
#ifndef ROOK_H_
#define ROOK_H_

#include "Piece.h"

class Rook : public Piece {
 protected:
  explicit Rook(COLOR color_);

  [[nodiscard]] static bool CheckMove(int from_row_,
                                      int from_col_,
                                      int to_row_,
                                      int to_col_,
                                      const Position& position_);

  static std::shared_ptr<Rook> white_rook_;
  static std::shared_ptr<Rook> black_rook_;

 public:
  Rook(const Rook&) = delete;
  void operator=(const Rook&) = delete;

  static std::shared_ptr<Rook> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                                                 int from_col_,
                                                 int to_row_,
                                                 int to_col_,
                                                 const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<Rook> Rook::white_rook_ = nullptr;
inline std::shared_ptr<Rook> Rook::black_rook_ = nullptr;

#endif
