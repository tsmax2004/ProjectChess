#ifndef CHESSPROJECT_SOURCE_MAIN_H_
#define CHESSPROJECT_SOURCE_MAIN_H_

#include "logic/headers/logic.h"

class Main {
 public:
  Main();                                 // Создает Main, Interface, Game, вызывает Run()

  void Run();                             // Запускает меню

  void StartGame();                       // Метод, который вызывает интерфейс, если пользователь из меню хочет начать игру
  void MakeMove(int, int, int, int);      // Метод, который вызывает интерфейс, если пользователь сделал ход
  void CancelMove();                      // Метод, который вызывает интерфейс, если пользователь отменил послдений ход
  void DeclareDraw();                     // Метод, который вызывает интерфейс, если пользователь объвил ничью
  void DeclareGivingUp();                 // Метод. который вызывает интерфейс, если пользователь сдаётся

  void Exit()                             // Выход из игры, удаляет интерфейс и логику

 private:
  void MenuCycle();                       // Менюшный цикл, отсюда можно выйти из игры, начать игру (т.е. войти в игровой цикл)
  void GameCycle();                       // Игровой цикл, отсюда можно выйти в меню

  Game game_logic_;
  Interface interface_;
};

#endif //CHESSPROJECT_SOURCE_MAIN_H_
