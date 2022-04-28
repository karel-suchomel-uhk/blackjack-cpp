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

// Initializes game objects
void Game::initialize() {
  GameLibrary::startGame();
  Deck deck = Deck();
  Dealer d = Dealer("Dealer", deck);
  setDealer(d);
  initializePlayers();
}

// Creates players for current game sessions
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
      } else {
        printf("At least 1 player must be input!!\n");
      }
    } else {
      printf("Please enter a valid number!!\n");
    }
  } while (!isInputNumber || intValue <= 0);
}

// Game loop
void Game::mainGameLoop() {
  printPlayers();
  int turns = 0;
  int round = 1;
  printf("\nStarting game...\n");
  collectBets();
  // Deal card to all players and the dealer himself.
  dealer.dealCards(players);

  // Switching turns for all players. Each player decides, if he wants to Hit or Stay.
  while (turns < players.size()) {
    printf("\n%s's hand: ", dealer.getUsername().c_str());
    printf("%i\n", dealer.checkHand());
    dealer.printHand();
    printf("________________________________\n");
    printf("           %i. round            \n", round);
    printf("________________________________\n");

    for (Player &player: players) {
      if (!player.isStanding() && !player.isBusted() && !player.getHasBlackjack()) {
        char choice;
        printf("\n\n******* %s's turn *******\n", player.getUsername().c_str());
        printf("\n%s's hand: ", player.getUsername().c_str());
        printf("%i, ", player.checkHand());
        printf("bet: %g\n", player.getBetAmount());
        player.printHand();
        // If user starts with blackjack, skip his turns
        if (player.checkHand() == 21) {
          player.setHasBlackjack(true);
          double wonAmount = player.getBetAmount() * 1.5;
          printf("%s hit a BLACKJACK", player.getUsername().c_str());
          printf(", won $%g", wonAmount);
          player.getWallet().addToBalance(wonAmount);
          turns++;
        } else {
          choice = presentChoice();
          if (choice == 'H') {
            Card drawnCard = dealer.getDeck().drawACard();
            if (drawnCard.getCardIntValue() == 11) {
              drawnCard.setCardIntValue(1);
            }
            player.hit(drawnCard);
          } else if (choice == 'S') {
            player.stand();
            turns++;
          } else {
            printf("Invalid input, enter only H or S.");
          }

          printf("\n%s's hand: ", player.getUsername().c_str());
          printf("%i\n", player.checkHand());
          player.printHand();

          // If user draws a card and busts, skip his turn.
          if (player.checkHand() > 21) {
            player.setBusted(true);
            printf("%s BUSTED", player.getUsername().c_str());
            printf(", lost $%g\n", player.getBetAmount());
            turns++;
          } else if (player.checkHand() == 21) {
            double wonAmount = player.getBetAmount() * 1.5;
            printf("%s hit a BLACKJACK", player.getUsername().c_str());
            printf(", won $%g", wonAmount);
            player.getWallet().addToBalance(wonAmount);
            turns++;
          }
        }
      }
//      printf("******* End of %s's turn *******\n", player.getUsername().c_str());

    }
    round++;
  }

  // Ending current game by flipping dealers card and checking
  // if his hand total less than 17, if that's the case dealer draws
  // a card until his total is over 17
  printf("\n\n******* End of Game *******\n\n");
  dealer.flipCard();
  while (dealer.checkHand() < 17) {
    dealer.hit(dealer.getDeck().drawACard());
  }
  if (dealer.checkHand() > 21) {
    dealer.setBusted(true);
    for (Player &player: players) {
      if (!player.isBusted()) {
        printf("%s get his", player.getUsername().c_str());
        printf(" $%g back\n", player.getBetAmount());
        player.getWallet().addToBalance(player.getBetAmount());
        turns++;
      }
    }
  }

  printf("Results: \n");

  // Checking results
  checkWin();

  // Offering for restarting a game or creating a brand new one.
  restartGame();
}

