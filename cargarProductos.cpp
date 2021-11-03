#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"


void cargarProductos(Prod allProds[]){

    /** Este es el proceso automatizado de colocar los registros en la estructura **/

    FILE *archivo;
    archivo = fopen("Precios.txt", "r");
    for(int i=0; !feof(archivo); i++){
        fread(&allProds[i], sizeof(Prod), 1, archivo);
        if(allProds[i].estado!=3){
            allProds[i].estado=0;
        }
    }
fclose(archivo);
}
