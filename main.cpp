//
// Created by Karel Suchomel on 22.04.2022.
//
#include <iostream>
#include <game/Game.h>
#include <cstdio>

using namespace std;

int main() {
  Game game = Game("BlackJack");
  printf("_____________________________\n");
  printf("    Welcome to %s\n", game.getNameOfTheGame().c_str());
  printf("_____________________________\n\n");
  game.startGame();
  return 0;
}