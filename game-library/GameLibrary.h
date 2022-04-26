//
// Created by Karel Suchomel on 22.04.2022.
//
#pragma once

#include <iostream>
#include <string>

class GameLibrary {
  std::string nameOfTheGame;

  public:
    explicit GameLibrary(const std::string &name);

    virtual void startGame();

    const std::string &getNameOfTheGame() const;

    void setNameOfTheGame(const std::string &nameOfTheGame);

    virtual void mainGameLoop();
};