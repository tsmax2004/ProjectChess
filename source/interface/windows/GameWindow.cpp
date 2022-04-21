#include "../headers/windows/GameWindow.h"

void GameWindow::UpdateBoard(const std::vector<std::vector<InterfacePiece>>& new_board) {
  board = new_board;
}
