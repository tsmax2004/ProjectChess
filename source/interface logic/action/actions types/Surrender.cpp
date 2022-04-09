//
// Created by Георгий Кузнецов on 09.04.2022.
//

#include "Surrender.h"
Surrender::Surrender() = default;

std::shared_ptr<Surrender> Surrender::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = std::shared_ptr<Surrender>(new Surrender());
  }
  return instance_;
}

void Surrender::GetAction(std::shared_ptr<Game> logic_) {
  logic_ -> Surrender();
}