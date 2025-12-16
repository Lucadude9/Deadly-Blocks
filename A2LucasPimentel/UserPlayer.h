#ifndef USERPLAYER_H
#define USERPLAYER_H

class UserPlayer {
private:
	int x, y;
	char symbol;

public:
	//default position and symbol
	UserPlayer(int xPos = 0, int yPos = 0, char s = 'X') : x(xPos), y(yPos), symbol(s) {}

	int getX() const { return x; }
	int getY() const { return y; }
	char getSymbol() const { return symbol; }

	//move player based on input
	bool move(char direction, int boardWidth, int boardHeight);
};

#endif
