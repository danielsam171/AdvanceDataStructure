#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item_t.h"
#include "stack_t.h"

stack_t* create_stack(int size){
    stack_t *p = (stack_t*)malloc(sizeof(stack_t));
    p -> base = (item_t*)malloc(sizeof(item_t)*size);
    p -> top = p -> base;
    p -> size = size;
    p -> previous = NULL;
    return p;
}
bool empty(stack_t* stack){
    return (stack -> base == stack -> top && stack -> previous == NULL);
}
void push(stack_t *stack,item_t item){
    if(stack->top < stack->base + stack->size){
        *(stack->top) = item;
        stack->top += 1;
    }
    else{
        stack_t *new = (stack_t*)malloc(sizeof(stack_t));
        new -> base = stack -> base;
        new -> size = stack -> size;
        new ->  top = stack -> top;
        new -> previous = stack -> previous;
        stack -> previous = new;
        stack -> base = (item_t*)malloc(sizeof(item_t)*stack->size);
        stack -> top = stack -> base + 1;
        *(stack -> base) = item;
    }
} 
item_t pop(stack_t *stack){
    if(empty(stack)){
        printf("La pila esta vacia, Se retornara un item basura");
        return (item_t){ .id = -1, .valor = 0 };
    }
    if(stack-> base == stack-> top){
        stack_t *old;
        old = stack-> previous;
        stack -> top = old -> top;
        stack -> size = old -> size;
        free(stack->base);
        stack -> base = old -> base;
        stack -> previous = old -> previous;
        free(old);
    }
    stack -> top -= 1;
    return *(stack -> top);  
}

item_t top(stack_t *stack){
    if(stack->top == stack->base){
        stack_t *stack_prev = stack->previous;
        return *((stack_prev-> top)-1);
    }
    return *(stack->top -1);
}

void remove_stack(stack_t *stack){
    stack_t *tmp;
    do
    { tmp = stack->previous;
    free( stack->base );
    free( stack );
    stack = tmp;
    }
    while( stack != NULL );
}