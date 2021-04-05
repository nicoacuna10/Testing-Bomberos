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
    //Se ingresa rut de persona a sacar de la lista//
    printf("Ingrese rut del bombero a despedir: ");
    scanf("%[^\n]s", rut);
    getchar();


    int i;
    bool encontrado;
    Bombero* aux = firstList(listaBomberos);
    /*Se recorre la lista con 'aux' y se verifica si se encuentra bombmero.
    Si se encuentra se borrar con popcurrent y se sale del programa.
    sino se imprime que no existe reigstro                               */
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

    //free(aux);
    return;
}
