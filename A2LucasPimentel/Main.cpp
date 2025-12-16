#include "Game.h"

int main() {
	//creat player position
	UserPlayer player(0, 0, 'X');
	//empty block
	GameObject emptyBlock('-');
	//initialize game
	Game game(&player, emptyBlock);
	//start game
	game.playGame();

	return 0;
}
