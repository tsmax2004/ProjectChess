#ifndef CHESSPROJECT_SOURCE_CONFIGS_H_
#define CHESSPROJECT_SOURCE_CONFIGS_H_

#include <string>

enum class INTERFACE_TYPE {
  CONSOLE
};

enum class GAME_MODE_TYPE {
  CLASSICAL,
  FISHER,
  CRAZY
};

static INTERFACE_TYPE INTERFACE = INTERFACE_TYPE::CONSOLE;
inline GAME_MODE_TYPE GAME_MODE = GAME_MODE_TYPE::CLASSICAL;
static int CNT_ROWS = 8;
static int CNT_COLS = 8;

#endif //CHESSPROJECT_SOURCE_CONFIGS_H_
