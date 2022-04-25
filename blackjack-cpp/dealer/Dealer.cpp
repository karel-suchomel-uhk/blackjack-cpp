//
// Created by Karel Suchomel on 24.04.2022.
//

#include "Dealer.h"
#include <utility>

Dealer::Dealer(const std::string &username, Deck &deck) : Player(username), deck(deck) {}

Dealer::Dealer() = default;

void Dealer::dealCards(std::vector<Player> &players) {
  this->hit(deck.drawACard());
  this->hit(deck.drawACard());
  printf("\n%s's hand: \n", getUsername().c_str());
  printHand();
  for (Player& player: players) {
    player.hit(deck.drawACard());
    player.hit(deck.drawACard());
  }
}

Deck &Dealer::getDeck() {
  return deck;
}