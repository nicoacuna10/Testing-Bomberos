#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
  int diasConTrabajo;
  int totalDeDiasDisponibles;
}Bombero;

void mostrarTodosLosBomberosDeLaEstacion(List *listaBomberos){
    int i, espacios;
    Bombero* aux = firstList(listaBomberos);

    //se usa aux para recorrer toda la lista e imprimirla a continuación//
    printf("\nRUT            NOMBRE                        DISPONIBILIDAD\n");
    while(aux!=NULL){
        espacios = 10 - strlen(aux->rut);
        for(i = 0; i < espacios; i++){
            printf(" ");
        }
        printf("%s     %s", aux->rut, aux->nombre);
        espacios = 30 - strlen(aux->nombre);
        for( i = 0; i < espacios; i++){
            printf(" ");
        }
        printf("[");
        for( i = 0; i < 7; i++){
            printf("%d ", aux->disponibilidad[i]);
        }
        printf("]\n");
        aux = nextList(listaBomberos);
    }

    return;
}
