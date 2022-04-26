//
// Created by Karel Suchomel on 23.04.2022.
//

#include <card/Card.h>

Card::Card(const Suit &cardSuit, const Value &cardValue) : cardSuit(cardSuit), cardValue(cardValue) {}

const Card::Suit &Card::getCardSuit() const {
  return cardSuit;
}

void Card::setCardSuit(const Suit &cardSuitRef) {
  Card::cardSuit = cardSuitRef;
}

const Card::Value &Card::getCardValue() const {
  return cardValue;
}

int Card::getCardIntValue() const {
  int value = 1;
  switch (cardValue) {
    case Value::Begin:
      value = 2;
      break;
    case Value::THREE:
      value = 3;
      break;
    case Value::FOUR:
      value = 4;
      break;
    case Value::FIVE:
      value = 5;
      break;
    case Value::SIX:
      value = 6;
      break;
    case Value::SEVEN:
      value = 7;
      break;
    case Value::EIGHT:
      value = 8;
      break;
    case Value::NINE:
      value = 9;
      break;
    case Value::TEN:
    case Value::JACK:
    case Value::QUEEN:
    case Value::KING:
      value = 10;
      break;
    case Value::ACE:
      value = 11;
      break;
    default:
      value = 1;
  }

  return value;
};

void Card::setCardValue(const Value &cardValueRef) {
  Card::cardValue = cardValueRef;
}

void Card::printCard() {
  std::string suitString;
  switch (cardSuit) {
    case Suit::HEARTS:
      suitString = "♥";
      break;
    case Suit::DIAMONDS:
      suitString = "♦";
      break;
    case Suit::SPADES:
      suitString = "♠";
      break;
    case Suit::CLUBS:
      suitString = "♣";
      break;
    default:
      suitString = "♣";
  }

  printf("| %i", getCardIntValue());
  printf("%s |\n", suitString.c_str());
}

Card::Suit& operator ++(Card::Suit& e)
{
  e = Card::Suit(int(e) + 1);
  return e;
}

Card::Value& operator ++(Card::Value& e)
{
  e = Card::Value(int(e) + 1);
  return e;
}

void Card::setFaceUp(bool faceUpRef) {
  Card::faceUp = faceUpRef;
}

bool Card::isFaceUp() const {
  return faceUp;
}
