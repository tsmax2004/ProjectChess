#include "../headers/wrappers/PieceWrapper.h"

#include <utility>

PieceWrapper::PieceWrapper(std::shared_ptr<Piece> piece) {
  piece_ = std::move(piece);
}

PIECE_NAME PieceWrapper::GetPieceName() {
  return piece_->GetPieceName();
}
COLOR PieceWrapper::GetPieceColor() {
  return piece_->GetColor();
}