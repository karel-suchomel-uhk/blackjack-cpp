//
// Created by Karel Suchomel on 22.04.2022.
//

#include <game/Game.h>
#include <deck/Deck.h>

#include <utility>

using namespace std;

Game::Game(const string &name) : GameLibrary(name) {}

void Game::startGame() {
  initialize();
}

void Game::initialize() {
  int numberOfPlayer;
  GameLibrary::startGame();
  Deck deck = Deck();
  Dealer dealer = Dealer("Dealer", deck);
  printf("How many player's are going to play? ");
  cin >> numberOfPlayer;
  for (int i = 0; i < numberOfPlayer; i++) {
    createPlayer();
  }
  printPlayers();
  dealer.dealCards(players);

}

void Game::createDealer(Deck &deck) {
  Dealer dealer = Dealer("Dealer", deck);
}

void Game::createPlayer() {
  string userName;
  printf("Select player's name: ");
  cin >> userName;
  Player p = Player(userName);
  players.push_back(p);
}

void Game::printPlayers() {
  int index = 1;
  printf("\n");
  index++;
  for (Player &player: players) {
    printf("%d. ", index);
    printf("%s\n", player.getUsername().c_str());
    index++;
  }
}