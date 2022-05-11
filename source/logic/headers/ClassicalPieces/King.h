
#ifndef King_H_
#define King_H_

#include "../Piece.h"

class King : public Piece {
 protected:
  explicit King(COLOR color);

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

  static std::shared_ptr<King> white_king_;
  static std::shared_ptr<King> black_king_;

 public:
  King(const King&) = delete;
  void operator=(const King&) = delete;

  static std::shared_ptr<King> GetPiece(COLOR color);

  [[nodiscard]] std::shared_ptr<Move> DefineMove(int from_row_,
                                                 int from_col_,
                                                 int to_row_,
                                                 int to_col_,
                                                 const Position& position_) const override;

  [[nodiscard]] PIECE_NAME GetPieceName() const override;
};

inline std::shared_ptr<King> King::white_king_ = nullptr;
inline std::shared_ptr<King> King::black_king_ = nullptr;

#endif
