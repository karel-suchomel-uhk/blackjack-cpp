//
// Created by Karel Suchomel on 23.04.2022.
//
#pragma once
#include <deck/Deck.h>

class Player{
    std::string username;
    std::vector<Card> hand;

  public:
    explicit Player(std::string username);

    void hit(Deck &deck);
    void stand();
    int checkHand();
    void printHand();

    const std::string &getUsername() const;

    void setUsername(const std::string &username);
};