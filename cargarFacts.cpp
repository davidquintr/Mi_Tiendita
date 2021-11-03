#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"


void cargarFacts(fact allFacts[]){

    /** Carga todos los datos de factura desde el archivo hasta estructura **/

    FILE *archivo;
    archivo = fopen("Facturas.txt", "r");
    for(int i=0; !feof(archivo); i++){
        fread(&allFacts[i], sizeof(fact), 1, archivo);
    }
fclose(archivo);
}
