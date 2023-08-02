#include <stdlib.h>
#include "libs/snake.h"

void add(struct snake_node **head, int x, int y)
{
    snake_node *newNode = (snake_node *)malloc(sizeof(snake_node));
    newNode->X = x;
    newNode->Y = y;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    snake_node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}