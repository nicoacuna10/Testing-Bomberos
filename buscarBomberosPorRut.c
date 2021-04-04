#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct{
    char* rut;
    char* nombre;
    int disponibilidad[7];
}bombero;

void buscarBomberosPorRut(char *rut, List *listaBomberos){
    printf("Ingrese RUT: ");
    scanf("%[^\n]s", rut);
    getchar();

    int i;
    bool encontrado;
    bombero *aux = firstList(listaBomberos);

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
            printf("RUT               NOMBRE\n");
            printf("%s          %s\n", aux->rut, aux->nombre);
            return;
        }
        aux = nextList(listaBomberos);
    }
    if(!encontrado){
        printf("NO EXISTE REGISTRO\n");
    }

}
