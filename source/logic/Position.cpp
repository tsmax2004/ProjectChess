#include <stdexcept>
#include <set>
#include <fstream>
#include <memory>
#include "headers/logic.h"
#include "headers/Position.h"

Position::Position() : board_(),
                       move_color_(COLOR::WHITE),
                       position_type_(POSITION_TYPE::NOT_DEFINED),
                       info_for_castle_(),
                       last_move_() {}

Position::Position(const Position&) = default;

void Position::SetStartPosition() {
  std::ifstream inp("logic/configs/start_position.txt");
  SetBoard(inp);
  move_color_ = COLOR::WHITE;
  position_type_ = POSITION_TYPE::COMMON;
  info_for_castle_ = std::vector<bool>(6, true);
}

void Position::SetBoard(std::ifstream& inp) {
  board_ = std::vector<std::vector<std::shared_ptr<Piece>>>(8, std::vector<std::shared_ptr<Piece>>(8, nullptr));
  for (int row = cnt_rows - 1; row >= 0; --row) {
    for (int col = 0; col < cnt_cols; ++col) {
      char color_char, piece_char;
      inp >> color_char >> piece_char;
      COLOR color = (color_char == 'W' ? COLOR::WHITE : COLOR::BLACK);
      std::shared_ptr<Piece> piece = Empty::GetPiece();
      switch (piece_char) {
        case 'p':piece = Pawn::GetPiece(color);
          break;
        case 'b':piece = Bishop::GetPiece(color);
          break;
        case 'k':piece = Knight::GetPiece(color);
          break;
        case 'r':piece = Rook::GetPiece(color);
          break;
        case 'q':piece = Queen::GetPiece(color);
          break;
        case 'K':piece = King::GetPiece(color);
          break;
        default:break;
      }
      board_[row][col] = piece;
    }
  }
}

std::shared_ptr<Piece> Position::at(int row, int col) const {
  if ((row < 0) || (row >= 8) || (col < 0) || (col >= 8)) {
    throw std::out_of_range("invalid coordinates input");
  }
  return board_[row][col];
}

bool Position::SquareIsUnderAttack(int row, int col, COLOR attack_color) const {
  auto tmp_position(*this);
  tmp_position.move_color_ = attack_color;
  for (int i = 0; i < board_.size(); ++i) {
    for (int j = 0; j < board_[i].size(); ++j) {
      if ((board_[i][j]->GetPieceName() != PIECE_NAME::EMPTY) && (board_[i][j]->GetColor() == attack_color)) {
        auto move = board_[i][j]->DefineMove(i, j, row, col, tmp_position);
        if (move->IsValid()) { return true; }
      }
    }
  }
  return false;
}

void Position::DefinePositionType() {
  position_type_ = POSITION_TYPE::COMMON;
  if (Check(move_color_ == COLOR::WHITE ? COLOR::BLACK : COLOR::WHITE)) {
    position_type_ = POSITION_TYPE::CHECK;
    if (Checkmate(move_color_ == COLOR::WHITE ? COLOR::BLACK : COLOR::WHITE))
      position_type_ = POSITION_TYPE::CHECKMATE;
  } else if (Draw() || Stalemate()) {
    position_type_ = POSITION_TYPE::DRAW;
  }
}

bool Position::Check(COLOR attack_color) const {
  std::vector<int> king_coord = FindKing(attack_color == COLOR::WHITE ? COLOR::BLACK : COLOR::WHITE);
  int king_row = king_coord[0];
  int king_col = king_coord[1];
  return SquareIsUnderAttack(king_row, king_col, attack_color);
}

