#include <stdio.h>
#include <stdlib.h>
#include "libs/test.h"
#include "libs/snake.h"

void move(struct snake_node** head)
{
    char direction;
    scanf("%c", &direction);

    if (direction == 'd')
    {
        increment(*head, 1);
    }
}


void increment(struct snake_node* head, int increment)
{
    while (head != NULL)
    {
        head->value += increment;
        head = head->next;
    }
}

void add(struct snake_node** head, int value)
{
    struct snake_node* newNode = (struct snake_node*)malloc(sizeof(struct snake_node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct snake_node* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main(void)
{
    struct snake_node* head = NULL;

    // Dodawanie 5 elementów do struktury
    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 40);
    add(&head, 50);

    moving_test(head);

    move(&head);

    moving_test(head);


    return 0;
}

