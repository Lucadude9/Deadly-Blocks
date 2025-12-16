#ifndef GAME_H
#define GAME_H

#include "GameObject.h"
#include "UserPlayer.h"
#include <vector>

//game logic
class Game {
private:
	int width, height, numDeadBlocks;
	std::vector<std::pair<int, int>> deadBlockLocations;
	UserPlayer* player;
	GameObject block;
	int numHits;

public:
	// initializes the game with player, block, and board dimensions
	Game(UserPlayer* p, GameObject b, int w = 10, int h = 10, int numBlocks = 10);
	//game board
	void printGameBoard();
	//starts game
	void playGame();

private:
	// Checks if a position contains a deadly block
	bool isDeadlyBlock(int x, int y);
};

#endif
