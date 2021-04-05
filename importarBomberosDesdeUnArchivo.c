#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct{
  char* rut;
  char* nombre;
  int disponibilidad[7];
}Bombero;

char *get_csv_field (char * tmp, int k){
    int open_mark = 0;
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){

        if(tmp[i]== '\"'){
            open_mark = 1-open_mark;
            if(open_mark) ini_i = i+1;
            i++;
            continue;
        }

        if(open_mark || tmp[i]!= ','){
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }

        if(tmp[i]== ','){
            if(k==j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }

        i++;
    }

    if(k==j) {
       ret[i-ini_i] = 0;
       return ret;
    }


    return NULL;
}

List *importarBomberosDesdeUnArchivo(char *nombreArchivo, unsigned long long *talla){
    //Se ingresa ruta de la archivo ingresado// 
    printf("Ingrese nombre del archivo .csv: ");
    scanf("%[^\n]s", nombreArchivo);
    getchar();
    FILE *fp = fopen(nombreArchivo,"r");
    if(fp == NULL){
      printf("\nARCHIVO NO ENCONTRADO\n");
      exit(1);
    }


    char linea[1000];
    char *aux;
    Bombero *b;
    List *listaBomberos = createList();
    int i, j = 0;

    while(fgets (linea, 1000, fp) != NULL){
        b =(Bombero*)malloc(sizeof(Bombero));
        b->rut = malloc(10*sizeof(char));
        b->nombre = malloc(100*sizeof(char));

        //Se lee desde el archivo cvs los datos de las personas y se van agregando a la 'list'//
        //Se usa 'b' para guardar todos los datos del archivo csv por persona y se guardan en lista//
        for( i = 0; i < 9; i++) {
            if(i==0){
              b->rut = get_csv_field(linea,i);
              printf("%s ", b->rut);
            }
            if(i==1){
              b->nombre = get_csv_field(linea,i);
              printf("%s ", b->nombre);
            }

            if(i==2){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                b->disponibilidad[0] = 1;
              }else b->disponibilidad[0] = 0;
              printf("%d ", b->disponibilidad[0]);
            }
            if(i==3){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                b->disponibilidad[1] = 1;
              }else b->disponibilidad[1] = 0;
              printf("%d ", b->disponibilidad[1]);

            }
            if(i==4){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                b->disponibilidad[2] = 1;
              }else b->disponibilidad[2] = 0;
              printf("%d ", b->disponibilidad[2]);

            }
            if(i==5){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                b->disponibilidad[3] = 1;
              }else b->disponibilidad[3] = 0;

              printf("%d ", b->disponibilidad[3]);

            }
            if(i==6){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                b->disponibilidad[4] = 1;
              }else b->disponibilidad[4] = 0;

              printf("%d ", b->disponibilidad[4]);

            }
            if(i==7){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                b->disponibilidad[5] = 1;
              }else b->disponibilidad[5] = 0;

              printf("%d ", b->disponibilidad[5]);

            }
            if(i==8){
              aux = get_csv_field(linea,i);
              if(aux[0] == 'S'){
                b->disponibilidad[6] = 1;
              }else b->disponibilidad[6] = 0;

              printf("%d ", b->disponibilidad[6]);

            }

        }
        //Se coloca todo lo guardado con 'b' en la lista//
        pushBack(listaBomberos,b);
        j++;
        printf("\n\n");
    }

    (*talla) = j;
    //Creo que hay que hacerle free a 'b'//
    //free(b);
    return listaBomberos;
}
