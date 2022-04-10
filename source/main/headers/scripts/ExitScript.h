
#ifndef CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_EXITSCRIPT_H_
#define CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_EXITSCRIPT_H_

#include "Script.h"

class ExitScript: public Script {
 public:
  static std::shared_ptr<ExitScript> Get();
  static void Initialize();

  std::shared_ptr<Script> Run() override;

 private:
  static std::shared_ptr<ExitScript> instance_;

  ExitScript();
};

inline std::shared_ptr<ExitScript> ExitScript::instance_ = nullptr;

#endif
