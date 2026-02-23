#ifndef ITEM_T_H
#define ITEM_T_H

typedef struct{
    int id;
    int valor;
}item_t;

item_t* item_t_building(int id, int valor);
void item_t_print(item_t *p);
#endif 