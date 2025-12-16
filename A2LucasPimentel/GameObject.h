#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//represents an object on the game board with a symbol
class GameObject {
private:
	char symbol;

public:
	GameObject(char s = '-') : symbol(s) {}

	char getSymbol() const { return symbol; }
};

#endif
