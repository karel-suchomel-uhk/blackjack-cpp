//
// Created by Karel Suchomel on 23.04.2022.
//
#pragma once
#include <deck/Deck.h>

class Player{
    std::string username;
  protected:
    std::vector<Card> hand;

  public:
    explicit Player(std::string username);

    Player();

    void hit(Card card);
    void stand();
    int checkHand();
    virtual void printHand();
    char presentChoice();
    const std::string &getUsername() const;

    const std::vector<Card> &getHand() const;

    void setUsername(const std::string &username);
};