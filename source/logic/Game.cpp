#include "headers/Game.h"
#include <iostream>
#include <string>

Game::Game() : position_(nullptr),
               position_history_() {}

void Game::start_new_game() {
  position_ = new Position();
  position_->start_position();
  game_cycle();
  std::string ans;
  while ((ans != "y") && (ans != "n")) {
    std::cout << "Do you want play again? (y/n): ";
    std::cin >> ans;
  }
  if (ans == "y")
    start_new_game();
}

void Game::game_cycle() {
  while (true) {
    print_board();
    std::cout << "Print move: ";
    int from_row, from_col, to_row, to_col;
    std::cin >> from_row >> from_col >> to_row >> to_col;
    --from_row;
    --from_col;
    --to_row;
    --to_col;
    try {
      const Move* move = position_->at(from_row, from_col)->define_move(from_row, from_col, to_row, to_col, *position_);
      if (!move->is_valid()) {
        std::cout << "Incorrect move\n";
        continue;
      }

      Position* new_position = new Position(*position_);
      move->make_move(from_row, from_col, to_row, to_col, *new_position);
      if (new_position->position_type_ == INVALID) {
        std::cout << "Incorrect move\n";
        continue;
      }

      position_history_.push_back(position_);
      position_ = new_position;

      if (position_->position_type_ == CHECKMATE) {
        std::cout << "CHECKMATE!\n";
        break;
      }
      if (position_->position_type_ == DRAW) {
        std::cout << "DRAW!\n";
        break;
      }
      if (position_->position_type_ == STALEMATE) {
        std::cout << "STALEMATE!\n";
        break;
      }
      if (check_for_repeating()) {
        std::cout << "DRAW by repeating moves!\n";
        break;
      }
    } catch (std::out_of_range&) {
      std::cout << "Incorrect coordinates\n";
      continue;
    }
  }
}

bool Game::check_for_repeating() const {
  size_t cnt_of_moves = position_history_.size();
  if (cnt_of_moves < 5) {
    return false;
  }
  if ((position_history_[cnt_of_moves - 1] == position_history_[cnt_of_moves - 3])
      && (position_history_[cnt_of_moves - 3] == position_history_[cnt_of_moves - 5]))
    return true;
  return false;
}

void Game::print_board() const {
  std::cout << "\n\n";
  for (int row = 8; row >= 1; --row) {
    std::cout << "       ";
    for (int col = 0; col < 8; ++col)
      std::cout << "---- ";

    std::cout << "\n      ";
    for (int col = 0; col < 8; ++col)
      std::cout << "|    ";

    std::cout << "|\n  " << row << "   ";
    for (int col = 0; col < 8; ++col) {
      std::cout << "| ";
      Piece* piece = position_->at(row - 1, col);
      if (piece->get_piece_name() == EMPTY) {
        std::cout << "  ";
      } else {
        std::cout << piece->get_color() << piece->get_piece_name();
      }
      std::cout << " ";
    }

    std::cout << "|\n      ";
    for (int col = 0; col < 8; ++col)
      std::cout << "|    ";
    std::cout << "|\n";
  }

  std::cout << "       ";
  for (int col = 0; col < 8; ++col)
    std::cout << "---- ";

  std::cout << "\n        a    b    c    d    e    f    g    h\n\n";
}




//       ---- ---- ---- ---- ---- ---- ---- ----
//      |    |    |    |    |    |    |    |    |
//  8   | Br | Bk | Bb | Bq | BK | Bb | Bk | Br |
//      |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//      |    |    |    |    |    |    |    |    |
//  7   | Bp | Bp | Bp | Bp | Bp | Bp | Bp | Bp |
//      |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//      |    |    |    |    |    |    |    |    |
//  6   |    |    |    |    |    |    |    |    |
//      |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//      |    |    |    |    |    |    |    |    |
//  5   |    |    |    |    |    |    |    |    |
//      |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//      |    |    |    |    |    |    |    |    |
//  4   |    |    |    |    |    |    |    |    |
//      |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//      |    |    |    |    |    |    |    |    |
//  3   |    |    |    |    |    |    |    |    |
//      |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//      |    |    |    |    |    |    |    |    |
//  2   | Wp | Wp | Wp | Wp | Wp | Wp | Wp | Wp |
//      |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//      |    |    |    |    |    |    |    |    |
//  1   | Wr | Wk | Wb | Wq | WK | Wb | Wk | Wr |
//      |    |    |    |    |    |    |    |    |
//       ---- ---- ---- ---- ---- ---- ---- ----
//
//        a    b    c    d    e    f    g    h