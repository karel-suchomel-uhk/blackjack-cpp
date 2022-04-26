//
// Created by Karel Suchomel on 24.04.2022.
//

#include "Dealer.h"
#include <utility>

Dealer::Dealer(const std::string &username, Deck &deck) : Player(username), deck(deck) {}

Dealer::Dealer() = default;

// Distribute cards to dealer himself and current players.
void Dealer::dealCards(std::vector<Player> &players) {
  int round = 1;
  while(round != 3){
    this->hit(deck.drawACard(round == 1));
    for (Player& player: players) {
      player.hit(deck.drawACard());
    }
    round++;
  }
  printf("\n%s's hand: ", getUsername().c_str());
  printf("%i\n", checkHand());
  printHand();
}

Deck &Dealer::getDeck() {
  return deck;
}

// Flips the second card of dealer's hand.
void Dealer::flipCard(){
  for (Card &card: this->hand) {
    if (!card.isFaceUp()){
      card.setFaceUp(true);
    }
  }
}