#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void menu(int *opcion);
List *importarBomberosDesdeUnArchivo(List *listaBomberos, char *nombreArchivo);
void agregarBombero(char rut[11], char nombre[101], int disponibilidad[7], List *listaBomberos);
void eliminarBomberos(char *rut, List *listaBomberos);
void buscarBomberosDisponiblesPorDia(char *dia, List *listaBomberos);
void buscarBomberosPorRut(char *rut, List *listaBomberos);
void modificarDisponibilidadDeUnBombero(char *rut, int *disponibilidad, List *listaBomberos);
List *crearHorarioSemanal(List *listaBomberos, List *listOrdenada, Semana* planificacionSemanal);
void mostrarHorarioDeLaSemana(List *listaOrdenada, Semana planificacionSemanal[35]);
void mostrarTodosLosBomberosDeLaEstacion(List *listaBomberos);


int main(void){
    int opcion = 0;
    List *listaBomberos = createList();
    List *listaOrdenada = createList();
    Semana planificacionSemanal[35];
    char nombreArchivo[100];
    char rut[11], nombre[101], dia[9];
    int disponibilidad[7];
    memset(rut, '\0', 11);
    memset(nombre, '\0', 101);

    do{
        menu(&opcion);
        if(opcion == 0) break;
        if(opcion == 1) listaBomberos = importarBomberosDesdeUnArchivo(listaBomberos, nombreArchivo);
        if(opcion == 2) agregarBombero(rut,nombre,disponibilidad,listaBomberos);
        if(opcion == 3) eliminarBomberos(rut,listaBomberos);
        if(opcion == 4) buscarBomberosDisponiblesPorDia(dia,listaBomberos);
        if(opcion == 5) buscarBomberosPorRut(rut,listaBomberos);
        if(opcion == 6) modificarDisponibilidadDeUnBombero(rut,disponibilidad,listaBomberos);
        if(opcion == 7) listaOrdenada = crearHorarioSemanal(listaBomberos, listaOrdenada, planificacionSemanal);
        if(opcion == 8) mostrarHorarioDeLaSemana(listaOrdenada, planificacionSemanal);
        if(opcion == 9) mostrarTodosLosBomberosDeLaEstacion(listaBomberos);
        printf("\n\n");
    }while(opcion != 0);


    printf("¡Adios! ¡Que tenga buen dia !\n\n");
    free(listaBomberos);
    free(listaOrdenada);
    return 0;
}