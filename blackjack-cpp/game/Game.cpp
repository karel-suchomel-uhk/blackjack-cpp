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

  for (Player& player: players) {
    printf("\n******* %s's turn *******\n", player.getUsername().c_str());
    printf("\n%s's hand: ", player.getUsername().c_str());
    printf("%i\n", player.checkHand());
    player.printHand();
    char choice;

    if (player.checkHand() == 21){
      printf("%s: ", player.getUsername().c_str());
      printf("BLACKJACK!!! \n");
    }else{
      while(player.checkHand() <= 21 && choice != 'S') {
        choice = player.presentChoice();
        if (choice == 'H') {
          Card drawnCard = dealer.getDeck().drawACard();
          if (drawnCard.getCardIntValue() == 11) {
            drawnCard.setCardValue(Card::Value::Begin);
          }
          player.hit(drawnCard);
          if (player.checkHand() > 21){
            printf("%s: ", player.getUsername().c_str());
            printf("BUST \n");
          }
        } else if (choice == 'S') {
          player.stand();
        } else {
          printf("Invalid input, enter only H or S.");
        }
        printf("\n%s's hand: ", player.getUsername().c_str());
        printf("%i\n", player.checkHand());
      }
    }

    choice = ' ';
    printf("******* End of %s's turn *******\n", player.getUsername().c_str());
  }
  printf("\n\n******* End of Game *******\n\n");
  dealer.flipCard();
  while (dealer.checkHand() < 17){
    dealer.hit(dealer.getDeck().drawACard());
  }
  if (dealer.checkHand() > 21){
    dealer.setBusted(true);
  }

  printf("Results: \n");
  checkWin();
}

void Game::checkWin() {
  printf("%s's hand: ", dealer.getUsername().c_str());
  printf("%i\n", dealer.checkHand());
  dealer.printHand();
  int dealersHand = dealer.checkHand();
  if (dealer.isBusted()){
    printf("Dealer BUSTED!!");
  }else{
    for (Player& player: players) {
      int playerHand = player.checkHand();
      printf("\n%s's hand: ", player.getUsername().c_str());
      printf("%i\n", player.checkHand());

      if (playerHand == dealersHand) {
        // SAME HAND TOTAL -> PUSH
        printf("%s: ", player.getUsername().c_str());
        printf("PUSH \n");
      }else if(playerHand == 21 && dealersHand != 21){
        // PlAYERS HAND EQUAL 21 -> BLACKJACK
        printf("%s: ", player.getUsername().c_str());
        printf("BLACKJACK!!! \n");
      }else if (playerHand > 21){
        // PlAYERS HAND OVER 21 -> BUST
        printf("%s: ", player.getUsername().c_str());
        printf("BUST \n");
      }else if(dealersHand > 21){
        // DEALERS HAND OVER 21 -> BUST
        printf("Dealer: ");
        printf("BUST \n");
      }else if(playerHand > dealersHand && playerHand != 21) {
        // PlAYERS HAND OVER DEALERS -> WIN
        printf("%s: ", player.getUsername().c_str());
        printf("WIN!! \n");
      }else if(dealersHand > playerHand){
        // DEALERS HAND OVER PLAYERS -> LOSE
        printf("%s: ", player.getUsername().c_str());
        printf("LOSE !! \n");
      }
    }
  }

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
