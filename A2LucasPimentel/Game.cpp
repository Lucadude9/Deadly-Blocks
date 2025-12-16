#include "Game.h"
#include <iostream>

//initializes game settings and deadly blocks
Game::Game(UserPlayer* p, GameObject b, int w, int h, int numBlocks)
    : player(p), block(b), width(w), height(h), numDeadBlocks(numBlocks), numHits(0) {
    deadBlockLocations = { {2, 5}, {3, 4}, {4, 6}, {5, 7}, {6, 8},
                          {7, 1}, {8, 2}, {3, 8}, {1, 4}, {5, 2} };
}

//if a block is deadly based on its location
bool Game::isDeadlyBlock(int x, int y) {
    for (const auto& loc : deadBlockLocations) {
        if (loc.first == x && loc.second == y) {
            return true;
        }
    }
    return false;
}

//prints game board
void Game::printGameBoard() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (player->getX() == x && player->getY() == y) {
                std::cout << player->getSymbol();
            }
            else if (isDeadlyBlock(x, y)) {
                std::cout << '-'; //hide deadly blocks
            }
            else {
                std::cout << block.getSymbol();
            }
        }
        std::cout << std::endl;
    }
}

//main game loop
void Game::playGame() {
    std::cout << "Welcome to the game. \nThere are " << numDeadBlocks
        << " hidden deadly blocks.\n"
        << "Try to reach the bottom right corner without being hit by 80% of them " << std::endl;

    while (true) {
        printGameBoard();

        std::cout << "Enter a move (w/a/s/d) or (q) to quit: ";
        char move;
        std::cin >> move;

        if (move == 'q') {
            std::cout << "You quit the game!" << std::endl;
            break;
        }

        if (player->move(move, width, height)) {
            if (isDeadlyBlock(player->getX(), player->getY())) {
                numHits++;
                std::cout << "You Got Hit! You have been hit " << numHits
                    << " out of " << numDeadBlocks << std::endl;
            }
            if (player->getX() == width - 1 && player->getY() == height - 1) {
                std::cout << "You have reached the end!\n"
                    << "You have been hit " << numHits
                    << " out of " << numDeadBlocks << " throughout your journey." << std::endl;
                break;
            }
        }
        else {
            std::cout << "Invalid move. Try again!" << std::endl;
        }
    }
}
