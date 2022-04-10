
#ifndef CHESSPROJECT_SOURCE_MAIN_HEADERS_MAIN_H_
#define CHESSPROJECT_SOURCE_MAIN_HEADERS_MAIN_H_

#include "scripts/scripts.h"
#include "../../interface/headers/Interface.h"

class Main {
 public:
  Main();
  void Run();

 private:
  void InitializeScripts();

  Interface interface_;
};

#endif
