#include "../../../configs.h"
#include "../../headers/console/windows/MenuWindowConsole.h"
#include <iostream>
#include <chrono>
#include <thread>

void MenuWindowConsole::DrawMenuWindow() {
  std::cout << "\nWelcome to ChessGame!\n";
}

MenuAction MenuWindowConsole::GetAction() {
  CleanWindow();
  std::cout << '\n';
  std::string response;
  while ((response != "N") && (response != "C") &&(response != "E")) {
    std::cout << "Game mode: " << GetGameMode() << '\n';
    std::cout << "Options: (N)ewGame, (C)hangeMode, (E)xitGame: ";
    std::cin >> response;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  if (response == "N") { return MenuAction(MENU_ACTION_TYPE::NEW_GAME); }
  if (response == "C") { return ChangeMode(); }
  if (response == "E") { return MenuAction(MENU_ACTION_TYPE::EXIT); }
  return MenuAction(MENU_ACTION_TYPE::EXIT);
}

std::string MenuWindowConsole::GetGameMode() {
  std::string mode;
  switch (GAME_MODE) {
    case GAME_MODE_TYPE::CLASSICAL:
      mode = "ClassicalMoves chess";
      break;
    case GAME_MODE_TYPE::FISCHER:
      mode = "Fischer's chess";
      break;
    case GAME_MODE_TYPE::ATOMIC:
      mode = "Atomic chess";
      break;
  }
  return mode;
}


MenuAction MenuWindowConsole::ChangeMode() {
  CleanWindow();
  std::string response;
  while ((response != "1") && (response != "2") && (response != "3")) {
    std::cout << "Choose game mode:\n";
    std::cout << "1) ClassicalMoves\n";
    std::cout << "2) Fischer's chess\n";
    std::cout << "3) Atomic chess\n";
    std::cout << " > ";
    std::cin >> response;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  if (response == "1") { return MenuAction(MENU_ACTION_TYPE::CHANGE_MODE, GAME_MODE_TYPE::CLASSICAL); }
  if (response == "2") { return MenuAction(MENU_ACTION_TYPE::CHANGE_MODE, GAME_MODE_TYPE::FISCHER); }
  if (response == "3") { return MenuAction(MENU_ACTION_TYPE::CHANGE_MODE, GAME_MODE_TYPE::ATOMIC); }

  return MenuAction(MENU_ACTION_TYPE::CHANGE_MODE, GAME_MODE_TYPE::CLASSICAL);
}

void MenuWindowConsole::CleanWindow() {
  std::cout << "\x1B[2J\x1B[H";
}
