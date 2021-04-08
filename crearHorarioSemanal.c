#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct{
    char* rut;
    char* nombre;
    int disponibilidad[7];
    int totalDeDiasDisponibles;
    int diasConTrabajo;
}Bombero;

typedef struct{
char nombre[101];

}Semana;


int comparar(const void *a, const void *b){
    int *ptrA = (int *)a;
    int *ptrB = (int *)b;
    return ( (*ptrA) - (*ptrB) );
}

List *crearHorarioSemanal(List *listaBomberos, List *listaOrdenada, Semana* planificacionSemanal){
    /*Como en las funciones anteriores nunca se inicializó 'diasContrabajo' 
    ahora lo hacemos con toda la lista con ceros. Esto es con el fin de 
    usar esta variable como un contador de cuantes veces hemos asignado a
    una persona a trabajar un dia. La gracia que se haga esto acá es con 
    el fín de que cada vez que se solicita crear un horario semanal, este
    inicialice siempre a todas las personas sin carga administrativa.
    O sea 'diasConTrabajo' = 0                                          */ 
    int diasQueSePuedeTrabajar = 0, i = 0, j = 0;
    unsigned long long totalBomberos = 0;


    /*Se borra primero todo el contenido de 'planificacionSemanal' en caso de haberse ejecutado esta función
    más de una vez.                                                                                       */
    cleanList(listaOrdenada);



    Bombero *aux = firstList(listaBomberos);
    while(aux != NULL){
        aux->diasConTrabajo = 0;
        aux->totalDeDiasDisponibles = 0;
        totalBomberos++;
        aux = nextList(listaBomberos);
    }



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



    //Se realiza quickSort a vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar//
    qsort(vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar, totalBomberos, sizeof(int), comparar);


    //En esta sección se guarda en 'listaOrdeanda' las personas desde las que pueden trabajar menos hasta las que pueden más//
    j = 0;
    i = 0;
    aux = firstList(listaBomberos);
    while(aux != NULL){

        if(aux->totalDeDiasDisponibles == vectorConCantidadTotalDeDiasQuePersonasPuedenTrabajar[i]){
            pushBack(listaOrdenada, aux);
            i++;
        }
        if(i == totalBomberos) break;
        aux = nextList(listaBomberos);        
        if(aux == NULL) aux =firstList(listaBomberos);
    }



    i = 0;
    j = 0;
    int contador = 0;
    aux = firstList(listaOrdenada);
    //El bucle se sale cuando se llena el horario de trabajo semanal//
    while(i != 35){
        
        //Lunes//
        if( (i >= 0) && (i < 5) ){
            if( (aux->disponibilidad[0] == 1) && (aux->diasConTrabajo < 5) && (aux->diasConTrabajo < aux->totalDeDiasDisponibles) ){
                strcpy(planificacionSemanal[i].nombre, aux->nombre);
                i++;
            }
        }

        //Martes//
        if( (i >= 5) && (i < 10) ){
            if( (aux->disponibilidad[1] == 1 )&& (aux->diasConTrabajo < 5) && (aux->diasConTrabajo < aux->totalDeDiasDisponibles) ){
                strcpy(planificacionSemanal[i].nombre, aux->nombre);
                i++;
            }
        }

        //Miercoles//
        if( (i >= 10) && (i < 15) ){
            if( (aux->disponibilidad[2] == 1) && (aux->diasConTrabajo < 5) && (aux->diasConTrabajo < aux->totalDeDiasDisponibles) ){
                strcpy(planificacionSemanal[i].nombre, aux->nombre);
                i++;
            }
        }

        //Jueves//
        if( (i >= 15) && (i < 20) ){
            if( (aux->disponibilidad[3] == 1) && (aux->diasConTrabajo < 5) && (aux->diasConTrabajo < aux->totalDeDiasDisponibles) ){
                strcpy(planificacionSemanal[i].nombre, aux->nombre);
                i++;
            }
        }

        //Viernes//
        if( (i >= 20) && (i < 25) ){
            if( (aux->disponibilidad[4] == 1) && (aux->diasConTrabajo < 5) && (aux->diasConTrabajo < aux->totalDeDiasDisponibles) ){
                strcpy(planificacionSemanal[i].nombre, aux->nombre);
                i++;
            }
        }

        //Sabado//
        if( (i >= 25) && (i < 30) ){
            if( (aux->disponibilidad[5] == 1) && (aux->diasConTrabajo < 5) && (aux->diasConTrabajo < aux->totalDeDiasDisponibles) ){
                strcpy(planificacionSemanal[i].nombre, aux->nombre);
                i++;
            }
        }

        //Domingo//
        if( (i >= 30) && (i < 35) ){
            if( (aux->disponibilidad[6] == 1) && (aux->diasConTrabajo < 5) && (aux->diasConTrabajo < aux->totalDeDiasDisponibles) ){
                strcpy(planificacionSemanal[i].nombre, aux->nombre);
                i++;
            }
        }

        /*Esta sección está para cuando se llegaron a buscar el máximo 
        número de combinaciones posibles para crear la semana, si es que 
        mal no lo estoy pensando. De todas maneras es un número grande y sirve
        de testing. Pero hay que revisar si es matematicamente consistente!! */
        contador++;
        if(contador > (totalBomberos * 7)){
            printf("No se puede crear horario con las personas ingresadas\n\n");
            cleanList(listaOrdenada);
            return listaOrdenada;
        }

        aux = nextList(listaOrdenada);
        //Se reinicia 'aux' para empezar a buscar en la lista de nuevo//
        if(aux == NULL) aux = firstList(listaOrdenada);
    }


    //Si el programa fue existoso se entrega la lista ordenada. HAY QUE VER SI ES NECESARIO PARECE QUE YA NO :P //
    printf("\n\n¡Horario semanal creado exitosamente!\n");
    return listaOrdenada;
}