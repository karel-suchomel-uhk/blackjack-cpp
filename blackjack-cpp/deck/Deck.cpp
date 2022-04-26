//
// Created by Karel Suchomel on 22.04.2022.
//
#include <deck/Deck.h>
#include <algorithm>
#include <random>

using namespace std;

Deck::Deck() {
  initDeck();
}

void Deck::initDeck() {
  printf("Deck created\n");
  shuffleDeck();
//  printDeck();
}

void Deck::shuffleDeck() {
  deck.clear();
  for (Card::Value i = Card::Value::Begin; i != Card::Value::End; ++i) {
    for (Card::Suit j = Card::Suit::Begin; j != Card::Suit::End; ++j) {
      Card card(j, i);
      deck.push_back(card);
    }
  }

  random_device rd;
  auto rng = default_random_engine {rd()};

  shuffle(deck.begin(), deck.end(), rng);
}

void Deck::printDeck() {
  for (Card card: deck) {
    card.printCard();
  }
}

Card Deck::drawACard(bool isCardFaceUp) {
  Card topCard = deck.front();
  if (!isCardFaceUp){
    topCard.setFaceUp(false);
  }
  deck.erase(deck.begin());
  return topCard;
}

bool Deck::isDeckEmpty() {
  return deck.empty();
}
