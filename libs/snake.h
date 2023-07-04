#ifndef _SNAKE_H_
#define _SNAKE_H_

struct snake_node
{
    int value;
    char body_part;
    struct snake_node* next;
};

#endif
