//
// Created by Георгий Кузнецов on 09.04.2022.
//

#ifndef CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_WINDOW_H_
#define CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_WINDOW_H_

#include "../include_interface_logic.h"

class Window {
 public:
  Window();
  virtual void Draw(PositionWrapper*);
  virtual Action* GetAction();
  virtual void Rehearse();
  ~Window();
 private:
  //sf::ReferenceWindow& window_
  //sf::Color background_color_
  //sf::Font font_
  //sf::Color font_color_
};

#endif //CHESSPROJECT_SOURCE_INTERFACE_INTERFACE_WINDOW_H_
