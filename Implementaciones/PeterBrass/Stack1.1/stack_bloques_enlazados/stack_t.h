#ifndef STACK_T_H
#define STACK_T_H
#include "item_t.h"
#include <stdbool.h>

typedef struct sff{
    item_t *base;
    item_t *top;
    int size;
    struct sff *previous;
}stack_t;

stack_t* create_stack(int size);
bool empty(stack_t* stack);
void push(stack_t *stack,item_t item); 
item_t pop(stack_t *stack);
item_t top(stack_t *stack);
void remove_stack(stack_t *stack);

#endif 