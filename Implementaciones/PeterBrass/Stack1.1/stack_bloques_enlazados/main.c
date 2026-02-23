#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item_t.h"
#include "stack_t.h"

int main(){
    item_t *a = item_t_building(1,10);
    item_t *b = item_t_building(2,20);
    item_t *c = item_t_building(3,30);
    item_t *d = item_t_building(4,40);
    stack_t *stacka = create_stack(3);
    push(stacka,*a);
    push(stacka,*b);
    push(stacka,*c);
    push(stacka,*d);

    item_t newa = pop(stacka);
    printf("\nEl id: %d",newa.id);
    item_t newb = pop(stacka);
    printf("\nEl id: %d",newb.id);
    item_t newc = pop(stacka);
    printf("\nEl id: %d",newc.id);
    item_t newd = pop(stacka);
    printf("\nEl id: %d\n",newd.id);
    item_t newe = pop(stacka);

    push(stacka,*a);
    push(stacka,*b);
    push(stacka,*c);
    push(stacka,*d);
    

    newa = top(stacka);
    printf("\nEl id: %d",newa.id);
    newb = top(stacka);
    printf("\nEl id: %d",newb.id);
    
}