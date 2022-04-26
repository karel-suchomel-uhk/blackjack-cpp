//
// Created by Karel Suchomel on 22.04.2022.
//

#include "GameLibrary.h"
using namespace std;

GameLibrary::GameLibrary(const std::string &name) : nameOfTheGame(name) {}

const std::string &GameLibrary::getNameOfTheGame() const {
  return nameOfTheGame;
}

void GameLibrary::setNameOfTheGame(const std::string &nameOfTheGame) {
  GameLibrary::nameOfTheGame = nameOfTheGame;
}

void GameLibrary::startGame() {
  printf("Starting game...\n");
}

void GameLibrary::mainGameLoop() {
  printf("\nMissing main game loop\n");
}
