#include "headers/Game.h"
#include <memory>

Game::Game() : position_(nullptr),
               position_history_() {}

void Game::StartNewGame() {
  position_ = std::make_shared<Position>();
  position_->SetStartPosition();
  position_history_.push_back(position_);
}

bool Game::MakeMove(int from_row, int from_col, int to_row, int to_col) {
  auto move = position_->at(from_row, from_col)->DefineMove(from_row, from_col, to_row, to_col, *position_);
  if (!move->IsValid()) { return false; }

  auto new_position = std::make_shared<Position>(*position_);
  move->MakeMove(from_row, from_col, to_row, to_col, *new_position);
  new_position->DefinePositionType();
  if (new_position->position_type_ == POSITION_TYPE::INVALID) { return false; }

  position_ = new_position;
  position_history_.push_back(position_);
  return true;
}

bool Game::CancelMove() {
  if (position_history_.size() <= 1) { return false; }
  position_ = position_history_[position_history_.size() - 1];
  position_history_.pop_back();
  return true;
}

const std::vector<std::vector<std::shared_ptr<Piece>>>& Game::WhatBoard() const {
  return position_->board_;
}

POSITION_TYPE Game::WhatPositionType() const {
  return position_->position_type_;
}

COLOR Game::WhatColor() const {
  return position_->move_color_;
}

bool Game::SetPosition(const std::vector<std::vector<std::shared_ptr<Piece>>>& board, COLOR color) {
  auto new_position = std::make_shared<Position>();
  new_position->SetPosition(board, color);
  new_position->DefinePositionType();
  if (new_position->position_type_ == POSITION_TYPE::NOT_DEFINED) { return false; }
  position_ = new_position;
  position_history_.clear();
  position_history_.push_back(position_);
  return true;
}

bool Game::CheckForRepeating() const {
  size_t cnt_of_moves = position_history_.size();
  int pos_count = 0;
  auto first_position = position_history_[cnt_of_moves - 1];
  for (size_t j = 0; j < cnt_of_moves - 1; ++j) {
    bool is_equal = true;
    auto second_position = position_history_[j];
    for (int row = 0; row < first_position->board_.size(); ++row) {
      if (is_equal) {
        for (int col = 0; col < first_position->board_[row].size(); ++col) {
          if (first_position->at(row, col)->GetPieceName() != second_position->at(row, col)->GetPieceName() ||
          (first_position->at(row, col)->GetColor() != second_position->at(row, col)->GetColor()
          && first_position->at(row, col)->GetPieceName() != PIECE_NAME::EMPTY)) {
            is_equal = false;
            break;
          }
        }
      }
    }
    pos_count += is_equal;
  }
  if (pos_count >= 2) { return true; }
  return false;
}

std::shared_ptr<Position> Game::GetPosition() {
    return position_;
}
