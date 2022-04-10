#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_WRAPPERS_PIECEWRAPPER_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_WRAPPERS_PIECEWRAPPER_H_
#include "../../../logic/headers/Pieces/Piece.h"

class PieceWrapper {
  private:
    static std::shared_ptr<Piece> piece_;
  public:
    explicit PieceWrapper(std::shared_ptr<Piece>);
    static PIECE_NAME GetPieceName();
    static COLOR GetPieceColor();
};

#endif
