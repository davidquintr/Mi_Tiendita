#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Estructuras.h"

void cambiarRegistro(Prod allProds[], int cantProd);

void restaurarEliminado(Prod allProds[], int cantProd, Prod allEdits[10]){

    bool hayEliminados, foundProd;
    int idBusca=0;

    printf("\t\t\t\t\t  ----------------------------- \n");
    printf("\t\t\t\t\t |       MI TIENDITA:RE        |\n");
    printf("\t\t\t\t\t |     RESTAURAR ELIMINADO     |\n");
    printf("\t\t\t\t\t  ----------------------------- \n");

    for(int i=0; i<cantProd; i++){
        fflush(stdin);
        if(allProds[i].estado ==3){
            printf("LISTA DE PRODUCTOS ELIMINADOS: \n");
            printf("_______________________\n");
            printf("ID           : %i\n", allProds[i].id);
            printf("Nombre       : %s\n", allProds[i].nombre);
            printf("Precio Compra: %.2f\n", allProds[i].precioCompra);
            printf("Precio Venta : %.2f\n", allProds[i].precioVenta);
            printf("Cantidad     : %i\n", allProds[i].cantidad);
            hayEliminados = true;
        }
    }
    if(hayEliminados){
        printf("_______________________\n\n");
        printf("Digite el ID del producto que desea restaurar. \n");
        printf("(presione 0 para Cancelar)\n> ");
        scanf("%i", &idBusca);
        if(idBusca!=0){
            for(int i=0; i<cantProd; i++){
                if(allProds[i].id==idBusca){
                    foundProd=true;
                    if(allProds[i].estado==3){
                        allProds[i].estado=0;
                        for(int o=0; o<10; o++){
                            if(allProds[i].id==allEdits[o].id){
                                allEdits[o].estado=2;
                            }
                        }
                        cambiarRegistro(allProds, cantProd);
                        printf("\nProducto restaurado con exito. \n");
                    } else{
                        printf("\nEste ID corresponde a un producto habilitado. \n");
                    }
                }
            }
            if(!foundProd){
                printf("\nID no registrado. \n");
            }
        }
    } else
        printf("No hay productos eliminados. \n");
}
