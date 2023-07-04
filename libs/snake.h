#ifndef _SNAKE_H_
#define _SNAKE_H_

struct snake_node
{
    int X;
    int Y;
    char body_part;
    struct snake_node* next;
};

void add(struct snake_node** head, int x, int y);

#endif
