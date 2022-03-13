#include <stdexcept>
#include "headers/logic.h"

Position::Position(): board_(),
                      move_color_(WHITE),
                      position_type_(NOT_DEFINE),
                      info_for_castle_(),
                      last_move_(),
                      move_cnt_(0) {}

Position::Position(const Position& other) = default;

bool Position::operator==(const Position& other) const {
  return board_ == other.board_;
}

void Position::start_position() {
  board_ = std::vector<std::vector<Piece*>>(8, std::vector<Piece*>(8, nullptr));
  board_[0][0] = Rook::get_piece(WHITE);
  board_[7][0] = Rook::get_piece(BLACK);
  board_[0][1] = Knight::get_piece(WHITE);
  board_[7][1] = Knight::get_piece(BLACK);
  board_[0][2] = Bishop::get_piece(WHITE);
  board_[7][2] = Bishop::get_piece(BLACK);
  board_[0][3] = Queen::get_piece(WHITE);
  board_[7][3] = Queen::get_piece(BLACK);
  board_[0][4] = King::get_piece(WHITE);
  board_[7][4] = King::get_piece(BLACK);
  board_[0][5] = Bishop::get_piece(WHITE);
  board_[7][5] = Bishop::get_piece(BLACK);
  board_[0][6] = Knight::get_piece(WHITE);
  board_[7][6] = Knight::get_piece(BLACK);
  board_[0][7] = Rook::get_piece(WHITE);
  board_[7][7] = Rook::get_piece(BLACK);

  for (int col = 0; col < 8; ++col) {
    board_[1][col] = Pawn::get_piece(WHITE);
    board_[6][col] = Pawn::get_piece(BLACK);
    for (int row = 2; row < 6; ++row)
      board_[row][col] = Empty::get_piece();
  }

  move_color_ = WHITE;
  position_type_ = COMMON;
  info_for_castle_ = std::vector<bool>(6, true);
  move_cnt_ = 1;
}

Piece* Position::at(int row, int col) const {
  if ((row < 0) || (row >= 8) || (col < 0) || (col >= 8))
    throw std::out_of_range("invalid coordinates input");

  return board_[row][col];
}

bool Position::if_square_is_under_attack(int row, int col, COLOR attack_color) const {
  auto tmp_position(*this);
  tmp_position.move_color_ = attack_color;
  for (int i = 0; i < board_.size(); ++i) {
    for (int j = 0; j < board_[i].size(); ++j) {
      if ((board_[i][j]->get_piece_name() != EMPTY) && (board_[i][j]->get_color() == attack_color)) {
        const Move* move = board_[i][j]->define_move(i, j, row, col, tmp_position);
        if (move->is_valid())
          return true;
      }
    }
  }
  return false;
}

// TODO: make check for position_type
void Position::define_position_type() {
  position_type_ = COMMON;
  if (if_check(move_color_ == WHITE ? BLACK : WHITE)) {
    position_type_ = CHECK;
    if (if_checkmate(move_color_ == WHITE ? BLACK : WHITE))
      position_type_ = CHECKMATE;
  } else if (if_draw() || if_stalemate()) {
    position_type_ = DRAW;
  }
}

bool Position::if_check(COLOR attack_color) const {
  std::vector<int> king_coord = find_king(attack_color == WHITE ? BLACK : WHITE);
  int king_row = king_coord[0];
  int king_col = king_coord[1];
  return if_square_is_under_attack(king_row, king_col, attack_color);
}

bool Position::if_checkmate(COLOR attack_color) const {
  for (int row = 0; row < board_.size(); ++row) {
    for (int col = 0; col < board_[row].size(); ++col) {
      if ((board_[row][col]->get_piece_name() != EMPTY) && (board_[row][col]->get_color() != attack_color)) {
        auto piece = board_[row][col];
        for (int to_row = 0; to_row < board_.size(); ++to_row) {
          for (int to_col = 0; to_col < board_[to_row].size(); ++to_col) {
            auto tmp_position = Position(*this);
            auto move = piece->define_move(row, col, to_row, to_col, tmp_position);
            if (move->is_valid()) {
              move->make_move(row, col, to_row, to_col, tmp_position);
              if (!tmp_position.if_check(attack_color))
                return false;
            }
          }
        }
      }
    }
  }
  return true;
}

bool Position::if_draw() const {
  return false;
}

bool Position::if_stalemate() const {
  return false;
}

std::vector<int> Position::find_king(COLOR color) const {
  for (int row = 0; row < board_.size(); ++row) {
    for (int col = 0; col < board_[row].size(); ++col) {
      if ((board_[row][col]->get_piece_name() == KING) && (board_[row][col]->get_color() == color)) {
        return {row, col};
      }
    }
  }
  return {0, 0};
}
