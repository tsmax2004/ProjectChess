#include "headers/Game.h"
#include <iostream>
#include <string>
#include <memory>

Game::Game() : position_(nullptr),
               position_history_() {}

void Game::StartNewGame() {
  position_ = new Position();
  position_->StartPosition();
  GameCycle();
  std::string ans;
  while ((ans != "y") && (ans != "n")) {
    std::cout << "Do you want play again? (y/n): ";
    std::cin >> ans;
  }
  if (ans == "y")
    StartNewGame();
  if (ans == "n") std::cout << "Thank you for the game!";
}

void Game::GameCycle() {
  while (true) {
    PrintBoard();
    std::cout << "Print move: ";
    char from_col_ch, to_col_ch;
    int from_row, to_row, from_col, to_col;
    std::cin >> from_col_ch >> from_row >> to_col_ch >> to_row;
    from_col = from_col_ch - 'a';
    --from_row;
    to_col = to_col_ch - 'a';
    --to_row;

    try {
      auto move = position_->at(from_row, from_col)->DefineMove(from_row, from_col, to_row, to_col, *position_);
      if (!move->IsValid()) {
        std::cout << "Incorrect move\n";
        continue;
      }

      auto* new_position = new Position(*position_);
      move->MakeMove(from_row, from_col, to_row, to_col, *new_position);
      new_position->DefinePositionType();
      if (new_position->position_type_ == POSITION_TYPE::INVALID) {
        std::cout << "Incorrect move\n";
        continue;
      }

      position_history_.push_back(position_);
      position_ = new_position;

      if (position_->position_type_ == POSITION_TYPE::CHECK) {
        PrintBoard();
        std::cout << "CHECK!\n";
      }
      if (position_->position_type_ == POSITION_TYPE::CHECKMATE) {
        PrintBoard();
        std::cout << "CHECKMATE!\n";
        break;
      }
      if (position_->position_type_ == POSITION_TYPE::DRAW) {
        PrintBoard();
        std::cout << "DRAW!\n";
        break;
      }
      if (CheckForRepeating()) {
        PrintBoard();
        std::cout << "DRAW by repeating moves!\n";
        break;
      }
    } catch (std::out_of_range&) {
      std::cout << "Incorrect coordinates\n";
      continue;
    }
  }
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
  if (pos_count >= 2) return true;
  return false;
}

void Game::PrintBoard() const {
  std::cout << "\n\n";
  for (int row = 8; row >= 1; --row) {
    std::cout << "      ";
    for (int col = 0; col < 8; ++col)
      std::cout << "---- ";

    std::cout << "\n  " << row << "  ";
    for (int col = 0; col < 8; ++col) {
      std::cout << "| ";
      auto piece = position_->at(row - 1, col);
      if (piece->GetPieceName() == PIECE_NAME::EMPTY) {
        std::cout << "  ";
      } else {
        std::cout << char(piece->GetColor()) << char(piece->GetPieceName());
      }
      std::cout << " ";
    }

    std::cout << "|\n";
  }

  std::cout << "      ";
  for (int col = 0; col < 8; ++col)
    std::cout << "---- ";

  std::cout << "\n       a    b    c    d    e    f    g    h\n\n";
}
