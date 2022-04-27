//
// Created by Karel Suchomel on 23.04.2022.
//
#pragma once
#include <deck/Deck.h>

class Player{
  protected:
    std::string username;
    bool busted = false;
    bool standing = false;
    bool hasBlackjack = false;
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
    void resetPlayerState();
    const std::vector<Card> &getHand() const;
    bool isBusted() const;
    void setBusted(bool busted);
    bool isStanding() const;
    void setStanding(bool stay);

    bool getHasBlackjack() const;

    void setHasBlackjack(bool hasBlackjack);
};