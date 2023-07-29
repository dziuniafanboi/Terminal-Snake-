#include <stdio.h>
#include "libs/map.h"

// map is 24x12
void initialze_map(char board[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            board[i][j] = ' ';
        }
    }
}