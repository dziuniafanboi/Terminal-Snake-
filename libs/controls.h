#ifndef _CONTROLS_H_
#define _CONTROLS_H_

void readKey(struct snake_node **head);

void vertical_movement(struct snake_node **head, int increment);

void horizontal_movement(struct snake_node **head, int increment);

#endif