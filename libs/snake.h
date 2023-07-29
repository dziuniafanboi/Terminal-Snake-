#ifndef _SNAKE_H_
#define _SNAKE_H_

typedef struct snake_node
{
    int X;
    int Y;
    char body_part;
    struct snake_node *next;
} snake_node;

#endif
