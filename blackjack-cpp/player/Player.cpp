//
// Created by Karel Suchomel on 23.04.2022.
//

#include <player/Player.h>

#include <utility>
using namespace std;

Player::Player(const string &username, const Wallet &wallet) : username(username), wallet(wallet) {}

Player::Player(const string &username) : username(username) {}

Player::Player() {}

// For taking a card from a deck
void Player::hit(Card card) {
  this->hand.push_back(card);
}

// For skipping user round without taking a new card.
void Player::stand() {
  setStanding(true);
}

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
  this->standing = false;
  this->hasBlackjack = false;
  this->hand.clear();
}

bool Player::isStanding() const {
  return standing;
}

void Player::setStanding(bool standRef) {
  Player::standing = standRef;
}

bool Player::getHasBlackjack() const {
  return hasBlackjack;
}

void Player::setHasBlackjack(bool hasBlackjackRef) {
  Player::hasBlackjack = hasBlackjackRef;
}

double Player::getBetAmount() const {
  return betAmount;
}

void Player::setBetAmount(double betAmountRef) {
  Player::betAmount = betAmountRef;
}

Wallet &Player::getWallet() {
  return wallet;
}
