#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Estructuras.h"

int buscarProducto(Prod allProds[], int cantProd, int change);
void cambiarRegistro(Prod allProds[], int cantProd);

void darDeBaja(Prod allProds[], int cantProd2){

    int o=0;
    int change=3;
    int menosCant;

    o=buscarProducto(allProds, cantProd2, change);
    if(o>=0){
        printf("\nDigite la cantidad de producto que desea dar de baja. \n");
        printf("(presione 0 para Cancelar)\n> ");
        scanf("%i", &menosCant);
        std::cin.ignore(); fflush(stdin);

        if(menosCant>0){
            allProds[o].cantidad-=menosCant;
            cambiarRegistro(allProds, cantProd2);
            printf("\nCantidad de producto reducida con exito. \n");
            system("pause");
        }
    }
}
