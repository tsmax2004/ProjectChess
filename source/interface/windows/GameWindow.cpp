#include "../headers/windows/GameWindow.h"
#include <chrono>
#include <thread>

GameWindow::GameWindow() = default;
void GameWindow::UpdateBoard(const std::vector<std::vector<InterfacePiece>>& new_board) {
  board = new_board;
}

void GameWindow::DrawGameWindow() {
  std::cout << "\n\nHave a good game!\n";
}

GameAction GameWindow::GetAction() {
  CleanWindow();
  PrintBoard();
  std::string response;
  while ((response != "M") && (response != "C") && (response != "E")) {
    std::cout << "Options: (M)akeMove, (C)ancelMove, (E)xitToMenu: ";
    std::cin >> response;
  }
  if (response == "C") {
    return GameAction(GAME_ACTION_TYPE::CANCEL_MOVE);
  } else if (response == "E") {
    return GameAction(GAME_ACTION_TYPE::EXIT_TO_MENU);
  } else if (response == "M") {
    std::string from, to;
    while (!CheckInputCoordinate(from) || !CheckInputCoordinate(to)) {
      std::cout << "Input move in standard chess format (e.g. e2 e4): ";
      std::cin >> from >> to;
    }
    int row_from, col_from, row_to, col_to;
    col_from = from[0] - 'a';
    col_to = to[0] - 'a';
    row_from = from[1] - '1';
    row_to = to[1] - '1';
    return GameAction(GAME_ACTION_TYPE::MAKE_MOVE, row_from, col_from, row_to, col_to);
  }
}

bool GameWindow::CheckInputCoordinate(std::string inp) {
  if (inp.size() != 2) { return false; }
  char col = inp[0];
  if ((col < 'a') || (col > 'h')) { return false; }
  char row = inp[1];
  if ((row < '1') || (row > '8')) { return false; }
  return true;
}

void GameWindow::InformIncorrectMove() {
  std::cout << "Move is incorrect!\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

void GameWindow::InformCheck() {
  std::cout << "Check!\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

void GameWindow::InformCheckmate() {
  std::cout << "Checkmate!\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

void GameWindow::InformDraw() {
  std::cout << "Draw!\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

void GameWindow::PrintBoard() {
  std::cout << "\n\n";
  for (int row = 8; row >= 1; --row) {
    std::cout << "      ";
    for (int col = 0; col < 8; ++col) { std::cout << "---- "; }

    std::cout << "\n  " << row << "  ";
    for (int col = 0; col < 8; ++col) {
      std::cout << "| ";
      auto piece = board[row - 1][col];
      if (piece.piece_name == INTERFACE_PIECE_NAME::EMPTY) {
        std::cout << "  ";
      } else {
        std::cout << char(piece.color) << char(piece.piece_name);
      }
      std::cout << " ";
    }

    std::cout << "|\n";
  }

  std::cout << "      ";
  for (int col = 0; col < 8; ++col) { std::cout << "---- "; }

  std::cout << "\n       a    b    c    d    e    f    g    h\n\n";
}

void GameWindow::CleanWindow() {
  std::cout << "\x1B[2J\x1B[H";
}
