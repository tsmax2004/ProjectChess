
#ifndef CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_SCRIPT_H_
#define CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_SCRIPT_H_

#include <memory>

class Script {
 public:
  virtual std::shared_ptr<Script> Run() = 0;

 private:
};

#endif //CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_SCRIPT_H_
