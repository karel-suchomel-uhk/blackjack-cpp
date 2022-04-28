
//
// Created by Karel Suchomel on 22.04.2022.
//
#pragma once

#include <iostream>
#include <string>
#include <GameLibrary.h>
#include <UtilFunctions.h>
#include <player/Player.h>
#include <dealer/Dealer.h>
#include <cctype>

class Game: public GameLibrary {
    std::vector<Player> players;
    Dealer dealer;

    void createPlayer();
    void initialize();
    void printPlayers();
    void initializePlayers();
    void mainGameLoop() override;
    void checkWin();
    char presentChoice();
    void collectBets();

  public:

    explicit Game(const std::string &name);
    void startGame() override;
    void restartGame();
    void setDealer(Dealer dealer);
};