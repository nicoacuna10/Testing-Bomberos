#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

void agregarBombero(char *rut, char *nombre, int *disponibilidad, List* listaBomberos){
        char *d = malloc(2 * sizeof(char));

        printf("Ingrese rut: ");
        gets(rut);
        printf("\n");
        printf("Ingrese nombre: ");
        gets(nombre);

        printf("\nLunes: ");
        scanf("%[^\n]s", d);
        if(d[0] == 'S'){
            disponibilidad[0] = 1;
        }else disponibilidad[0] = 0;

        printf("\nMartes: ");
        scanf("%s", d);
        if(d[0] == 'S'){
            disponibilidad[1] = 1;
        }else disponibilidad[1] = 0;

        printf("\nMiercoles: ");
        scanf("%s", d);
        if(d[0] == 'S'){
            disponibilidad[2] = 1;
        }else disponibilidad[2] = 0;

        printf("\nJueves: ");
        scanf("%s", d);
        if(d[0] == 'S'){
            disponibilidad[3] = 1;
        }else disponibilidad[3] = 0;

        printf("\nViernes: ");
        scanf("%s", d);
        if(d[0] == 'S'){
            disponibilidad[4] = 1;
        }else disponibilidad[4] = 0;

        printf("\nSabado: ");
        scanf("%s", d);
        if(d[0] == 'S'){
            disponibilidad[5] = 1;
        }else disponibilidad[5] = 0;

        printf("\nDomingo: ");
        scanf("%s", d);
        getchar();
        if(d[0] == 'S'){
            disponibilidad[6] = 1;
        }else disponibilidad[6] = 0;


        int i;
        Bombero *aux = (Bombero*)malloc(sizeof(Bombero));
        strcpy(aux->rut,rut);
        strcpy(aux->nombre,nombre);
        for( i = 0; i < 7; i++){
            aux->disponibilidad[i] = disponibilidad[i];
        }
        pushBack(listaBomberos,aux);

}
