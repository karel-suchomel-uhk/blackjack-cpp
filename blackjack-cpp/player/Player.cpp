//
// Created by Karel Suchomel on 23.04.2022.
//

#include <player/Player.h>

#include <utility>
using namespace std;

Player::Player() = default;

Player::Player(string username) : username(std::move(username)) {}

void Player::hit(Card card) {
  this->hand.push_back(card);
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

void Player::setUsername(const std::string &usernameRef) {
  Player::username = usernameRef;
}

char* Player::presentChoice() {
  printf("Hit or Stand?\n");
  printf("Press H to hit, press S to stand.\n");
  char c = ' ';
  cin >> c;
  char* ref = &c;
  return ref;
}
