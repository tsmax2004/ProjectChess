
#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "../Piece.h"

class Knight : public Piece {
 protected:
  explicit Knight(COLOR color_);

  [[nodiscard]] static bool CheckMove(int from_row_,
                                      int from_col_,
                                      int to_row_,
                                      int to_col_,
                                      const Position& position_);

  static std::shared_ptr<Knight> white_knight_;
  static std::shared_ptr<Knight> black_knight_;

 public:
  Knight(const Knight&) = delete;
  void operator=(const Knight&) = delete;

  static std::shared_ptr<Knight> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                                                 int from_col_,
                                                 int to_row_,
                                                 int to_col_,
                                                 const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<Knight> Knight::white_knight_ = nullptr;
inline std::shared_ptr<Knight> Knight::black_knight_ = nullptr;

#endif
