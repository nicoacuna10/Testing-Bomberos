#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct{
    char* rut;
    char* nombre;
    int disponibilidad[7];
}bombero;

void modificarDisponibilidadDeUnBombero(char *rut, int *disponibilidad, List *listaBomberos){


        printf("Ingrese rut: ");
        gets(rut);

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
                char *d = malloc(2 * sizeof(char));

                printf("\nEscriba SI o NO segun disponibilidad");

                printf("\nLunes: ");
                scanf("%s", d);
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

                for( i = 0; i < 7; i++){
                    aux->disponibilidad[i] = disponibilidad[i];
                }
                printf("-------------------------\n");
                printf("Disponibilidad modificada\n");
                printf("-------------------------\n");
                return;
            }
            aux = nextList(listaBomberos);
        }
        if(!encontrado){
            printf("NO EXISTE REGISTRO");
        }

}
