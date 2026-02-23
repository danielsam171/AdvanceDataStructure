#include <stdio.h>
#include <stdlib.h>
#include "item_t.h"

item_t* item_t_building(int id, int valor){
    item_t *p = (item_t*)malloc(sizeof(item_t));
    p->id = id;
    p->valor = valor;
    return p;
}
void item_t_print(item_t *p){
    printf("Id: %d\nValor: %d",p->id,p->valor);
}