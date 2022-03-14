#include "headers/Game.h"
#include <iostream>
#include <string>
#include <fstream>

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
  if (ans == "n") std::cout << "Thank you for the game!";
}

void debug(Position* position) {
  for (int from_row = 0; from_row < position->board_.size(); ++from_row) {
    for (int from_col = 0; from_col < position->board_[from_row].size(); ++from_col) {
      std::cout << "On Square: " << char(from_col + 'a') << from_row+1 << " -- ";
      if (position->at(from_row, from_col)->get_piece_name() != EMPTY){
        std::cout << position->at(from_row, from_col)->get_color() << position->at(from_row, from_col)->get_piece_name() << " -- {";
        for (int to_row = 0; to_row < position->board_.size(); ++to_row) {
          for (int to_col = 0; to_col < position->board_[to_row].size(); ++to_col) {
            const Move* move = position->at(from_row, from_col)->define_move(from_row, from_col, to_row, to_col, *position);
            if (move->is_valid()) std::cout << '(' << to_row+1 << ", " << char(to_col+'a') << "), ";
          }
        }
        std::cout << "#}\n";
      }
      else std::cout << "EMPTY\n";
    }
  }
}

void Game::game_cycle() {
  std::ifstream inp("../moves.txt");
  while (true) {
    print_board();
    std::cout << "Print move: ";
    char from_col_ch, to_col_ch;
    int from_row, to_row, from_col, to_col;
    inp >> from_col_ch >> from_row >> to_col_ch >> to_row;
    if (from_col_ch == '!')
      break;
    from_col = from_col_ch - 'a';
    --from_row;
    to_col = to_col_ch - 'a';
    --to_row;
    try {
      const Move* move = position_->at(from_row, from_col)->define_move(from_row, from_col, to_row, to_col, *position_);
      if (!move->is_valid()) {
        std::cout << "Incorrect move\n";
        continue;
      }

      Position* new_position = new Position(*position_);
      move->make_move(from_row, from_col, to_row, to_col, *new_position);
      new_position->define_position_type();
      if (new_position->position_type_ == INVALID) {
        std::cout << "Incorrect move\n";
        continue;
      }

      position_history_.push_back(position_);
      position_ = new_position;

      if (position_->position_type_ == CHECK) {
        print_board();
        if (position_ -> position_type_ == CHECKMATE) std::cout << "CHECKMATE!\n";
        else std::cout << "CHECK!\n";
        break;
      }
      if (position_->position_type_ == DRAW) {
        print_board();
        std::cout << "DRAW!\n";
        break;
      }
      if (position_->position_type_ == STALEMATE) {
        print_board();
        std::cout << "STALEMATE!\n";
        break;
      }
      if (check_for_repeating()) {
        print_board();
        std::cout << "DRAW by repeating moves!\n";
        break;
      }
      debug(Game::position_);
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
    std::cout << "      ";
    for (int col = 0; col < 8; ++col)
      std::cout << "---- ";

    std::cout << "\n  " << row << "  ";
    for (int col = 0; col < 8; ++col) {
      std::cout << "| ";
      Piece* piece = position_->at(row - 1, col);
      if (piece->get_piece_name() == EMPTY) {
        std::cout << "  ";
      } else {
        std::cout << char(piece->get_color()) << char(piece->get_piece_name());
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




//      ---- ---- ---- ---- ---- ---- ---- ----
//  8  | Br | Bk | Bb | Bq | BK | Bb | Bk | Br |
//      ---- ---- ---- ---- ---- ---- ---- ----
//  7  | Bp | Bp | Bp | Bp | Bp | Bp | Bp | Bp |
//      ---- ---- ---- ---- ---- ---- ---- ----
//  6  |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//  5  |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//  4  |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//  3  |    |    |    |    |    |    |    |    |
//      ---- ---- ---- ---- ---- ---- ---- ----
//  2  | Wp | Wp | Wp | Wp | Wp | Wp | Wp | Wp |
//      ---- ---- ---- ---- ---- ---- ---- ----
//  1  | Wr | Wk | Wb | Wq | WK | Wb | Wk | Wr |
//      ---- ---- ---- ---- ---- ---- ---- ----
//       a    b    c    d    e    f    g    h