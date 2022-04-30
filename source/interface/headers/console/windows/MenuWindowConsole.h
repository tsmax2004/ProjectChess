#ifndef CHESSPROJECT_SOURCE_INTERFACE_HEADERS_CONSOLE_WINDOWS_MENUWINDOWCONSOLE_H_
#define CHESSPROJECT_SOURCE_INTERFACE_HEADERS_CONSOLE_WINDOWS_MENUWINDOWCONSOLE_H_

#include "../../windows/MenuWindow.h"
#include <string>

class MenuWindowConsole: public MenuWindow {
 public:
  void DrawMenuWindow() override;
  MenuAction GetAction() override;
 private:
  MenuAction ChangeMode();
  std::string GetGameMode();
  void CleanWindow();
};

#endif //CHESSPROJECT_SOURCE_INTERFACE_HEADERS_CONSOLE_WINDOWS_MENUWINDOWCONSOLE_H_
