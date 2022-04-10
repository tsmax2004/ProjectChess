
#ifndef CHESSPROJECT_SOURCE_INTERFACE_HEADERS_WINDOWS_MENUWINDOW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_HEADERS_WINDOWS_MENUWINDOW_H_

enum class MENU_ACTION_TYPE {
  NEW_GAME,
  EXIT
};

struct MenuAction {
  explicit MenuAction(MENU_ACTION_TYPE menu_action_type) : action_type(menu_action_type) {}
  MENU_ACTION_TYPE action_type;
};

class MenuWindow {
 public:
  MenuWindow();
  void DrawMenuWindow();
  MenuAction GetAction();
 private:
  void CleanWindow();
};

#endif