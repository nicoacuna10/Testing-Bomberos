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

void porFavorIngreseAlgoValido(char entrada[5000]){
    //Esta función verifica que los datos ingresados sean validos//
    do{
        memset(entrada, '\0', 5000);
        printf("Por favor Ingrese elementos VALIDOS\n");
        printf("Solo puede ser S mayuscula o N Mayuscula\n\n");
        printf("Por favor ingrese su opcion: ");
        scanf("%[^\n]s", entrada);
        getchar();
    }while( (entrada[0] != 'S') && (entrada[0] != 'N')  || (entrada[1] != '\0') );
    return;
}

void agregarBombero(char rut[11], char nombre[101], int disponibilidad[7], List* listaBomberos){
        char entrada[5000];
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
        scanf("%[^\n]s", entrada);
        getchar();
        if( (entrada[0] != 'S') && (entrada[0] != 'N') || (entrada[1] != '\0') ) porFavorIngreseAlgoValido(entrada);  
        if(entrada[0] == 'S'){
            disponibilidad[0] = 1;
        }else disponibilidad[0] = 0;

        printf("\nMartes: ");
        scanf("%[^\n]S", entrada);
        getchar();
        if( (entrada[0] != 'S') && (entrada[0] != 'N') || (entrada[1] != '\0') ) porFavorIngreseAlgoValido(entrada);
        if(entrada[0] == 'S'){
            disponibilidad[1] = 1;
        }else disponibilidad[1] = 0;

        printf("\nMiercoles: ");
        scanf("%[^\n]s", entrada);
        getchar();
        if( (entrada[0] != 'S') && (entrada[0] != 'N') || (entrada[1] != '\0') ) porFavorIngreseAlgoValido(entrada);
        if(entrada[0] == 'S'){
            disponibilidad[2] = 1;
        }else disponibilidad[2] = 0;

        printf("\nJueves: ");
        scanf("%[^\n]s", entrada);
        getchar();
        if( (entrada[0] != 'S') && (entrada[0] != 'N') || (entrada[1] != '\0') ) porFavorIngreseAlgoValido(entrada);
        if(entrada[0] == 'S'){
            disponibilidad[3] = 1;
        }else disponibilidad[3] = 0;

        printf("\nViernes: ");
        scanf("%[^\n]s", entrada);
        getchar();
        if( (entrada[0] != 'S') && (entrada[0] != 'N') || (entrada[1] != '\0') ) porFavorIngreseAlgoValido(entrada);
        if(entrada[0] == 'S'){
            disponibilidad[4] = 1;
        }else disponibilidad[4] = 0;

        printf("\nSabado: ");
        scanf("%[^\n]s", entrada);
        getchar();
        if( (entrada[0] != 'S') && (entrada[0] != 'N') || (entrada[1] != '\0') ) porFavorIngreseAlgoValido(entrada);
        if(entrada[0] == 'S'){
            disponibilidad[5] = 1;
        }else disponibilidad[5] = 0;

        printf("\nDomingo: ");
        scanf("%[^\n]s", entrada);
        getchar();

        if( (entrada[0] != 'S') && (entrada[0] != 'N') || (entrada[1] != '\0') ) porFavorIngreseAlgoValido(entrada);
        if(entrada[0] == 'S'){
            disponibilidad[6] = 1;
        }else disponibilidad[6] = 0;
        printf("\n");




        /*Nombre, rut y disponiblidad se guardan en en variable dinamica aux
        y luego se realiza un pushback a la lista con aux*/
        int i = 0;
        Bombero *aux = (Bombero *) malloc(sizeof(Bombero) );
        if(aux == NULL){
            printf("Error en inicializar memoria en funcion agregar bombero\n\n"); exit(1);
        }
        aux->rut = (char *) malloc(11 * sizeof(char) );
        if(aux->rut == NULL){
            printf("Error en inicializar rut en funcion agregar bombero\n");
        }
        aux->nombre = (char *) malloc(101 * sizeof(char) );
        if(aux->nombre == NULL){
            printf("Error en inicialiar nombre en funcion agregar bombero\n");

        }

        //Se copian rut y nombre a 'aux'//
        strcpy(aux->rut, rut);
        strcpy(aux->nombre,nombre);

        //Se copian los valores de disponibilidad a 'aux'//
        for( i = 0; i < 7; i++){
            aux->disponibilidad[i] = disponibilidad[i];
        }

        //Se agrega  persona a lista//
        pushBack(listaBomberos,aux);
        
    return;
}