// Check results of current game
void Game::checkWin() {
  printf("%s's hand: ", dealer.getUsername().c_str());
  printf("%i\n", dealer.checkHand());
  dealer.printHand();
  printf("\n");

  int dealersHand = dealer.checkHand();
  for (Player &player: players) {
    if (player.isBusted()) {
      printf("\n%s's hand: ", player.getUsername().c_str());
      printf("%i\n", player.checkHand());
      printf("%s BUSTED!!", player.getUsername().c_str());
    }
  }
  if (dealer.isBusted()) {
    printf("Dealer BUSTED!!");
  } else {
    for (Player &player: players) {
      int playerHand = player.checkHand();
      if (!player.isBusted()) {
        printf("\n%s's hand: ", player.getUsername().c_str());
        printf("%i\n", player.checkHand());
      }
      if (!player.getHasBlackjack()) {
        if (playerHand == dealersHand) {
          // SAME HAND TOTAL -> PUSH
          printf("%s hit a PUSH!! ", player.getUsername().c_str());
          printf("Getting his %g back", player.getBetAmount());
          player.getWallet().addToBalance(player.getBetAmount());
        } else if (playerHand == 21 && dealersHand != 21) {
          // PlAYERS HAND EQUAL 21 -> BLACKJACK
          double wonAmount = player.getBetAmount() * 1.5;
          printf("%s hit a BLACKJACK", player.getUsername().c_str());
          printf(", won $%g", wonAmount);
          player.getWallet().addToBalance(wonAmount);
        } else if (playerHand > dealersHand && playerHand < 21) {
          // PlAYERS HAND OVER DEALERS -> WIN

          double wonAmount = player.getBetAmount() * 1.5;
          printf("%s WON!! Winnings are ", player.getUsername().c_str());
          printf("$%g \n", wonAmount);
          player.getWallet().addToBalance(wonAmount);
        } else if (dealersHand > playerHand) {
          // DEALERS HAND OVER PLAYERS -> LOSE
          printf("%s LOST!! ", player.getUsername().c_str());
          printf("Lost amount is $%g\n", player.getBetAmount());
        }
      }
    }
  }
}

void Game::createPlayer() {
  string userName;
  printf("Select player's name: ");
  cin >> userName;
  Player p = Player(userName, Wallet(5000.00));
  players.push_back(p);
}

void Game::printPlayers() {
  int index = 1;
  printf("\n");
  for (Player &player: players) {
    printf("%d. ", index);
    printf("%s, balance: ", player.getUsername().c_str());
    printf("$%g\n", player.getWallet().getBalance());
    index++;
  }
}

void Game::setDealer(Dealer dealerRef) {
  this->dealer = std::move(dealerRef);
}

// Prompts players for their bets
void Game::collectBets() {
  printf("********* Collecting bets **********\n");
  for (Player &player: players) {
    double bet = 0.0;
    printf("%s's bet: ", player.getUsername().c_str());
    cin >> bet;
    player.getWallet().subtractFromBalance(bet);
    cout << "Balance: " << player.getWallet().getBalance() << endl;
    player.setBetAmount(bet);
    printf("__________________________________\n");
  }
  printf("\n");
}

// Presents user with game choices. H (hit) / S (stay)
char Game::presentChoice() {
  printf("Hit or Stand?\n");
  printf("Press H to hit, press S to stand.\n");
  char c;
  cin >> c;
  char upperCased = toupper(c);
  return upperCased;
}

// Dialog displayed at the end of a game, where user chooses whether he
// wants to play again, create completely new game or exit the game
void Game::restartGame() {
  char choice = ' ';

  do {
    printf("\n\nPress R for to restart, N for a new game or Q for exit: ");
    cin >> choice;
    choice = toupper(choice);
    if (choice == 'R') {
      printf(("\n********* Restarting game *********\n"));
      dealer.getDeck().initDeck();
      dealer.resetPlayerState();
      for (Player &player: players) {
        player.resetPlayerState();
      }
      mainGameLoop();
    } else if (choice == 'N') {
      printf(("\n********* Starting a new game *********\n"));
      dealer.getDeck().initDeck();
      dealer.resetPlayerState();
      players.clear();
      initializePlayers();
      mainGameLoop();
    } else if (choice == 'Q') {
      players.clear();
      printf("\n*********** Bey, come back later :( ************");
      return;
    } else {
      printf("Wrong input, try again!!\n");
    }
  } while (choice != 'R' || choice != 'N' || choice != 'Q');
}