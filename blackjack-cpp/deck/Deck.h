//
// Created by Karel Suchomel on 22.04.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <card/Card.h>

class Deck {
    std::vector<Card> deck;

    void initDeck();
    void shuffleDeck();

  public:
    Deck();

    void printDeck();
    Card drawACard();
    bool isDeckEmpty();
};