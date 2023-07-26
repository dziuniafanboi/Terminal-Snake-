#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include "libs/test.h"
#include "libs/snake.h"
#include "libs/map.h"

// struct for holding original terminal settings
struct termios orig_termios;

// function to turn on "no buffor" mode
void enableRawMode()
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, &orig_termios);
    raw = orig_termios;

    // turn of classical keyboard mode
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    // set minimal delay time and min char number
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    // set my setting in terminal
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// function to turn off "no buffor" mode
void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCIFLUSH, &orig_termios);
}

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

void add(struct snake_node **head, int x, int y)
{
    struct snake_node *newNode = (struct snake_node *)malloc(sizeof(struct snake_node));
    newNode->X = x;
    newNode->Y = y;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct snake_node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main(void)
{
    struct snake_node *head = NULL;
    char c;

    initialze_map();

    // Dodawanie 5 elementów do struktury
    add(&head, 10, 10);
    add(&head, 10, 11);
    add(&head, 10, 12);
    add(&head, 10, 13);
    add(&head, 10, 14);

    moving_test(head);

    enableRawMode();
    while (1)
    {
        // move(&head);
        readKey(&head);
        moving_test(head);
    }
    disableRawMode();

    return 0;
}