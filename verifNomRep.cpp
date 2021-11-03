#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Estructuras.h"


bool verifNomRep(Prod allProds[], int cantProd, char nomProd[20]){

    /** Verifica si hay un nombre repetido dentro de los inventarios **/

    for(int i=0; i<=cantProd; i++ ){
        if(strcmp(nomProd,allProds[i].nombre) == 0){
            return false;
        }
    }
return true;
}
