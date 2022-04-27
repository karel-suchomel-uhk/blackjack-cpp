//
// Created by Karel Suchomel on 23.04.2022.
//
#pragma once
#include <generate_to_string.h>
#include <iostream>
#include <string>

class Card {
  public:
    enum class Suit {
      Begin, HEARTS = Begin, CLUBS, SPADES, DIAMONDS, End
    };
    enum class Value {
      Begin, TWO = Begin, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
      JACK, QUEEN, KING, ACE, End
    };

    GENERATE_TO_STRING(Suit, HEARTS, CLUBS, SPADES, DIAMONDS, End);
    GENERATE_TO_STRING(Value, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
                       JACK, QUEEN, KING, ACE, End);

    Card(const Suit &cardSuit, const Value &cardValue);

    const Suit &getCardSuit() const;

    const Value &getCardValue() const;

    int getCardIntValue() const;

    void setCardIntValue(int cardIntValue);

    void printCard();

    bool isFaceUp() const;

    void setFaceUp(bool faceUp);

    friend Suit &operator++(Suit &e);

    friend Value &operator++(Value &e);
  private:
    Suit cardSuit;
    Value cardValue;
    int cardIntValue = 0;
    bool faceUp = true;
};