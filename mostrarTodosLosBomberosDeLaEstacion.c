#include <stdio.h>
#include <string.h>
#include "list.h"

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

void mostrarTodosLosBomberosDeLaEstacion(List *listaBomberos){
    int i;
    Bombero* aux = firstList(listaBomberos);
    printf("RUT          NOMBRE                    DISPONIBILIDAD\n");
    while(aux!=NULL){
    printf("%s          %s                    [", aux->rut, aux->nombre);
        for( i = 0; i < 7; i++){
            printf("%d ", aux->disponibilidad[i]);
        }
        printf("]\n");
        aux = nextList(listaBomberos);
    }
    printf("\n\n");
}
