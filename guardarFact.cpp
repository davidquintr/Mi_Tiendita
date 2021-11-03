#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"

void guardarFact(int cantFact, fact allFacts[]){

    /** Guarda finalmente los datos de la estructura al archivo **/

    FILE *archivo;
    archivo = fopen("facturas.txt", "a+");

    fwrite(&allFacts[cantFact], sizeof(fact), 1, archivo);

    fclose(archivo);
}
