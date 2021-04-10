#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
  int diasConTrabajo;
  int totalDeDiasDisponibles;
}Bombero;

void porFavorIngreseAlgoValido(char d[5000]){
    //Esta función verifica que los datos ingresados sean validos//
    do{
        memset(d, '\0', 5000);
        printf("Por favor Ingrese elementos VALIDOS\n");
        printf("Solo puede ser S mayúscula o N Mayúscula\n\n");
        printf("Por favor ingrese su opción: ");
        scanf("%[^\n]s", d);
        getchar();
    }while( (d[0] != 'S') && (d[0] != 'N')  || (d[1] != '\0') );
    return;
}

void agregarBombero(char rut[11], char nombre[101], int disponibilidad[7], List* listaBomberos){
        char d[5000];
        memset(rut, '\0', 11);
        memset(nombre, '\0', 101);

        //Se lee rut y nombre//
        printf("Ingrese rut: ");
        scanf("%[^\n]s", rut);
        getchar();
        printf("Ingrese nombre: ");
        scanf("%[^\n]s", nombre);
        getchar();


        /*Se ingresan disponibilidad por días de la semana.
        Tambien se verifica si el dato es correcto       */
        printf("Por favor ingrese disponiblidad por persona: S = si, N = No\n");
        printf("Lunes: ");
        scanf("%[^\n]s", d);
        getchar();
        if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) porFavorIngreseAlgoValido(d);  
        if(d[0] == 'S'){
            disponibilidad[0] = 1;
        }else disponibilidad[0] = 0;

        printf("\nMartes: ");
        scanf("%[^\n]S", d);
        getchar();
        if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) porFavorIngreseAlgoValido(d);
        if(d[0] == 'S'){
            disponibilidad[1] = 1;
        }else disponibilidad[1] = 0;

        printf("\nMiercoles: ");
        scanf("%[^\n]s", d);
        getchar();
        if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) porFavorIngreseAlgoValido(d);
        if(d[0] == 'S'){
            disponibilidad[2] = 1;
        }else disponibilidad[2] = 0;

        printf("\nJueves: ");
        scanf("%[^\n]s", d);
        getchar();
        if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) porFavorIngreseAlgoValido(d);
        if(d[0] == 'S'){
            disponibilidad[3] = 1;
        }else disponibilidad[3] = 0;

        printf("\nViernes: ");
        scanf("%[^\n]s", d);
        getchar();
        if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) porFavorIngreseAlgoValido(d);
        if(d[0] == 'S'){
            disponibilidad[4] = 1;
        }else disponibilidad[4] = 0;

        printf("\nSabado: ");
        scanf("%[^\n]s", d);
        getchar();
        if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) porFavorIngreseAlgoValido(d);
        if(d[0] == 'S'){
            disponibilidad[5] = 1;
        }else disponibilidad[5] = 0;

        printf("\nDomingo: ");
        scanf("%[^\n]s", d);
        getchar();

        if( (d[0] != 'S') && (d[0] != 'N') || (d[1] != '\0') ) porFavorIngreseAlgoValido(d);
        if(d[0] == 'S'){
            disponibilidad[6] = 1;
        }else disponibilidad[6] = 0;
        printf("\n");

        /*Nombre, rut y disponiblidad se guardan en en variable dinamica aux
        y luego se realiza un pushback a la lista con aux*/
        printf("%s\n", rut);
        printf("%s\n", nombre);
        int i = 0;
        Bombero *auxB = (Bombero *) malloc(sizeof(Bombero) );
        //Bombero *auxB = (Bombero*) realloc(auxB,1 * sizeof(Bombero));
        if(auxB == NULL){
            printf("Error en inicializar memoria en funcion agregar bombero\n\n"); exit(1);
        }
        auxB->rut = (char *) malloc(11 * sizeof(char) );
        if(auxB->rut == NULL){
            printf("Error en inicializar rut en funcion agregar bombero\n");
        }
        auxB->nombre = (char *) malloc(101 * sizeof(char) );
        if(auxB->nombre == NULL){
            printf("Error en inicialiar nombre en funcion agregar bombero\n");

        }

        strcpy(auxB->rut, rut);
        while(rut[i] != '\0'){
            printf("%c", rut[i]);
            i++;
        }
        printf("\n");
        //for(i = 0; rut[i]; i++) auxB->rut[i] = rut[i];
        
        strcpy(auxB->nombre,nombre);
        for( i = 0; i < 7; i++){
            auxB->disponibilidad[i] = disponibilidad[i];
        }
        pushBack(listaBomberos,auxB);
        
    return;
}