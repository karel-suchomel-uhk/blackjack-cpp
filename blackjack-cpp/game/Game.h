
//
// Created by Karel Suchomel on 22.04.2022.
//
#pragma once

#include <iostream>
#include <string>
#include <GameLibrary.h>
#include <player/Player.h>
#include "dealer/Dealer.h"
//#include <deck/Deck.h>

class Game: public GameLibrary {
    std::vector<Player> players;

    void createDealer(Deck& deck);
    void createPlayer();
    void initialize();
    void printPlayers();
  public:

    explicit Game(const std::string &name);

    void startGame() override;
};