#include <stdio.h>
#include "libs/map.h"
#include "libs/apple.h"


void spawnApple(Apple *apple, char board[20][40]) {
    do {
        apple->X = rand() % 40; // generates a random number between 0 and 39
        apple->Y = rand() % 20; // generates a random number between 0 and 19
    } while (board[apple->Y][apple->X] != ' '); // repeat if the location is occupied
    board[apple->Y][apple->X] = '#'; // place the apple on the board
}
