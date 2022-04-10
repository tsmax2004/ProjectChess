
#ifndef CHESSPROJECT_SOURCE_INTERFACE_HEADERS_WINDOWS_GAMEWINDOW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_HEADERS_WINDOWS_GAMEWINDOW_H_

class GameWindow {
 public:
  GameWindow();

 private:
};

enum class GAME_ACTION_TYPE {
  MAKE_MOVE,
  CANCEL_MOVE,
  EXIT_TO_MENU
};

struct GameAction {
  GameAction(GAME_ACTION_TYPE action_type): action_type(action_type) {}
  GameAction(GAME_ACTION_TYPE action_type, int row_from, int col_from, int row_to, int col_to):
    action_type(action_type), row_from(row_from), col_from(col_from), row_to(row_to), col_to(col_to) {}

  GAME_ACTION_TYPE action_type;
  int row_from = 0, col_from = 0, row_to = 0, col_to = 0;
};

#endif
