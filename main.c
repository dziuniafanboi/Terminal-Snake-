#include <stdio.h>
#include <stdlib.h>

struct snake_node
{
    int value;
    char body_part;
    struct snake_node* next;
};

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
    struct snake_node* first = NULL;

    // Dodawanie 5 elementów do struktury
    add(&first, 10);
    add(&first, 20);
    add(&first, 30);
    add(&first, 40);
    add(&first, 50);

    move(&first);

    return 0;
}

