//
// Created by Георгий Кузнецов on 09.04.2022.
//

#include <iostream>
#include "../headers/windows/GameWindow.h"

GameWindow::GameWindow() = default;

std::shared_ptr<Action> GameWindow::GetAction() {
  std::string input;
  std::cin >> input;
  //check if we try: "surrender" or "offer draw"
  if (input.size() > 2) {
    if (input == "surrender") {
      std::shared_ptr<Surrender> surrender;
      surrender = surrender->GetInstance();
      return std::static_pointer_cast<Action>(surrender);
    }
    /*else if (input == "draw") {
      std::shared_ptr<OfferDraw> draw;
      draw = draw->GetInstance();
      return std::static_pointer_cast<Action>(draw);
    }*/
  }
}

std::shared_ptr<GameWindow> GameWindow::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = std::shared_ptr<GameWindow>(new GameWindow());
  }
  return instance_;
}

void GameWindow::Draw(PositionWrapper* position_wrapper) {
    std::cout << "\n\n";
    for (int row = 8; row >= 1; --row) {
      std::cout << "      ";
      for (int col = 0; col < 8; ++col)
        std::cout << "---- ";

      std::cout << "\n  " << row << "  ";
      for (int col = 0; col < 8; ++col) {
        std::cout << "| ";
        auto piece = position_wrapper->at(row - 1, col);
        if (piece->GetPieceName() == PIECE_NAME::EMPTY) {
          std::cout << "  ";
        } else {
          std::cout << char(piece->GetPieceColor()) << char(piece->GetPieceName());
        }
        std::cout << " ";
      }

      std::cout << "|\n";
    }

    std::cout << "      ";
    for (int col = 0; col < 8; ++col)
      std::cout << "---- ";

    std::cout << "\n       a    b    c    d    e    f    g    h\n\n";
}
