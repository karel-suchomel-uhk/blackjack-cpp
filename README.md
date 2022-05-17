# Blackjack

I have decided to do a Blackjack game for my final project. This document serves the purpose of the summary of the game and as a documentation for my program.
This blackjack game is based on regular rules, not on the casino one's, that means there might be a few things missing. I hope you will enjoy it and that it is sufficient enough. It was my first time writing C++ code, but I believe that it is readable and well structured. I have spent approx. 15h writing this codebase, so there is deffinitely room for improvment.


## Rules of Blackjack
1. The game starts with everybody besides the dealer placing a bet. Then the dealer deals 1 card facing up to each player and 1 card facing up to themselves. Everyone is dealt one more face-up card besides the dealer, whose card is dealt face-down.
2. If your hand total’s higher than 21, it is called a **BUST**, which means you are out of the game.
3. Card 2-10 are scored using their face value, and Jacks, Queens, and Kings are all equal to 10.
4. Aces are equal to 1 or 11, and you can choose their value throughout the round if you have one.
5. If your hand is equal to 21 you automatically win 1.5x of your bet and you're done for that round.
6. Otherwise, the dealer asks whether you want another card from the top of the deck. If you do, say **HIT**.
7. If you don't want any more cards, say **STAY.**
8. There is no limit to how many cards you ask for, but once your hand totals higher than 21, you **BUST,** and the dealer gets your bet.
9. Once the dealer has gone around the table, they flip up their face-down card. If it's 16 or under, they have to take another card. If it's 17 or higher, that has to STAY with their hand.
10. If the dealer BUST, every player, that's still in that round wins 2x their bet.
11. However, if the dealer doesn't BUST, only the players, whose hands are higher than dealers, win 2x their bet. Everyone else loses their bet.
12. If the dealer's and the player's hands total is the same, it is called **PUSH** and the player gets their bet back.


## How to play
1. After you run the application, you will be presented options of how many players are going to play. Enter any number higher than 0, and you will be taken to the next step.
2. Next you are going to be prompted for usernames for every player that you have chosen.
3. After you enter all usernames, the game will start automatically.
4. Each game starts by collecting bets. Every player is going to be prompted to enter the amount they want to bet and after all players entered their bet, the dealer will deal cards to every player.
5. Players take a turn. In every turn player can either Hit by pressing the [H] key or Stay by  the [S] key. The player's turn is ended when his hand total is 21 or higher or if he chooses to Stay.
6. After all players end their turn, results will be printed on the screen, after which a user can decide whether he what to restart the game [R], create a new one [N], or quit the game completely [Q].
