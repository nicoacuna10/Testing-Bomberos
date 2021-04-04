#include <stdio.h>

void menu(int *opcion){
    do{
    printf("Estacion de bomberos\n");
    printf("1. Agregar Bombero\n");
    printf("2. Despedir Bombero\n");
    printf("3. Buscar Bombero por dia\n");
    printf("4. Buscar Bombero por Rut\n");
    printf("5. Modificar disponibilidad de un Bombero\n");
    printf("6. Crear horario de la semana\n");
    printf("7. Mostrar horario de la semana\n");
    printf("8. Mostrar todods los Bomberos\n");
    printf("0. Salir\n\n");
    printf("Por favor ingrese un opción de 0 al 8: ");
    scanf("%d", opcion);
    while( (getchar() ) != '\n');

    }while( (*opcion < 0) || (*opcion > 8) );

    return;
}

