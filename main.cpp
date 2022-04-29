//
// Created by Karel Suchomel on 22.04.2022.
//
#include <game/Game.h>

int main() {
  Game game = Game("BlackJack");
  printf("________________________________\n");
  printf("    Welcome to %s\n", game.getNameOfTheGame().c_str());
  printf("________________________________\n\n");
  game.startGame();
  return 0;
}