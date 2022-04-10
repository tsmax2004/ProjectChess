#include "../headers/wrappers/wrappers.h"


PositionWrapper::PositionWrapper(std::shared_ptr<Position> position) : position_(position) {};
POSITION_TYPE PositionWrapper::GetPositionType() {
    return position_->position_type_;
}

std::shared_ptr<PieceWrapper> PositionWrapper::at(int row, int col) {
    return std::make_shared<PieceWrapper>(PieceWrapper(position_->at(row, col)));
}

std::pair<int, int> PositionWrapper::GetBoardSize() {
    return std::make_pair(position_->board_.size(), position_->board_[0].size());
}

void PositionWrapper::UpdatePosition(std::shared_ptr<Position> position) {
    position_ = position;
}