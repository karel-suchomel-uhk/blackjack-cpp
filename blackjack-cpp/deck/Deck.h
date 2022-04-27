//
// Created by Karel Suchomel on 22.04.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <card/Card.h>

class Deck {
    std::vector<Card> deck;

    void shuffleDeck();
    void printDeck();

  public:
    void initDeck();
    Deck();
    Card drawACard(bool isCardFaceUp = true);
    bool isDeckEmpty();
    int size();
};