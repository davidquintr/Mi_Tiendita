#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include "Estructuras.h"

int buscarProducto(Prod allProds[], int cantProd, int change);
void guardarEdits(Prod allProds[], Prod allEdits[10], int o);
bool verifNomRep(Prod allProds[], int cantProd, char nomProd[20]);
void cambiarRegistro(Prod allProds[], int cantProd);

void editarProducto(Prod allProds[], int cantProd, Prod allEdits[10]){

    int o=0;
    int change=0;
    o=buscarProducto(allProds, cantProd, change);

    char nomProd[20];
    bool nomUsed;

    int opc=0;
    if(o>=0){
        printf("\nEditar ___ del producto: \n");
        printf("[1] Nombre         \n");
        printf("[2] Precio Compra  \n");
        printf("[3] Precio venta   \n");
        printf("[4] Cancelar     \n\n");
        printf("Digite su elección > ");
        scanf("%i", &opc);
        std::cin.ignore(); fflush(stdin);

        printf("\n");
    }
    if(opc>1 && opc<4){
        allProds[o].estado=2;
        guardarEdits(allProds, allEdits, o);
    }
    switch(opc){
        case 1:
            printf("Digite el nuevo nombre: ");
            scanf("%s", nomProd);
            nomUsed=verifNomRep(allProds, cantProd, nomProd);
            if(nomUsed){
                allProds[o].estado=2;
                guardarEdits(allProds, allEdits, o);
                strcpy(allProds[o].nombre, nomProd);
                cambiarRegistro(allProds, cantProd);
                printf("\nProducto editado con exito. \n");
            } else{
                printf("\nNombre de producto reservado. \n");
            }
            system("pause");
        break;
        case 2:
           printf("Digite el nuevo precio de compra: ");
            scanf("%f", &allProds[o].precioCompra);
            std::cin.ignore(); fflush(stdin);
        break;
        case 3:
            printf("Digite el nuevo precio de venta: ");
            scanf("%f", &allProds[o].precioVenta);
            std::cin.ignore(); fflush(stdin);
        break;
    }
    if(opc>1 && opc<4){
        cambiarRegistro(allProds, cantProd);
        printf("\nProducto editado con exito. \n");
        system("pause");
    }
}
