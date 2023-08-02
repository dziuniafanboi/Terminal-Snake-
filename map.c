#include <stdio.h>
#include "libs/map.h"

void initialze_map(char board[20][40])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            board[i][j] = ' ';
        }
    }
}