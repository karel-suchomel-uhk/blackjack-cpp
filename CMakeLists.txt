cmake_minimum_required(VERSION 3.21)
project(blackjack_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(blackjack-cpp)
include_directories(blackjack-cpp/card)
include_directories(blackjack-cpp/deck)
include_directories(blackjack-cpp/game)
include_directories(blackjack-cpp/player)
include_directories(game-library)

add_executable(
        blackjack_cpp
        blackjack-cpp/card/Card.cpp
        blackjack-cpp/card/Card.h
        blackjack-cpp/deck/Deck.cpp
        blackjack-cpp/deck/Deck.h
        blackjack-cpp/game/Game.cpp
        blackjack-cpp/game/Game.h
        blackjack-cpp/player/Player.cpp
        blackjack-cpp/player/Player.h
        blackjack-cpp/generate_to_string.h
        main.cpp game-library/GameLibrary.cpp game-library/GameLibrary.h blackjack-cpp/dealer/Dealer.cpp blackjack-cpp/dealer/Dealer.h)
