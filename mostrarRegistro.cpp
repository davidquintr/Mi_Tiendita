#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"

void mostrarRegistro(Prod allProds[], int cantProd, int change){

    /** Esto sirve para mostrar el registro de los productos desde la estructura,
    los datos de la estructura han estado cargados previamente

    Se flexibilizó el uso de este módulo para varios módulos, depende de cuáles estén
    llamándolo, el texto cambia **/

    system("cls");
    printf("\t\t\t\t\t  ----------------------------- \n");
    printf("\t\t\t\t\t |       MI TIENDITA:RE        |\n");
    if(change==0)
        printf("\t\t\t\t\t |      LISTA DE PRDUCTOS      |\n");
    else if(change==1)
        printf("\t\t\t\t\t |         INVENTARIO          |\n");
    else
        printf("\t\t\t\t\t |    REGISTRO DE PRODUCTOS    |\n");
    printf("\t\t\t\t\t  ----------------------------- \n");
    printf("\n");
    if(cantProd!=0){
        printf("_______________________\n");
    }
    for(int i=0; i<cantProd; i++){
        fflush(stdin);
        if(allProds[i].estado !=3){
            if(change==0){
                printf("ID           : %i\n", allProds[i].id);
                printf("Nombre       : %s\n", allProds[i].nombre);
                printf("Precio Compra: %.2f\n", allProds[i].precioCompra);
                printf("Precio Venta : %.2f\n", allProds[i].precioVenta);
                printf("Cantidad     : %i\n", allProds[i].cantidad);
                printf("_______________________\n");
            } else if(change==1) {
                printf("ID         : %i\n", allProds[i].id);
                printf("Nombre     : %s\n", allProds[i].nombre);
                printf("Cantidad   : %i\n", allProds[i].cantidad);
                printf("_____________________\n");
            } else {
                printf("ID           : %i\n", allProds[i].id);
                printf("Nombre       : %s\n", allProds[i].nombre);
                printf("Precio Compra: %.2f\n", allProds[i].precioCompra);
                printf("Precio Venta : %.2f\n", allProds[i].precioVenta);
                printf("_______________________\n");
            }
        }
    }
    if(cantProd==0) {
        printf("No hay registro de productos");
    }
    printf("\n");
    system("pause");
}
