//
// Created by Karel Suchomel on 24.04.2022.
//
#pragma once
#include <player/Player.h>

class Dealer: public Player{
    Deck deck;

    bool hasBlackjack = false;
  public:
    Dealer();
    Dealer(const std::string &username, Deck &deck);

    void dealCards(std::vector<Player> &playersRef);

    Deck &getDeck();

    void flipCard();
};
