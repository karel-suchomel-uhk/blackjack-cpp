//
// Created by Karel Suchomel on 23.04.2022.
//
#pragma once
#include <deck/Deck.h>
#include <wallet/Wallet.h>

class Player{
    Wallet wallet;
  protected:
    std::string username;
    bool busted = false;
    bool standing = false;
    bool hasBlackjack = false;
    std::vector<Card> hand;
    double betAmount;

  public:
    Player(const std::string &username, const Wallet &wallet);

    Player(const std::string &username);

    Player();

    void hit(Card card);
    void stand();
    int checkHand();
    void printHand();
    const std::string &getUsername() const;
    void resetPlayerState();
    const std::vector<Card> &getHand() const;
    bool isBusted() const;
    void setBusted(bool busted);
    bool isStanding() const;
    void setStanding(bool stay);

    double getBetAmount() const;

    void setBetAmount(double betAmount);

    Wallet &getWallet();

    bool getHasBlackjack() const;

    void setHasBlackjack(bool hasBlackjack);
};