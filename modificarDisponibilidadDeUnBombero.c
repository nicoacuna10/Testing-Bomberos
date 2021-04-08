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

void validarDato(char d[5000]){
    do{
        printf("Por favor Ingrese elementos VALIDOS\n");
        printf("Solo puede ser S mayúscula o N Mayúscula\n\n");
        printf("Por favor ingrese su opción: ");
        scanf("%[^\n]s", d);
        while( ( getchar() ) != '\n');
    }while( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') );
    return;
}

void modificarDisponibilidadDeUnBombero(char *rut, int *disponibilidad, List *listaBomberos){
        printf("Ingrese rut: ");
        scanf("%s", rut);
        getchar();

        int i;
        bool encontrado;
        bombero *aux = firstList(listaBomberos);

        //Se recorre la lista con 'aux' y en el caso de encontrarse vamos cambiando la disponibilidad//
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
                char d[5000]; 


                printf("Por favor ingrese disponiblidad por persona: S = si, N = No\n");
                printf("\nLunes: ");
                scanf("%[^\n]s", d);
                getchar();
                if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) validarDato(d);
                if(d[0] == 'S'){
                disponibilidad[0] = 1;
                }else disponibilidad[0] = 0;

                printf("\nMartes: ");
                scanf("%[^\n]s", d);
                getchar();
                if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) validarDato(d);
                if(d[0] == 'S'){
                disponibilidad[1] = 1;
                }else disponibilidad[1] = 0;

                printf("\nMiercoles: ");
                scanf("%[^\n]s", d);
                getchar();
                if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) validarDato(d);
                if(d[0] == 'S'){
                    disponibilidad[2] = 1;
                }else disponibilidad[2] = 0;

                printf("\nJueves: ");
                scanf("%[^\n]s", d);
                getchar();
                if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) validarDato(d);
                if(d[0] == 'S'){
                    disponibilidad[3] = 1;
                }else disponibilidad[3] = 0;

                printf("\nViernes: ");
                scanf("%[^\n]s", d);
                getchar();
                if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) validarDato(d);
                if(d[0] == 'S'){
                    disponibilidad[4] = 1;
                }else disponibilidad[4] = 0;

                printf("\nSabado: ");
                scanf("%[^\n]s", d);
                getchar();
                if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) validarDato(d);
                if(d[0] == 'S'){
                    disponibilidad[5] = 1;
                }else disponibilidad[5] = 0;

                printf("\nDomingo: ");
                scanf("%[^\n]s", d);
                getchar();
                if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) validarDato(d);
                if(d[0] == 'S'){
                    disponibilidad[6] = 1;
                }else disponibilidad[6] = 0;

                for( i = 0; i < 7; i++){
                    aux->disponibilidad[i] = disponibilidad[i];
                }
                printf("\n-------------------------\n");
                printf("Disponibilidad modificada\n");
                printf("-------------------------\n");
                return;
            }
            aux = nextList(listaBomberos);
        }
        if(!encontrado){
            printf("NO EXISTE REGISTRO DEL RUT INGRESADO");
        }

    return;
}