#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"

int encontrarCantProd(){

    /** Este es el proceso automatizado de encontrar las cantidades de productos
    en fichero, se usa una estructura temporal, en la que solo manda con return
    el dato de cuántos productos existen, es "i-1" porque el puntero añade un dato de demás **/

    int i=1;
    Prod notUsed;
    FILE *archivo;
    archivo = fopen("Precios.txt", "r");
    if(archivo == NULL){
        fclose(archivo);
        fopen("Precios.txt", "a");
    } else {
        for(i=0; !feof(archivo); i++){
            fread(&notUsed, sizeof(Prod), 1, archivo);
        }
    }

    fclose(archivo);
    return i-1;
}
