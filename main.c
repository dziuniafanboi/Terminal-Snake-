#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include "libs/test.h"
#include "libs/snake.h"
#include "libs/map.h"
#include "libs/utils.h"
#include "libs/controls.h"

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