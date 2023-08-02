#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include "libs/test.h"
#include "libs/snake.h"
#include "libs/map.h"
#include "libs/utils.h"
#include "libs/controls.h"
#include "libs/apple.h"

void print_node(snake_node *node, char board[20][40])
{
    printf("(%d, %d)\n", node->Y, node->X);
    if (node->body_part != '\0')
    {
        board[node->Y][node->X] = node->body_part;
        return;
    }
    board[node->Y][node->X] = '$';
}

void print_board(snake_node *head, Apple *apple, char board[20][40])
{
        
    initialze_map(board);

     board[apple->Y][apple->X] = '#';

    snake_node *current = head;
    while (current != NULL)
    {
        print_node(current, board);
        current = current->next;
    }

    printf("-");
    for (int i = 0; i < 40; i++)
    {
        printf("-");
    }
    printf("-\n");

    for (int i = 0; i < 20; i++)
    {
        printf("|");
        for (int j = 0; j < 40; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }

    printf("-");
    for (int i = 0; i < 40; i++)
    {
        printf("-");
    }
    printf("-\n");


}

int main(void)
{
    srand(time(NULL));

    snake_node *head = NULL;
    Apple apple;

    char board[20][40];

    initialze_map(board);
    spawnApple(&apple, board);

    // Dodawanie elementów do struktury
    add(&head, 10, 10);

    enableRawMode();
    while (1)
    {
        readKey(&head, &apple, board);
        print_board(head, &apple, board);
    }
    disableRawMode();

    return 0;
}