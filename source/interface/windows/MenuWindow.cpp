#include "../headers/windows/MenuWindow.h"
#include <iostream>
#include <chrono>
#include <thread>

MenuWindow::MenuWindow() = default;

void MenuWindow::DrawMenuWindow() {
  std::cout << "\nWelcome to ChessGame!\n";
}

MenuAction MenuWindow::GetAction() {
  CleanWindow();
  std::cout << '\n';
  std::string response;
  while ((response != "N") && (response != "E")) {
    std::cout << "Options: (N)ew Game, (E)xitGame: ";
    std::cin >> response;
  }
  if (response == "N") {
    return MenuAction(MENU_ACTION_TYPE::NEW_GAME);
  }
  if (response == "E") {
    return MenuAction(MENU_ACTION_TYPE::EXIT);
  }
}

void MenuWindow::CleanWindow() {
  std::cout << "\x1B[2J\x1B[H";
}
