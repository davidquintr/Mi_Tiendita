#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Estructuras.h"

int buscarProducto(Prod allProds[], int cantProd, int change);
void cambiarRegistro(Prod allProds[], int cantProd);

void eliminarProducto(Prod allProds[], int cantProd, Prod allEdits[10]){

    /** Una vez buscado, el producto es identificado, esto lo que hace es cambiar
    el estado de 0 o 1 a 3 que determina que el producto está "Eliminado", esto después
    al mostrar, se oculta de la visualización**/

    int o=0;
    int change=1;
    o=buscarProducto(allProds, cantProd, change);

    char siEliminar;

    if(o>=0){
        fflush(stdin);
        printf("Seguro que desea eliminar este producto(S/N)? - ");
        scanf("%c", &siEliminar);
        if(siEliminar == 'S' || siEliminar == 's'){
            allProds[o].estado = 3;
            for(int i=0; i<10; i++){
                if(allProds[o].id==allEdits[i].id){
                    allEdits[i].estado=0;
                }
            }
            cambiarRegistro(allProds, cantProd);
            printf("\nProducto eliminado con exito. \n");
            system("pause");
        }
    }
}