bool Position::Checkmate(COLOR attack_color) const {
  for (int row = 0; row < board_.size(); ++row) {
    for (int col = 0; col < board_[row].size(); ++col) {
      if ((board_[row][col]->GetPieceName() != PIECE_NAME::EMPTY) && (board_[row][col]->GetColor() != attack_color)) {
        auto piece = board_[row][col];
        for (int to_row = 0; to_row < board_.size(); ++to_row) {
          for (int to_col = 0; to_col < board_[to_row].size(); ++to_col) {
            auto tmp_position = Position(*this);
            auto move = piece->DefineMove(row, col, to_row, to_col, tmp_position);
            if (move->IsValid()) {
              move->MakeMove(row, col, to_row, to_col, tmp_position);
              if (!tmp_position.Check(attack_color)) { return false; }
            }
          }
        }
      }
    }
  }
  return true;
}

bool Position::Draw() const {
  std::vector<int> white_bishops(2);
  std::vector<int> black_bishops(2);
  std::set<PIECE_NAME> white_pieces;
  std::set<PIECE_NAME> black_pieces;
  for (int row = 0; row < board_.size(); ++row) {
    for (int col = 0; col < board_[row].size(); ++col) {
      if (at(row, col)->GetColor() == COLOR::BLACK) {
        if (at(row, col)->GetPieceName() == PIECE_NAME::BISHOP) { ++black_bishops[(row + col) % 2]; }
        if (at(row, col)->GetPieceName() != PIECE_NAME::EMPTY) { black_pieces.insert(at(row, col)->GetPieceName()); }
      } else {
        if (at(row, col)->GetPieceName() == PIECE_NAME::BISHOP) { ++white_bishops[(row + col) % 2]; }
        if (at(row, col)->GetPieceName() != PIECE_NAME::EMPTY) { white_pieces.insert(at(row, col)->GetPieceName()); }
      }
    }
  }
  if (white_pieces == std::set{PIECE_NAME::KING} && black_pieces == std::set{PIECE_NAME::KING}) return true;
  if (white_pieces == std::set{PIECE_NAME::KING, PIECE_NAME::KNIGHT} && black_pieces == std::set{PIECE_NAME::KING}
      || black_pieces == std::set{PIECE_NAME::KING, PIECE_NAME::KNIGHT}
          && white_pieces == std::set{PIECE_NAME::KING}) { return true; }
  if (white_pieces == std::set{PIECE_NAME::KING, PIECE_NAME::BISHOP} && black_pieces == std::set{PIECE_NAME::KING}
      || black_pieces == std::set{PIECE_NAME::KING, PIECE_NAME::BISHOP}
          && white_pieces == std::set{PIECE_NAME::KING}) { return true; }
  if (white_pieces == std::set{PIECE_NAME::KING, PIECE_NAME::BISHOP}
      && black_pieces == std::set{PIECE_NAME::KING, PIECE_NAME::BISHOP}
      && white_bishops == black_bishops) { return true; }
  return false;
}

bool Position::Stalemate() const {
  for (int from_row = 0; from_row < board_.size(); ++from_row) {
    for (int from_col = 0; from_col < board_[from_row].size(); ++from_col) {
      if ((at(from_row, from_col)->GetPieceName() != PIECE_NAME::EMPTY)
          && (at(from_row, from_col)->GetColor() == move_color_)) {
        auto piece = at(from_row, from_col);
        for (int to_row = 0; to_row < board_.size(); ++to_row) {
          for (int to_col = 0; to_col < board_[to_row].size(); ++to_col) {
            auto move = piece->DefineMove(from_row, from_col, to_row, to_col, *this);
            if (move->IsValid()) {
              auto new_pos = Position(*this);
              move->MakeMove(from_row, from_col, to_row, to_col, new_pos);
              if (!new_pos.Check(move_color_ == COLOR::WHITE ? COLOR::BLACK : COLOR::WHITE)) {
                return false;
              }
            }
          }
        }
      }
    }
  }
  return true;
}

std::vector<int> Position::FindKing(COLOR attack_color) const {
  for (int row = 0; row < board_.size(); ++row) {
    for (int col = 0; col < board_[row].size(); ++col) {
      if ((board_[row][col]->GetPieceName() == PIECE_NAME::KING) && (board_[row][col]->GetColor() == attack_color)) {
        return {row, col};
      }
    }
  }
  return {0, 0};
}