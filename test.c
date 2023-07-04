#include <stdio.h>
#include "libs/snake.h"

void moving_test(struct snake_node* head)
{
        while(head->next != NULL)
        {
                printf("%d\n", head->value);
                head = head->next;
        }
}



