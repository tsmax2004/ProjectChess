
#ifndef CHESSPROJECT_SOURCE_INTERFACE_HEADERS_WINDOWS_MENUWINDOW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_HEADERS_WINDOWS_MENUWINDOW_H_

#include "../../../configs.h"

enum class MENU_ACTION_TYPE {
  NEW_GAME,
  CHANGE_MODE,
  EXIT
};

struct MenuAction {
  explicit MenuAction(MENU_ACTION_TYPE menu_action_type) : action_type(menu_action_type), mode() {}
  MenuAction(MENU_ACTION_TYPE menu_action_type, GAME_MODE_TYPE mode): action_type(menu_action_type), mode(mode) {}
  MENU_ACTION_TYPE action_type;
  GAME_MODE_TYPE mode;
};

class MenuWindow {
 public:
  virtual void DrawMenuWindow() = 0;
  virtual MenuAction GetAction() = 0;
};

#endif