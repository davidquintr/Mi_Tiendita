#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"

int contar=0;

void guardarEdits(Prod allProds[], Prod allEdits[10], int o){

    /** Ocupar un arreglo de Prod Auxiliar que guarda los productos
    originales para poder restaurarlo, esto solo es usado por editarProducto **/

    bool idRep;

    for(int i=0; i<10;i++){
        if(allEdits[i].id==allProds[o].id){
            allEdits[i].id = allProds[o].id;
            strcpy(allEdits[i].nombre, allProds[o].nombre);
            allEdits[i].precioCompra = allProds[o].precioCompra;
            allEdits[i].precioVenta = allProds[o].precioVenta;
            idRep=true;
        }
    }
    if(!idRep){
        allEdits[contar].estado = 2;
        allEdits[contar].id = allProds[o].id;
        strcpy(allEdits[contar].nombre, allProds[o].nombre);
        allEdits[contar].precioCompra = allProds[o].precioCompra;
        allEdits[contar].precioVenta = allProds[o].precioVenta;
        contar++;
    }

}
