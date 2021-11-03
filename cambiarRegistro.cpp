#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"

void cambiarRegistro(Prod allProds[], int cantProd){

        /** Guarda finalmente los datos de la estructura al archivo **/

    FILE *archivo;
    archivo = fopen("Precios.txt", "w");
    for(int i=0; i<cantProd; i++){
        fwrite(&allProds[i], sizeof(Prod), 1, archivo);
    }
fclose(archivo);
}
