//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_MENUWINDOW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_MENUWINDOW_H_

#include "Window.h"

class MenuWindow : public Window{
 private:
  static std::shared_ptr<MenuWindow> instance_;
  MenuWindow();
 public:
  static std::shared_ptr<MenuWindow> GetInstance();
  void Draw(std::shared_ptr<PositionWrapper>) override;
  std::shared_ptr<Action> GetAction() override;
};

inline std::shared_ptr<MenuWindow> MenuWindow::instance_ = nullptr;
#endif
