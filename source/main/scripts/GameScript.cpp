#include <utility>

#include "../headers/scripts/scripts.h"

GameScript::GameScript(std::shared_ptr<GameWindow> interface) : game_logic_(), interface_(std::move(interface)) {}

void GameScript::Initialize(std::shared_ptr<GameWindow> interface) {
  if (!instance_) {
    instance_ = std::shared_ptr<GameScript>(new GameScript(std::move(interface)));
  }
}

std::shared_ptr<GameScript> GameScript::Get() {
  return instance_;
}

std::shared_ptr<Script> GameScript::Run() {
  interface_->DrawGameWindow();
  game_logic_.StartNewGame();

  bool game_cycle = true;

  while (game_cycle) {
    interface_->UpdateBoard(ConvertBoard(game_logic_.WhatBoard()));
    auto action = interface_->GetAction();
    if (action.action_type == GAME_ACTION_TYPE::MAKE_MOVE) {
      if (!game_logic_.MakeMove(action.row_from, action.col_from, action.row_to, action.col_to)) {
        interface_->InformIncorrectMove();
      } else {
        auto position_type = game_logic_.WhatPositionType();
        if (position_type == POSITION_TYPE::CHECK) { interface_->InformCheck(); }
        if (position_type == POSITION_TYPE::DRAW) {
          interface_->InformDraw();
          game_cycle = false;
        }
        if (position_type == POSITION_TYPE::CHECKMATE) {
          interface_->InformCheckmate();
          game_cycle = false;
        }
      }
    }
    if (action.action_type == GAME_ACTION_TYPE::CANCEL_MOVE) { game_logic_.CancelMove(); }
    if (action.action_type == GAME_ACTION_TYPE::EXIT_TO_MENU) {
      game_cycle = false;
    }
  }

  return MenuScript::Get();
}

std::vector<std::vector<InterfacePiece>> GameScript::ConvertBoard(const std::vector<std::vector<std::shared_ptr<Piece>>>& board) {
  std::vector<std::vector<InterfacePiece>> converted_board(8, std::vector<InterfacePiece>(8));
  for (int row = 0; row < 8; ++row) {
    for (int col = 0; col < 8; ++col) {
      auto color = board[row][col]->GetColor();
      auto piece_name = board[row][col]->GetPieceName();
      INTERFACE_COLOR interface_color = (color == COLOR::WHITE ? INTERFACE_COLOR::WHITE : INTERFACE_COLOR::BLACK);
      INTERFACE_PIECE_NAME interface_piece_name;
      switch (piece_name) {
        case PIECE_NAME::EMPTY:interface_piece_name = INTERFACE_PIECE_NAME::EMPTY;
          break;
        case PIECE_NAME::PAWN:interface_piece_name = INTERFACE_PIECE_NAME::PAWN;
          break;
        case PIECE_NAME::BISHOP:interface_piece_name = INTERFACE_PIECE_NAME::BISHOP;
          break;
        case PIECE_NAME::KNIGHT:interface_piece_name = INTERFACE_PIECE_NAME::KNIGHT;
          break;
        case PIECE_NAME::ROOK:interface_piece_name = INTERFACE_PIECE_NAME::ROOK;
          break;
        case PIECE_NAME::QUEEN:interface_piece_name = INTERFACE_PIECE_NAME::QUEEN;
          break;
        case PIECE_NAME::KING:interface_piece_name = INTERFACE_PIECE_NAME::KING;
          break;
      }
      converted_board[row][col] = {interface_piece_name, interface_color};
    }
  }
  return converted_board;
}
