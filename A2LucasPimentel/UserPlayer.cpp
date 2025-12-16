#include "UserPlayer.h"
#include <iostream>

bool UserPlayer::move(char direction, int boardWidth, int boardHeight) {
    switch (direction) {
    case 'w': //move up
        if (y > 0) --y;
        break;
    case 'a': //move left
        if (x > 0) --x;
        break;
    case 's': //move down
        if (y < boardHeight - 1) ++y;
        break;
    case 'd': //move right
        if (x < boardWidth - 1) ++x;
        break;
    default:
        return false; //invalid move
    }
    return true;
}
