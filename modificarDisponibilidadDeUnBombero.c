#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct{
    char* rut;
    char* nombre;
    int disponibilidad[7];
}bombero;

void validarDato(char *d){
    do{
        printf("Por favor Ingrese elementos VALIDOS\n");
        printf("Solo puede ser S mayúscula o N Mayúscula\n\n");
        printf("Por favor ingrese su opción: ");
        scanf("%c", d);
        getchar();
    }while( (*d != 'S') && (*d != 'N') );
    return;
}

void modificarDisponibilidadDeUnBombero(char *rut, int *disponibilidad, List *listaBomberos){
        //Hay que ver si sacamos rut de variable de entrada de la función//

        printf("Ingrese rut: ");
        scanf("%s", rut);
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
                char d; 

                printf("\nEscriba SI o NO segun disponibilidad");

                printf("\nLunes: ");
                scanf("%c", &d);
                getchar();
                if( (d != 'S') && (d != 'N') ) validarDato(&d);
                if(d == 'S'){
                disponibilidad[0] = 1;
                }else disponibilidad[0] = 0;

                printf("\nMartes: ");
                scanf("%c", &d);
                getchar();
                if( (d != 'S') && (d != 'N') ) validarDato(&d);
                if(d == 'S'){
                disponibilidad[1] = 1;
                }else disponibilidad[1] = 0;

                printf("\nMiercoles: ");
                scanf("%c", &d);
                getchar();
                if( (d != 'S') && (d != 'N') ) validarDato(&d);
                if(d == 'S'){
                    disponibilidad[2] = 1;
                }else disponibilidad[2] = 0;

                printf("\nJueves: ");
                scanf("%c", &d);
                getchar();
                if( (d != 'S') && (d != 'N') ) validarDato(&d);
                if(d == 'S'){
                    disponibilidad[3] = 1;
                }else disponibilidad[3] = 0;

                printf("\nViernes: ");
                scanf("%c", &d);
                getchar();
                if( (d != 'S') && (d != 'N') ) validarDato(&d);
                if(d == 'S'){
                    disponibilidad[4] = 1;
                }else disponibilidad[4] = 0;

                printf("\nSabado: ");
                scanf("%c", &d);
                getchar();
                if( (d != 'S') && (d != 'N') ) validarDato(&d);
                if(d == 'S'){
                    disponibilidad[5] = 1;
                }else disponibilidad[5] = 0;

                printf("\nDomingo: ");
                scanf("%c", &d);
                getchar();
                if( (d != 'S') && (d != 'N') ) validarDato(&d);
                if(d == 'S'){
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