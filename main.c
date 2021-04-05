#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

void menu(int *opcion);
List *importarBomberosDesdeUnArchivo(char *nombreArchivo, unsigned long long *talla);
void agregarBombero(char *rut, char *nombre, int *disponibilidad, List *listaBomberos);
void eliminarBomberos(char *rut, List *listaBomberos, unsigned long long *talla);
void buscarBomberosDisponiblesPorDia(char *dia, List *listaBomberos);
void buscarBomberosPorRut(char *rut, List *listaBomberos);
void modificarDisponibilidadDeUnBombero(char *rut, int *disponibilidad, List *listaBomberos);
void crearHorarioSemanal();
void mostrarHorarioDeLaSemana();
void mostrarTodosLosBomberosDeLaEstacion(List *listaBomberos);


int main(void){
    int opcion = 0;
    unsigned long long talla;
    List *listaBomberos = createList();
    char nombreArchivo[100];
    char rut[11], nombre[101], dia[9];
    int disponibilidad[7];
    memset(rut, '\0', 11);
    memset(nombre, '\0', 101);


    listaBomberos = importarBomberosDesdeUnArchivo(nombreArchivo, &talla);

    do{
        menu(&opcion);
        if(opcion == 0) break;
        if(opcion == 1){ agregarBombero(rut,nombre,disponibilidad,listaBomberos); talla++;}
        if(opcion == 2) eliminarBomberos(rut,listaBomberos, &talla);
        if(opcion == 3) buscarBomberosDisponiblesPorDia(dia,listaBomberos);
        if(opcion == 4) buscarBomberosPorRut(rut,listaBomberos);
        if(opcion == 5) modificarDisponibilidadDeUnBombero(rut,disponibilidad,listaBomberos);
        if(opcion == 6) crearHorarioSemanal();
        if(opcion == 7) mostrarHorarioDeLaSemana();
        if(opcion == 8) mostrarTodosLosBomberosDeLaEstacion(listaBomberos);

        printf("\n\n");
    }while(opcion != 0);


    printf("TOTAL BOMBEROS: %llu\n\n", talla);
    printf("¡Adios! ¡Que tenga buen día !\n\n");
    return 0;
}

