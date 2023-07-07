#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include "libs/test.h"
#include "libs/snake.h"
#include "libs/map.h"

void move(struct snake_node** head)
{
    while(_kbhit())
    {
        switch (getch())
        {
        case 'd':
           horizontal_movement(*head, 1);
            break;
        case 'w':
	        vertical_movement(*head, 1);
            break;
        case 's':
    	    vertical_movement(*head, -1);
            break;
        case 'a':
	        horizontal_movement(*head, -1);
            break;
        
        default:
            break;
        }
    }
}


void vertical_movement(struct snake_node* head, int increment)
{
    while (head != NULL)
    {
        head->X += increment;
        head = head->next;
    }
}

void horizontal_movement(struct snake_node* head, int increment)
{
    while (head != NULL)
    {
        head->Y += increment;
        head = head->next;
    }
}

void add(struct snake_node** head, int x, int y)
{
    struct snake_node* newNode = (struct snake_node*)malloc(sizeof(struct snake_node));
    newNode->X = x;
    newNode->Y = y;
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

    initialze_map();

    // Dodawanie 5 elementów do struktury
    add(&head, 10, 10);
    add(&head, 20, 20);
    add(&head, 30, 30);
    add(&head, 40, 40);
    add(&head, 50, 50);

    moving_test(head);
    char direction;

    while(1)
    {   
    move(&head);

    moving_test(head);
    }

    return 0;
}

