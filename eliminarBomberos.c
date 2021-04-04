#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

void eliminarBomberos(char *rut, List *listaBomberos, unsigned long long *talla){
    printf("Ingrese rut del bombero a despedir: ");
    scanf("%[^\n]s", rut);
    getchar();
    int i;
    bool encontrado;
    Bombero* aux = firstList(listaBomberos);
    while(aux!=NULL){
        i=0;
        encontrado = true;
        aux->rut = (char*)aux->rut;
        for( i = 0; aux->rut[i]; i++){
            if(aux->rut[i] != rut[i]){
                encontrado = false;
            }
        }
        if(encontrado){
            aux = popCurrent(listaBomberos);
            *talla = *talla-1;
            printf("-----------------------\n");
            printf("BOMBERO ELIMINADO\n");
            printf("-----------------------\n");
            return;
        }
        aux = nextList(listaBomberos);
    }
    if(!encontrado){
        printf("NO EXISTE REGISTRO\n");
    }
}
