#include <stdio.h>


void spawnApple(char board[20][40]) {
    int X;
    int Y;
    
    do {
        X = rand() % 40; // generates a random number between 0 and 39
        Y = rand() % 20; // generates a random number between 0 and 19
    } while (board[Y][X] != ' '); // repeat if the location is occupied
    board[Y][X] = '#'; // place the apple on the board
}
