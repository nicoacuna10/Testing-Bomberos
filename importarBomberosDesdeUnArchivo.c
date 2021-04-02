#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//void copiarCadena(Bombero *b, Bombero *vector, unsigned long long j);

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

List *importarBomberosDesdeUnArchivo(char * bomberos, unsigned long long *talla){
    FILE *fp = fopen("bomberos.csv","r");
    char linea[1000];
    char *a;
    Bombero *aux;
    List *list = createList();
    int i, j = 0;

    while(fgets (linea, 1000, fp) != NULL){

        for( i = 0; i < 9; i++) {
            if(i==0){
              aux->rut = get_csv_field(linea,i);
              printf("%s ", aux->rut);
            }
            if(i==1){
              aux->nombre = get_csv_field(linea,i);
              printf("%s ", aux->nombre);
            }

            if(i==2){
              a = get_csv_field(linea,i);
              if(a[0] == 'S'){
                aux->disponibilidad[0] = 1;
              }else aux->disponibilidad[0] = 0;
              printf("%d ", aux->disponibilidad[0]);
            }
            if(i==3){
              a = get_csv_field(linea,i);
              if(a[0] == 'S'){
                aux->disponibilidad[1] = 1;
              }else aux->disponibilidad[1] = 0;
              printf("%d ", aux->disponibilidad[1]);
            }
            if(i==4){
              a = get_csv_field(linea,i);
              if(a[0] == 'S'){
                aux->disponibilidad[2] = 1;
              }else aux->disponibilidad[2] = 0;
              printf("%d ", aux->disponibilidad[2]);

            }
            if(i==5){
              a = get_csv_field(linea,i);
              if(a[0] == 'S'){
                aux->disponibilidad[3] = 1;
              }else aux->disponibilidad[3] = 0;
              printf("%d ", aux->disponibilidad[3]);

            }
            if(i==6){
              a = get_csv_field(linea,i);
              if(a[0] == 'S'){
                aux->disponibilidad[4] = 1;
              }else aux->disponibilidad[4] = 0;
              printf("%d ", aux->disponibilidad[4]);
            }
            if(i==7){
              a = get_csv_field(linea,i);
              if(a[0] == 'S'){
                aux->disponibilidad[5] = 1;
              }else aux->disponibilidad[5] = 0;
              printf("%d ", aux->disponibilidad[5]);

            }
            if(i==8){
              a = get_csv_field(linea,i);
              if(a[0] == 'S'){
                aux->disponibilidad[6] = 1;
              }else aux->disponibilidad[6] = 0;
              printf("%d ", aux->disponibilidad[6]);

            }
            if(list == NULL){
                pushFront(list, aux);
            }else pushBack(list, aux);
        }

        //Copiamos rut y nombre a vector.
        //copiarCadena(b,vector, j);

        j++;
        printf("\n\n");
    }

    (*talla) = j;
    return list;
}
