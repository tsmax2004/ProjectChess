
#ifndef CHESSPROJECT_SOURCE_INTERFACE_HEADERS_WINDOWS_GAMEWINDOW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_HEADERS_WINDOWS_GAMEWINDOW_H_


#include <vector>
#include <iostream>
#include <string>

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

enum class INTERFACE_PIECE_NAME : char {
  EMPTY,
  PAWN   = 'p',
  KNIGHT = 'k',
  BISHOP = 'b',
  ROOK   = 'r',
  QUEEN  = 'q',
  KING   = 'K'
};

enum class INTERFACE_COLOR { WHITE = 'W', BLACK = 'B' };

struct InterfacePiece {
  INTERFACE_PIECE_NAME piece_name;
  INTERFACE_COLOR color;
};

class GameWindow {
 public:
  GameWindow();

  void UpdateBoard(const std::vector<std::vector<InterfacePiece>>&);
  void DrawGameWindow();

  GameAction GetAction();

  void InformIncorrectMove();
  void InformCheck();
  void InformCheckmate();
  void InformDraw();

 private:
  void PrintBoard();
  bool CheckInputCoordinate(std::string);

  std::vector<std::vector<InterfacePiece>> board;
};


#endif
