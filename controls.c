#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "libs/snake.h"
#include "libs/utils.h"

void readKey(struct snake_node **head)
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
            vertical_movement(*head, 1);
            break;
        // down arrow
        case 'B':
            vertical_movement(*head, -1);
            break;
        // right arrow
        case 'C':
            horizontal_movement(*head, 1);
            break;
        // left arrow
        case 'D':
            horizontal_movement(*head, -1);
            break;
        default:
            break;
        }
    }
}

void vertical_movement(struct snake_node **head, int increment)
{
    struct snake_node *current = *head;
    int prevX = current->X, prevY = current->Y;
    int tempX, tempY;

    // move the head
    current->X += increment;

    // move the rest of the body
    while (current != NULL)
    {
        // store current position
        tempX = current->X;
        tempY = current->Y;

        // move to previous part's position
        current->X = prevX;
        current->Y = prevY;

        // update previous position
        prevX = tempX;
        prevY = tempY;

        current = current->next;
    }
}

void horizontal_movement(struct snake_node **head, int increment)
{
    struct snake_node *current = *head;
    int prevX = current->X, prevY = current->Y;
    int tempX, tempY;

    // move the head
    current->Y += increment;

    // move the rest of the body
    while (current != NULL)
    {
        // store current position
        tempX = current->X;
        tempY = current->Y;

        // move to previous part's position
        current->X = prevX;
        current->Y = prevY;

        // update previous position
        prevX = tempX;
        prevY = tempY;

        current = current->next;
    }
}