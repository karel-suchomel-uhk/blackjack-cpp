//
// Created by Karel Suchomel on 23.04.2022.
//

#include <player/Player.h>

#include <utility>
using namespace std;

Player::Player(string username) : username(std::move(username)) {}

void Player::hit(Deck &deck) {
  this->hand.push_back(deck.drawACard());
}

void Player::stand() {}

int Player::checkHand() {
  int sum = 0;
  for (auto i: this->hand) {
    sum += i.getCardIntValue();
  }

  return sum;
}

void Player::printHand() {
  for (Card card: this->hand) {
    card.printCard();
  }
}

const std::string &Player::getUsername() const {
  return username;
}

void Player::setUsername(const std::string &username) {
  Player::username = username;
}
