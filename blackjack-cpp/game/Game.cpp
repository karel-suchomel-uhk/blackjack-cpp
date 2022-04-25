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
  string numberOfPlayer = "0";
  string *numberOfPlayersRef = &numberOfPlayer;
  int intValue = stoi(numberOfPlayer);
  bool isInputNumber = false;

  GameLibrary::startGame();
  Deck deck = Deck();
  Dealer dealer = Dealer("Dealer", deck);

  do {
    printf("How many player's are going to play? ");
    cin >> *numberOfPlayersRef;
    isInputNumber = isNumber(*numberOfPlayersRef);
    if (isInputNumber) {
      intValue = stoi(*numberOfPlayersRef);

      if (intValue > 0) {
        for (int i = 0; i < intValue; i++) {
          createPlayer();
        }
        printPlayers();
        dealer.dealCards(players);
      }else{
        printf("At least 1 player must be input!!\n");
      }
    } else {
      printf("Please enter a valid number!!\n");
    }
  } while (!isInputNumber || intValue <= 0);
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
  for (Player &player: players) {
    printf("%d. ", index);
    printf("%s\n", player.getUsername().c_str());
    index++;
  }
}

bool Game::isNumber(const string &s) {
  bool hitDecimal = false;
  for (char c: s) {
    if (c == '.' && !hitDecimal) // 2 '.' in string mean invalid
      hitDecimal = true; // first hit here, we forgive and skip
    else if (!isdigit(c))
      return false; // not ., not
  }
  return true;
}