#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"


void eliminarBomberos(char *rut, List *list, unsigned long long *talla){
  printf("Ingrese rut del bombero a despedir: ");
  scanf("%[^\n]s", rut);
  getchar();
    int j, i;
    bool encontrado;
    for( j = 0; j < *talla; j++){
        encontrado = existeRutBombero(list, rut);
        if(encontrado){
            popCurrent(list);
            *talla = *talla-1;
            vector = realloc (vector, (*talla) * sizeof(Bombero));
            printf("-----------------------\n");
            printf("BOMBERO ELIMINADO\n");
            printf("-----------------------\n");
            return;
        }
    }
    if(!encontrado){
        printf("NO EXISTE BOMBERO\n");
    }
}
