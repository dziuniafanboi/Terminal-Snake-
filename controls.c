#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "libs/snake.h"
#include "libs/utils.h"
#include "libs/apple.h"
#include "libs/map.h"

typedef enum
{
    VERTICAL,
    HORIZONTAL
} direction;

void movement(snake_node **head, int increment, direction dir, Apple *apple, char board[20][40])
{
    // ostatni element
    snake_node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    // organiczenie ruchu tak żeby glizda nie uciekła poza plansze
    if (dir == VERTICAL && (current->Y + increment < 0 || current->Y + increment >= 20))
    {
        printf("Game Over\n");
        disableRawMode();
        exit(0);
    }
    if (dir == HORIZONTAL && (current->X + increment < 0 || current->X + increment >= 40))
    {
        printf("Game Over\n");
        disableRawMode();
        exit(0);
    }

    // nowy node
    snake_node *new_node = (snake_node *)malloc(sizeof(snake_node));
    new_node->X = current->X;
    new_node->Y = current->Y;
    current->body_part = '$';
    new_node->body_part = 'O';
    new_node->next = NULL;

    if (dir == VERTICAL)
    {
        new_node->Y += increment;
    }
    else if (dir == HORIZONTAL)
    {
        new_node->X += increment;
    }

    // check if the new position is the same as the apple's position
    if (new_node->X == apple->X && new_node->Y == apple->Y)
    {
        // Spawn a new apple.
        spawnApple(apple, board);
    }
    else
    {
        current->next = new_node;
    }

    // dodanie nowego node na koniec
    current->next = new_node;

    // usuniecie pierwszego node
    snake_node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void readKey(snake_node **head, Apple *apple, char board[20][40])
{
    char c;
    char seq[3];

    read(STDIN_FILENO, &c, 1);

    if (c == 'q') // if 'q' is pressed
    {
        disableRawMode(); // turn off "no buffer" mode
        exit(0);          // exit the program
    }

    if (c == '\x1b')
    {
        read(STDIN_FILENO, &seq[0], 1);
        read(STDIN_FILENO, &seq[1], 1);

        switch (seq[1])
        {
            // up arrow
        case 'A':
            movement(head, -1, VERTICAL, apple, board);
            break;
        // down arrow
        case 'B':
            movement(head, 1, VERTICAL, apple, board);
            break;
        // right arrow
        case 'C':
            movement(head, 1, HORIZONTAL, apple, board);
            break;
        // left arrow
        case 'D':
            movement(head, -1, HORIZONTAL, apple, board);
            break;
        default:
            break;
        }
    }
}