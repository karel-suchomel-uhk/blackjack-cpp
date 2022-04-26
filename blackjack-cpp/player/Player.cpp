//
// Created by Karel Suchomel on 23.04.2022.
//

#include <player/Player.h>

#include <utility>
using namespace std;

Player::Player() = default;

Player::Player(string username) : username(std::move(username)) {}

// For taking a card from a deck
void Player::hit(Card card) {
  this->hand.push_back(card);
}

// Stay function, does nothing
void Player::stand() {}

// Returns the total of player's hand
int Player::checkHand() {
  int sum = 0;
  for (Card &card: this->hand) {
    if (card.isFaceUp()){
      sum += card.getCardIntValue();
    }
  }

  return sum;
}

// Displays player's hand to teh screen
void Player::printHand() {
  for (Card &card: this->hand) {
    if (card.isFaceUp()){
      card.printCard();
    }else{
      printf("| XX |\n");
    }
  }
}

const std::string &Player::getUsername() const {
  return username;
}

// Presents user with game choices. H (hit) / S (stay)
char Player::presentChoice() {
  printf("Hit or Stand?\n");
  printf("Press H to hit, press S to stand.\n");
  char c;
  cin >> c;
  char upperCased = toupper(c);
  return upperCased;
}

const vector<Card> &Player::getHand() const {
  return hand;
}

bool Player::isBusted() const {
  return busted;
}

void Player::setBusted(bool bustedRef) {
  Player::busted = bustedRef;
}

void Player::resetPlayerState() {
  this->busted = false;
  this->hand.clear();
}
