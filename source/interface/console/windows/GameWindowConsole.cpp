#include "../../headers/console/windows/GameWindowConsole.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "../../../configs.h"


void GameWindowConsole::DrawGameWindow() {
  std::cout << "\n\nHave a good game!\n";
}

GameAction GameWindowConsole::GetAction() {
  CleanWindow();
  PrintBoard();
  std::string response;
  while ((response != "M") && (response != "C") && (response != "E")) {
    std::cout << "Options: (M)akeMove, (C)ancelMove, (E)xitToMenu: ";
    std::cin >> response;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    int row_from, col_from, row_to, col_to;
    col_from = from[0] - 'a';
    col_to = to[0] - 'a';
    row_from = from[1] - '1';
    row_to = to[1] - '1';
    return GameAction(GAME_ACTION_TYPE::MAKE_MOVE, row_from, col_from, row_to, col_to);
  }
  return GameAction(GAME_ACTION_TYPE::EXIT_TO_MENU);
}

bool GameWindowConsole::CheckInputCoordinate(std::string inp) {
  if (inp.size() != 2) { return false; }
  char col = inp[0];
  if ((col < 'a') || (col > 'h')) { return false; }
  char row = inp[1];
  if ((row < '1') || (row > '8')) { return false; }
  return true;
}

void GameWindowConsole::InformIncorrectMove() {
  std::cout << "Move is incorrect!\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

void GameWindowConsole::InformCheck() {
  std::cout << "Check!\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

void GameWindowConsole::InformCheckmate() {
  std::cout << "Checkmate!\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "Thank you for game!\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

void GameWindowConsole::InformDraw() {
  std::cout << "Draw!\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "Thank you for game!\n";
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

void GameWindowConsole::PrintBoard() {
  std::cout << "\n\n";
  for (int row = CNT_ROWS; row >= 1; --row) {
    std::cout << "      ";
    for (int col = 0; col < CNT_COLS; ++col) { std::cout << "---- "; }

    std::cout << "\n  " << row << "  ";
    for (int col = 0; col < CNT_COLS; ++col) {
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
  for (int col = 0; col < CNT_COLS; ++col) { std::cout << "---- "; }

  std::cout << "\n       a    b    c    d    e    f    g    h\n\n";
}

void GameWindowConsole::CleanWindow() {
  std::cout << "\x1B[2J\x1B[H";
}
