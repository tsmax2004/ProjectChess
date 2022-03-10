#include "headers/Position.h"

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


// TODO: make check for position_type
void Position::define_position_type() {
  position_type_ = COMMON;
}

bool Position::if_check(COLOR color) const {
  return false;
}

bool Position::if_checkmate(COLOR color) const {
  return false;
}

bool Position::if_draw(COLOR color) const {
  return false;
}

bool Position::if_stalemate(COLOR color) const {
  return false;
}