#include <stdio.h>
#include <string.h>

void menu(int *opcion){
    char entrada[5000];
    int numero;

    do{
    memset(entrada, '\0', 1000);
    printf("Estacion de bomberos\n");
    printf("1. Importar Bomberos\n");
    printf("2. Agregar Bombero\n");
    printf("3. Despedir Bombero\n");
    printf("4. Buscar Bombero por dia\n");
    printf("5. Buscar Bombero por Rut\n");
    printf("6. Modificar disponibilidad de un Bombero\n");
    printf("7. Crear horario de la semana\n");
    printf("8. Mostrar horario de la semana\n");
    printf("9. Mostrar todods los Bomberos\n");
    printf("0. Salir\n\n");
    printf("Por favor ingrese un opcion de 0 al 9: ");
    scanf("%[^\n]s", entrada);
    getchar();
    numero = entrada[0] - 48; //Diferencia ascii para conseguir entradas precisas para numeros enteros//
    if( ( (numero < 0) || (numero > 9) ) || entrada[1] != '\0' ) printf("Opcion no valida!\n\n");
    (*opcion) = numero; // Se entrega a 'opcion' el valor de numero//

    //Si cadena es más grande que un solo caracter o no está entre 0 y 9 se continua en el bucle //
    }while( (*opcion < 0) || (*opcion > 9) || entrada[1] != '\0');  

    return;
}