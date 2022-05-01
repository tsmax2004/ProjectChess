
#ifndef BISHOP_H_
#define BISHOP_H_

#include "../Piece.h"

class Bishop : public Piece {
 protected:
  explicit Bishop(COLOR color_);

  [[nodiscard]] static bool CheckMove(int from_row_,
                                      int from_col_,
                                      int to_row_,
                                      int to_col_,
                                      const Position& position_);

  static std::shared_ptr<Bishop> white_bishop_;
  static std::shared_ptr<Bishop> black_bishop_;

 public:
  Bishop(const Bishop&) = delete;
  void operator=(const Bishop&) = delete;

  static std::shared_ptr<Bishop> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                                                 int from_col_,
                                                 int to_row_,
                                                 int to_col_,
                                                 const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<Bishop> Bishop::white_bishop_ = nullptr;
inline std::shared_ptr<Bishop> Bishop::black_bishop_ = nullptr;

#endif
