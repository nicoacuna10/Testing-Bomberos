#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

void buscarBomberosDisponiblesPorDia(char *dia, List *listaBomberos){
    printf("Ingrese dia para buscar bomberos disponibles: ");
    scanf("%[^\n]s", dia);
    getchar();

    int j;
    Bombero *aux;

    for( j = 0; dia[j]; j++){
        dia[j] = toupper(dia[j]);
    }

    printf("RUT                    NOMBRE\n");

    aux = firstList(listaBomberos);

    if(dia[0] == 'L'){
        while(aux!=NULL){
            if(aux->disponibilidad[0] == 1){
                printf("%s               %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'M' && dia[1] == 'A'){
        while(aux!=NULL){
            if(aux->disponibilidad[1] == 1){
                printf("%s          %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'M' && dia[1] == 'I'){
        while(aux!=NULL){
            if(aux->disponibilidad[2] == 1){
                printf("%s          %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'J'){
        while(aux!=NULL){
            if(aux->disponibilidad[3] == 1){
                printf("%s          %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'V'){
        while(aux!=NULL){
            if(aux->disponibilidad[4] == 1){
                printf("%s          %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'S'){
        while(aux!=NULL){
            if(aux->disponibilidad[5] == 1){
                printf("%s          %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'D'){
        while(aux!=NULL){
            if(aux->disponibilidad[6] == 1){
                printf("%s          %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    return;
}
