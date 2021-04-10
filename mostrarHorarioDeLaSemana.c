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

typedef struct{
char nombre[101];

}Semana;

void mostrarHorarioDeLaSemana(List *listaOrdenada, Semana planificacionSemanal[35]){
    //Primero se verifica si se creo una lista en 'listaOrdenada'; o sea si se ingreso a la opción 6//    
    Bombero *aux = firstList(listaOrdenada);
    if(aux == NULL){
        printf("Por favor selecione la opcion crear horario antes de ingresar a esta opcion");
        return;
    }


    //Impresión de horario de la semana//
    for(int i = 0; i < 35; i++){
        if(i == 0)  printf("\n\nLUNES\n");
        if(i == 5)  printf("\n\nMARTES\n");
        if(i == 10) printf("\n\nMIERCOLES\n");
        if(i == 15) printf("\n\nJUEVES\n");
        if(i == 20) printf("\n\nVIERNES\n");
        if(i == 25) printf("\n\nSABADO\n");
        if(i == 30) printf("\n\nDOMINGO\n");

        printf("%s\n", planificacionSemanal[i].nombre);
    }

    cleanList(listaOrdenada);
    return;
}