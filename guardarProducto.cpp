#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"


void cambiarRegistro(Prod allProds[], int cantProd);

void establecerProducto(Prod allProds[], int cantProd, Prod newProd){

    /** Toma los productos que se han puesto y lo pasa al arreglo principal y luego
    lo guarda **/

    allProds[cantProd].id = cantProd+1;
    allProds[cantProd].estado = 1;
    strcpy(allProds[cantProd].nombre,newProd.nombre);
    allProds[cantProd].precioCompra = newProd.precioCompra;
    allProds[cantProd].precioVenta = newProd.precioVenta;
    allProds[cantProd].cantidad = newProd.cantidad;
    cantProd++;

    cambiarRegistro(allProds, cantProd);
}
