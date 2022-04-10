#include "PieceWrapper.h"

PieceWrapper::PieceWrapper(std::shared_ptr<Piece> piece) : piece_(piece) {};

PIECE_NAME PieceWrapper::GetPieceName() {
  return piece_->GetPieceName();
}
COLOR PieceWrapper::GetPieceColor() {
  return piece_->GetColor();
}