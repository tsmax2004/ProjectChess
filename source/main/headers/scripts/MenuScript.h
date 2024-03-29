
#ifndef CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_MENUSCRIPT_H_
#define CHESSPROJECT_SOURCE_MAIN_HEADERS_SCRIPTS_MENUSCRIPT_H_

#include "Script.h"
#include "../../../interface/headers/windows/MenuWindow.h"

#include <memory>

class MenuScript: public Script {
 public:
  static std::shared_ptr<MenuScript> Get();
  static void Initialize(std::shared_ptr<MenuWindow>);

  std::shared_ptr<Script> Run() override;

 private:
  static std::shared_ptr<MenuScript> instance_;

  explicit MenuScript(std::shared_ptr<MenuWindow>);
  std::shared_ptr<MenuWindow> interface_;
};

inline std::shared_ptr<MenuScript> MenuScript::instance_ = nullptr;


#endif
