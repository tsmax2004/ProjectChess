#ifndef CHESSPROJECT_SOURCE_INTERFACE_HEADERS_CONSOLE_WINDOWS_GAMEWINDOWCONSOLE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_HEADERS_CONSOLE_WINDOWS_GAMEWINDOWCONSOLE_H_

#include "../../windows/GameWindow.h"

class GameWindowConsole: public GameWindow {
 public:
  void DrawGameWindow() override;

  GameAction GetAction() override;

  void InformIncorrectMove() override;
  void InformCheck() override;
  void InformCheckmate() override;
  void InformDraw() override;

 private:
  void CleanWindow();
  void PrintBoard();
  bool CheckInputCoordinate(std::string);
};

#endif //CHESSPROJECT_SOURCE_INTERFACE_HEADERS_CONSOLE_WINDOWS_GAMEWINDOWCONSOLE_H_
