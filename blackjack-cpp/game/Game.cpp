//
// Created by Karel Suchomel on 22.04.2022.
//

#include <game/Game.h>
#include <deck/Deck.h>
#include <utility>
#include <stdlib.h>

using namespace std;

Game::Game(const string &name) : GameLibrary(name) {}

void Game::startGame() {
  initialize();
  mainGameLoop();
}

void Game::initialize() {
  GameLibrary::startGame();
  Deck deck = Deck();
  Dealer d = Dealer("Dealer", deck);
  setDealer(d);
  initializePlayers();
}

void Game::initializePlayers() {
  string numberOfPlayer = "0";
  string *numberOfPlayersRef = &numberOfPlayer;
  int intValue = stoi(numberOfPlayer);
  bool isInputNumber = false;

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
      }else{
        printf("At least 1 player must be input!!\n");
      }
    } else {
      printf("Please enter a valid number!!\n");
    }
  } while (!isInputNumber || intValue <= 0);
}

void Game::mainGameLoop() {
  printf("\nStarting game...\n");
  dealer.dealCards(players);

  int currentPlayer = 0;
  for (Player& player: players) {
    currentPlayer++;
    printf("\n******* %s's turn *******\n", player.getUsername().c_str());
    printf("\n%s's hand: ", player.getUsername().c_str());
    printf("%i\n", player.checkHand());
    player.printHand();
    char choice = ' ';
    char* choiceRef = &choice;
    while(player.checkHand() < 21 && *choiceRef != 'S' || player.checkHand() < 21 && *choiceRef != 's'){
      choiceRef = player.presentChoice();
      if (*choiceRef == 'H' || *choiceRef == 'h'){

        player.hit(dealer.getDeck().drawACard());
      }else if(*choiceRef == 'S' || *choiceRef == 's'){
        player.stand();
      }else{
        printf("Invalid input, enter only H or S.");
      }
      printf("\n%s's hand: ", player.getUsername().c_str());
      printf("%i\n", player.checkHand());
    }
  }
  printf("******* End of Turn *******\n");
  while (dealer.checkHand() < 17)
    dealer.hit(dealer.getDeck().drawACard());
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

void Game::setDealer(Dealer dealerRef) {
  this->dealer = std::move(dealerRef);
}

void Game::checkWin() {

}
