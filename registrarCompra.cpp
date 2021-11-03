#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Estructuras.h"

int buscarProducto(Prod allProds[], int cantProd, int change);
void cambiarRegistro(Prod allProds[], int cantProd);

void registrarCompra(Prod allProds[], int cantProd2){

    int o=0;
    int change=2;
    int masCant;

    o=buscarProducto(allProds, cantProd2, change);
    if(o>=0){
        printf("\nDigite la cantidad de producto que desea agregar. \n");
        printf("(presione 0 para Cancelar)\n> ");
        scanf("%i", &masCant);
        std::cin.ignore(); fflush(stdin);

        if(masCant>0){
            allProds[o].cantidad+=masCant;
            cambiarRegistro(allProds, cantProd2);
            printf("\nCantidad de producto aumentada con exito. \n");
            system("pause");
        }
    }
}
