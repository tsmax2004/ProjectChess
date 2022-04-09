#ifndef CHESSPROJECT_SOURCE_INTERFACE_LOGIC_WRAPPERS_PIECEWRAPPER_H_
#define CHESSPROJECT_SOURCE_INTERFACE_LOGIC_WRAPPERS_PIECEWRAPPER_H_
#include "../../logic/headers/Pieces/Piece.h"

class PieceWrapper {
  private:
    std::shared_ptr<Piece> piece_;
  public:
    PieceWrapper(std::shared_ptr<Piece>);
};

#endif //CHESSPROJECT_SOURCE_INTERFACE_LOGIC_WRAPPERS_PIECEWRAPPER_H_
