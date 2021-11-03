#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"

void cambiarRegistro(Prod allProds[], int cantProd);

void restaurarModificado(Prod allProds[], int cantProd, Prod allEdits[10]){

    bool hayModificados, foundProd;
    int idBusca=0;

    printf("\t\t\t\t\t  ----------------------------- \n");
    printf("\t\t\t\t\t |       MI TIENDITA:RE        |\n");
    printf("\t\t\t\t\t |    RESTAURAR  MODIFICADO    |\n");
    printf("\t\t\t\t\t  ----------------------------- \n");

    for(int i=0; i<10; i++){
        fflush(stdin);
        if(allEdits[i].estado == 2){
            if(!hayModificados){
                printf("LISTA DE PRODUCTOS MODIFICADOS: \n");
            }
            printf("_______________________\n");
            printf("ID           : %i\n", allEdits[i].id);
            printf("Nombre       : %s\n", allEdits[i].nombre);
            printf("Precio Compra: %.2f\n", allEdits[i].precioCompra);
            printf("Precio Venta : %.2f\n", allEdits[i].precioVenta);
            hayModificados=true;
        }
    }
    if(hayModificados) {
        printf("_______________________\n\n");
        printf("Digite el ID del producto que desea restaurar. \n");
        printf("(presione 0 para Cancelar)\n");
        printf("> "); scanf("%i", &idBusca);
        if(idBusca!=0){
            for(int i=0; i<cantProd; i++){
                if(allProds[i].id==idBusca){
                    foundProd=true;
                    if(allProds[i].estado==2){
                        for(int o=0; o<10; o++){
                            if(allProds[i].id == allEdits[o].id){
                                allEdits[o].estado=0;
                                allProds[i].estado=0;
                                strcpy(allProds[i].nombre, allEdits[o].nombre);
                                allProds[i].precioCompra = allEdits[o].precioCompra;
                                allProds[i].precioVenta = allEdits[o].precioVenta;
                                cambiarRegistro(allProds, cantProd);
                                printf("\nProducto restaurado con exito. \n");
                            }
                        }
                    } else{
                        printf("\nEste ID corresponde a un producto no editado. \n");
                    }
                }
            }
            if(!foundProd){
                printf("\nID no registrado. \n");
            }
        }
    } else{
        printf("No hay productos modificados recientemente. \n");
    }
}
