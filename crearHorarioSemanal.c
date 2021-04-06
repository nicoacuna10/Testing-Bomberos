#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct{
    char* rut;
    char* nombre;
    int disponibilidad[7];
    int totalDeDiasDisponibles;
    int diasConTrabajo;
}bombero;

/*
void intercambiarNodos(bombero *aux){
    bombero *auxPtr = aux;
    //El previo del siguiente pasa a tener el previo del actual//
    aux->next->prev = auxPtr->prev;
    aux->next->next = auxPtr;
    aux->next = auxPtr->next->next;



    return; 
}
*/

int comparar(const void *a, const void *b){
    int *ptrA = (int *)a;
    int *ptrB = (int *)b;
    return ( (*ptrA) - (*ptrB) );
}

void crearHorarioSemanal(List *listaBomberos, List *planificacionSemanal){
    /*Como en las funciones anteriores nunca se inicializó 'diasContrabajo' 
    ahora lo hacemos con toda la lista con ceros. Esto es con el fin de 
    usar esta variable como un contador de cuantes veces hemos asignado a
    una persona a trabajar un dia. La gracia que se haga esto acá es con 
    el fín de que cada vez que se solicita crear un horario semanal, este
    inicialice siempre a todas las personas sin carga administrativa.
    O sea 'diasConTrabajo' = 0                                          */ 
    int diasQueSePuedeTrabajar = 0, i = 0, j = 0;
    unsigned long long totalBomberos = 0;
    bombero *aux = firstList(listaBomberos);

    while(aux != NULL){
        aux->diasConTrabajo = 0;
        aux->totalDeDiasDisponibles = 0;
        totalBomberos++;
        aux = nextList(listaBomberos);
    }

    //Testing para ver si el código realizó 'diasConTrabajo' = 0//
    aux = firstList(listaBomberos);
    while(aux != NULL){
        printf("%d - ", aux->diasConTrabajo);
        aux = nextList(listaBomberos);
    }
    printf("Total bomberos: %llu\n\n", totalBomberos);
    //Fin testing// 


    //Se inicializa memoria para vector que guarda en cada casilla el total de 'diasConTrabajo' de cada persona//
    int *vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar = (int *) malloc(totalBomberos * sizeof(int) );
    if(vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar == NULL){
         printf("Error en inicializa memoria en funcion crearHorarioSemanal\n\n");
         exit(1);
    }
    
    //Se guarda en 'totalDeDiasDisponibles' la cantidad de dias que las personas pueden trabajar//
    aux = firstList(listaBomberos);
    while(aux != NULL){
        for(i = 0; i < 7; i++)
            if(aux->disponibilidad[i] == 1) aux->totalDeDiasDisponibles++;
        vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar[j] = aux->totalDeDiasDisponibles;
        j++;
        aux = nextList(listaBomberos); 
    }
    
    j = 0; //MIRAR SI AL FINAL DE TODO ESTA INSTRUCION NO ES NECESARIA//

    //Testing//
    printf("Vector: ");
    for(i = 0; vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar[i]; i++){
        printf("%d - ", vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar[i]);
    }
    printf("\n\n");
    //Fin testing// 

    //TESTING PARA SABER SI TOTALDEDIASDISPONIBLES SE GUARDÓ CORRECTAMENTE//
    aux = firstList(listaBomberos);
    printf("TotalDisponibilidad: ");
    while(aux != NULL){
        printf("%d - ", aux->totalDeDiasDisponibles);
        aux = nextList(listaBomberos);
    }
    //FIN TESTING//

    //Se realiza quickSort a vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar//
    qsort(vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar, totalBomberos, sizeof(int), comparar);

    //Testing//
    printf("\n\n");
    printf("Vector: ");
    for(i = 0; vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar[i]; i++){
        printf("%d - ", vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar[i]);
    }
    printf("\n\n");
    //Fin testing// 


    j = 0;
    i = 0;
    aux = firstList(listaBomberos);
    while(aux != NULL){

        if(aux->totalDeDiasDisponibles == vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar[i]){
            pushBack(planificacionSemanal,aux);
            i++;
        }

        if(i == totalBomberos) break;
        aux = nextList(listaBomberos);        
        if(aux == NULL) aux =firstList(listaBomberos);
    }

    aux = firstList(planificacionSemanal);
    while(aux != NULL){
        printf("%s\n", aux->nombre);
        aux = nextList(planificacionSemanal);
    }

    /*
    //Se ordena lista  con bubblesort desde las que personas que tienen menos disponibilidad a las que tienen más//
    aux = firstList(listaBomberos);
    for(i = 0; i < (totalBomberos - 1); i++){
       for(j = 0; j < (totalBomberos - i - 1); j++){
            if(aux->totalDeDiasDisponibles > aux->next->totalDeDiasDisponibles)
                intercambiarNodos(aux);
            aux = nextList();
       }
       aux =first(listaBomberos);
       for(int k = 0; k < i; k++){
           aux = nextList();
       }
    }

    */

    return;
}