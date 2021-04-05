#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

void porFavorIngreseAlgoValido(char *d){
    //Esta función verifica que los datos ingresados sean validos//
    do{
        printf("Por favor Ingrese elementos VALIDOS\n");
        printf("Solo puede ser S mayúscula o N Mayúscula\n\n");
        printf("Por favor ingrese su opción: ");
        scanf("%c", d);
        getchar();
    }while( (*d != 'S') && (*d != 'N') );
    return;
}

void agregarBombero(char *rut, char *nombre, int *disponibilidad, List* listaBomberos){
        char d;
        
        //Se lee rut y nombre//
        printf("Ingrese rut: ");
        scanf("%s", rut);
        getchar();
        printf("Ingrese nombre: ");
        scanf("%[^\n]s", nombre);
        getchar();


        //Testing//
        //printf("%s\n", rut);
        //printf("%s\n", nombre);
        //Fin testing//

        /*Se ingresan disponibilidad por días de la semana.
        Tambien se verifica si el dato es correcto       */
        printf("Por favor ingrese disponiblidad por persona: S = si, N = No\n");
        printf("Lunes: ");
        scanf("%c", &d);
        getchar();
        if( (d != 'S') && (d != 'N') ) porFavorIngreseAlgoValido(&d); 
        if(d == 'S'){
            disponibilidad[0] = 1;
        }else disponibilidad[0] = 0;

        printf("\nMartes: ");
        scanf("%c", &d);
        getchar();
        if( (d != 'S') && (d != 'N') ) porFavorIngreseAlgoValido(&d);
        if(d == 'S'){
            disponibilidad[1] = 1;
        }else disponibilidad[1] = 0;

        printf("\nMiercoles: ");
        scanf("%c", &d);
        getchar();
        if( (d != 'S') && (d != 'N') ) porFavorIngreseAlgoValido(&d);
        if(d == 'S'){
            disponibilidad[2] = 1;
        }else disponibilidad[2] = 0;

        printf("\nJueves: ");
        scanf("%c", &d);
        getchar();
        if( (d != 'S') && (d != 'N') ) porFavorIngreseAlgoValido(&d);
        if(d == 'S'){
            disponibilidad[3] = 1;
        }else disponibilidad[3] = 0;

        printf("\nViernes: ");
        scanf("%c", &d);
        getchar();
        if( (d != 'S') && (d != 'N') ) porFavorIngreseAlgoValido(&d);
        if(d == 'S'){
            disponibilidad[4] = 1;
        }else disponibilidad[4] = 0;

        printf("\nSabado: ");
        scanf("%c", &d);
        getchar();
        if( (d != 'S') && (d != 'N') ) porFavorIngreseAlgoValido(&d);
        if(d == 'S'){
            disponibilidad[5] = 1;
        }else disponibilidad[5] = 0;

        printf("\nDomingo: ");
        scanf("%c", &d);
        getchar();
        if( (d != 'S') && (d != 'N') ) porFavorIngreseAlgoValido(&d);
        if(d == 'S'){
            disponibilidad[6] = 1;
        }else disponibilidad[6] = 0;

        /*Nombre, rut y disponiblidad se guardan en en variable dinamica aux
        y luego se realiza un pushback a la lista con aux*/
        int i;
        Bombero *aux = (Bombero*)malloc(sizeof(Bombero));
        strcpy(aux->rut,rut);
        strcpy(aux->nombre,nombre);
        for( i = 0; i < 7; i++){
            aux->disponibilidad[i] = disponibilidad[i];
        }
        pushBack(listaBomberos,aux);
        //Tengo mi duda si debemos hacer free a aux//

    return;
}