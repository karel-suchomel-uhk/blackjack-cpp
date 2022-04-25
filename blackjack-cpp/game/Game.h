
//
// Created by Karel Suchomel on 22.04.2022.
//
#pragma once

#include <iostream>
#include <string>
#include <GameLibrary.h>
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
    static bool isNumber(const std::string& str);
    void mainGameLoop();
    void checkWin();

  public:

    explicit Game(const std::string &name);

    void startGame() override;

    void setDealer(Dealer dealer);
};