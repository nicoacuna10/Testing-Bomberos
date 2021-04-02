#include <stdio.h>
#include <stdbool.h>
#ifndef List_h
#define List_h

typedef struct{
    char* rut;
    char* nombre;
    int disponibilidad[7];
}Bombero;

typedef struct List List;

List * createList(void);

void * firstList(List * list);

void * nextList(List * list);

void * lastList(List * list);

void * prevList(List * list);

void pushFront(List * list, Bombero * data);

void pushBack(List * list, Bombero * data);

void pushCurrent(List * list, Bombero * data);

void * popFront(List * list);

void * popBack(List * list);

void * popCurrent(List * list);

bool existeRutBombero(List * list, char* r)

void cleanList(List * list);

#endif /* List_h */
