//
// Created by Karel Suchomel on 24.04.2022.
//

#include "Dealer.h"
#include <utility>

Dealer::Dealer(const std::string &username, Deck &deck) : Player(username), deck(deck) {}

void Dealer::dealCards(std::vector<Player> &players) {
  this->hit(deck);
  this->hit(deck);
  printf("\n%s's hand: \n", getUsername().c_str());
  printHand();
  for (Player player: players) {
    player.hit(deck);
    player.hit(deck);
    printf("\n%s's hand: ", player.getUsername().c_str());
    printf("%i\n", player.checkHand());
    player.printHand();
  }
}

Deck &Dealer::getDeck() const {
  return deck;
}


