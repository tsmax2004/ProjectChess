#include "headers/Game.h"
#include <iostream>
#include <string>

Game::Game() : position_(nullptr),
               position_history_() {}

void Game::start_new_game() {
  position_ = new Position();
  position_->start_position();
  std::cout << "Do you want to start a new game?[y/n/set]: ";
  std::string ans;
  std::cin >> ans;
  if (ans == "y") {
    game_cycle();
  } else if (ans == "set") {
    for (auto & row : position_->board_) {
      for (auto & piece : row) {
        piece = Empty::get_piece();
      }
    }
    print_board(position_->move_color_);
    std::cout << "\nEnter pieces by: '+' col row color piece name(ex Empty)\n";
    char end, col;
    std::cin >> end;
    int row;
    std::string color, piece_name;
    COLOR piece_color;
    while (end != '#') {
      std::cin >> col >> row >> color >> piece_name;
      col -= 'a';
      --row;
      if (color == "w") piece_color = WHITE;
      if (color == "b") piece_color = BLACK;
      if (piece_name == "p") position_->board_[row][col] = Pawn::get_piece(piece_color);
      if (piece_name == "n") position_->board_[row][col] = Knight::get_piece(piece_color);
      if (piece_name == "b") position_->board_[row][col] = Bishop::get_piece(piece_color);
      if (piece_name == "r") position_->board_[row][col] = Rook::get_piece(piece_color);
      if (piece_name == "q") position_->board_[row][col] = Queen::get_piece(piece_color);
      if (piece_name == "k") position_->board_[row][col] = King::get_piece(piece_color);
      print_board(position_->move_color_);
      std::cout << "For end type '#'\n";
      std::cin >> end;
    }
    game_cycle();
  }
  ans.clear();
  while ((ans != "y") && (ans != "n")) {
    std::cout << "Do you want play again? (y/n): ";
    std::cin >> ans;
  }
  if (ans == "y")
    start_new_game();
  if (ans == "n") std::cout << "Thank you for the game!";
}

void Game::game_cycle() {
  while (true) {
    print_board(position_->move_color_);
    std::cout << "Print move: ";
    char from_col_ch, to_col_ch;
    int from_row, to_row, from_col, to_col;
    std::cin >> from_col_ch >> from_row >> to_col_ch >> to_row;
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

      auto* new_position = new Position(*position_);
      move->make_move(from_row, from_col, to_row, to_col, *new_position);
      new_position->define_position_type();
      if (new_position->position_type_ == INVALID) {
        std::cout << "Incorrect move\n";
        continue;
      }

      position_history_.push_back(position_);
      position_ = new_position;
      if (position_->position_type_ == CHECK) {
        print_board(position_->move_color_);
        std::cout << "CHECK!\n";
      }
      if (position_->position_type_ == CHECKMATE) {
        print_board(position_->move_color_);
        std::cout << "CHECKMATE!\n";
        break;
      }
      if (position_->position_type_ == DRAW) {
        print_board(position_->move_color_);
        std::cout << "DRAW!\n";
        break;
      }
      if (position_->position_type_ == STALEMATE) {
        print_board(position_->move_color_);
        std::cout << "STALEMATE!\n";
        break;
      }
      if (check_for_repeating()) {
        print_board(position_->move_color_);
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
  int pos_count = 0;
  auto first_position = position_history_[cnt_of_moves - 1];
  for (size_t j = 0; j < cnt_of_moves - 1; ++j) {
    bool is_equal = true;
    auto second_position = position_history_[j];
    for (int row = 0; row < first_position->board_.size(); ++row) {
      if (is_equal) {
        for (int col = 0; col < first_position->board_[row].size(); ++col) {
          if (first_position->at(row, col)->get_piece_name() != second_position->at(row, col)->get_piece_name() ||
              (first_position->at(row, col)->get_color() != second_position->at(row, col)->get_color()
                  && first_position->at(row, col)->get_piece_name() != EMPTY)) {
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

void Game::print_board(COLOR color) const {
  std::cout << "\n\n";
  for (int row = 8; row >= 1; --row) {
    std::cout << "      ";
    for (int col = 0; col < 8; ++col)
      std::cout << "---- ";
    if (color == WHITE) std::cout << "\n  " << row << "  ";
    else std::cout << "\n  " << 9 - row << "  ";
    for (int col = 0; col < 8; ++col) {
      std::cout << "| ";
      Piece* piece = nullptr;
      if (color == WHITE) piece = position_->at(row - 1, col);
      else piece = position_->at(8-row, 7 - col);
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

  if (color == WHITE) std::cout << "\n       a    b    c    d    e    f    g    h\n\n";
  else  std::cout << "\n       h    g    f    e    d    c    b    a\n\n";
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