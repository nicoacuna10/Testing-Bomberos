#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void menu(int *opcion);
List *importarBomberosDesdeUnArchivo(char *, unsigned long long *talla);
//void copiarCadena(Bombero *b, Bombero *vector, unsigned long long j);
//List *agregarBombero(char rut[10], char *nombre, int disponibilidad[] );
void eliminarBomberos(char *rut, Bombero *vector, unsigned long long *talla);
//void buscarBomberosDisponiblesPorDia(char *dia);
//void buscarBomberosPorRut(char *rut);
//void modificarDisponibilidadDeUnBombero(char *rut, int disponibilidad[] );
//void crearHorarioSemanal(void);
//void mostrarHorarioDeLaSemana(void );
//void mostrarTodosLosBomberosDeLaEstacion(Bombero *vector, unsigned long long talla);


int main(void){
    int opcion = 0, i;
    List* list = NULL;
    unsigned long long talla;
    char rut[10];

    list = importarBomberosDesdeUnArchivo("bomberos.csv", &talla);


    do{
        menu(&opcion);
        getchar();
        if(opcion == 0) break;
        //if(opcion == 1) agregarBombero();
        //if(opcion == 2) eliminarBomberos(rut,vector, &talla);
        //if(opcion == 3) buscarBomberosDisponiblePorDia();
        //if(opcion == 4) buscarBomberosPorRut();
        //if(opcion == 5) modificarDisponibilidadDeUnBombero();
        //if(opcion == 6) crearHorarioSemanal();
        //if(opcion == 7) mostrarHorarioDelaSemana();
//        if(opcion == 8) mostrarTodosLosBomberosDeLaEstacion(vector, talla);

        printf("\n\n");
    }while(opcion != 0);


    printf("TOTAL BOMBEROS: %llu\n", talla);

    return 0;
}
