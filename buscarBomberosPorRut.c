#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

typedef struct{
    char* rut;
    char* nombre;
    int disponibilidad[7];
    int diasConTrabajo;
    int totalDeDiasDisponibles;
}bombero;

void buscarBomberosPorRut(char *rut, List *listaBomberos){
    //Se ingresa rut por persona//
    printf("\nIngrese RUT: ");
    scanf("%[^\n]s", rut);
    getchar();

    int i, espacios;
    bool encontrado;
    bombero *aux = firstList(listaBomberos);

    /*Se recorre con aux toda la lista y cada vez se va verificando si el rut es el encontrado.
    Sino se encuentra rut se menciona por pantalla.                                          */
    while(aux!=NULL){
        i=0;
        encontrado = true;
        aux->rut = (char*)aux->rut;
        for( i = 0; aux->rut[i]; i++){
            if(aux->rut[i] != rut[i]){
                encontrado = false;
                break;
            }
        }
        if(encontrado){
            printf("RUT            NOMBRE                        DISPONIBILIDAD\n");
            espacios = 10 - strlen(aux->rut);
            if(espacios == 1){ printf(" "); }
            printf("%s     %s", aux->rut, aux->nombre);
            espacios = 30 - strlen(aux->nombre);
            for( i = 0; i < espacios; i++){
                printf(" ");
            }
            //Se imprimen los días y su respectiva disponibilidad//
            int j;
            printf("[");
            for(j = 0; j < 7; j++) printf("%d ", aux->disponibilidad[j]);

            printf("]\n");
            return;
        }
        aux = nextList(listaBomberos);
    }

    if(!encontrado){
        printf("NO EXISTE REGISTRO\n");
    }

    return;
}
