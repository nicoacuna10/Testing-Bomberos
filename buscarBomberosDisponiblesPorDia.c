#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
  int diasConTrabajo;
  int totalDeDiasDisponibles;
}Bombero;

void corroborarValidezDeDia(char *dia){
    /*Esta función sirve para saber que se ingreso días de lunes a viernes
      y no un día con nombre no válido. Ej: bvbwgsf o 1234.             */ 
    repetirFuncion: 
    for(int j = 0; dia[j]; j++){
        dia[j] = toupper(dia[j]);
    }

    if(!strcmp(dia,"LUNES") )     return;
    if(!strcmp(dia,"MARTES") )    return;
    if(!strcmp(dia,"MIERCOLES") ) return;
    if(!strcmp(dia,"JUEVES") )    return;
    if(!strcmp(dia,"VIERNES") )   return;
    if(!strcmp(dia,"SABADO") )    return;
    if(!strcmp(dia, "DOMINGO") )  return;

    printf("¡Ha escrito algo que no es un día de la semana!\n\n Por favor ingrese día de la semana: ");
    scanf("%s", dia);
    getchar();
    printf("\n");
    goto repetirFuncion;
}


void buscarBomberosDisponiblesPorDia(char *dia, List *listaBomberos){
    //Se ingresa y día y se corrobra que sea correcto//
    printf("\nIngrese dia para buscar bomberos disponibles: ");
    scanf("%[^\n]s", dia);
    getchar();
    printf("\n"); //Enter para que se vea mejor estéticamente//
    corroborarValidezDeDia(dia);
    int j, espacios;
    Bombero *aux;


    //Se imprimen los días de las personas que pueden en el día ingresado trabajar //
    printf("RUT            NOMBRE\n");

    aux = firstList(listaBomberos);
    /*Para cada día se hace lo siguiente: Se busca  corroborar la o las primeras letras
    del la cadena ingresada. Luego se va a ese día en particular y se va recorriendo la
    lista con cada una de las personas buscando si el día ingresado pueden trabajar o no.
    Luego se imprime con formato bonito usando la diferencia entre rut y espacios      */ 
    
    if(dia[0] == 'L'){
        while(aux!=NULL){
            if(aux->disponibilidad[0] == 1){
                espacios = 10 - strlen(aux->rut);
                if(espacios == 1){ printf(" "); } 
                printf("%s     %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'M' && dia[1] == 'A'){
        while(aux!=NULL){
            if(aux->disponibilidad[1] == 1){
                espacios = 10 - strlen(aux->rut);
                if(espacios == 1){ printf(" "); }
                printf("%s     %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'M' && dia[1] == 'I'){
        while(aux!=NULL){
            if(aux->disponibilidad[2] == 1){
                espacios = 10 - strlen(aux->rut);
                if(espacios == 1){ printf(" "); }
                printf("%s     %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'J'){
        while(aux!=NULL){
            if(aux->disponibilidad[3] == 1){
                espacios = 10 - strlen(aux->rut);
                if(espacios == 1){ printf(" "); }
                printf("%s     %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'V'){
        while(aux!=NULL){
            if(aux->disponibilidad[4] == 1){
                espacios = 10 - strlen(aux->rut);
                if(espacios == 1){ printf(" "); }
                printf("%s     %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'S'){
        while(aux!=NULL){
            if(aux->disponibilidad[5] == 1){
                espacios = 10 - strlen(aux->rut);
                if(espacios == 1){ printf(" "); }
                printf("%s     %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    if(dia[0] == 'D'){
        while(aux!=NULL){
            if(aux->disponibilidad[6] == 1){
                espacios = 10 - strlen(aux->rut);
                if(espacios == 1){ printf(" "); }
                printf("%s     %s\n", aux->rut, aux->nombre);
            }
            aux = nextList(listaBomberos);
        }
    }

    return;
}
