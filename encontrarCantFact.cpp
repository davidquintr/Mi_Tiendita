#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"

int encontrarCantFact(){

    /** Encuentra la cantidad de facturas registradas y retorna (i - 1) por la
    ubicación del puntero**/

    int i=1;
    fact notUsed;
    FILE *archivo;
    archivo = fopen("Facturas.txt", "r");
    if(archivo == NULL){
        fclose(archivo);
        fopen("Facturas.txt", "a");
    } else {
        for(i=0; !feof(archivo); i++){
            fread(&notUsed, sizeof(fact), 1, archivo);
        }
    }

    fclose(archivo);
    return i-1;
}
