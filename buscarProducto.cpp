#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Estructuras.h"

int evaluarSimi(Prod allProds[], int cantProd);

int buscarProducto(Prod allProds[], int cantProd, int change){

    /** Buscar simplemente un producto por ID y nombre, se auxilia del módulo evaluarSimi **/

    int i;
    bool keepBucle=false;
    bool salir;
    char thatProd, repeat;

    do{
        system("cls");
        printf("\t\t\t\t\t  ----------------------------- \n");
        printf("\t\t\t\t\t |      MI TIENDITA 1.0        |\n");
        if(change==0)
            printf("\t\t\t\t\t |      EDITAR PRODUCTOS       |\n");
        else if(change==1)
            printf("\t\t\t\t\t |     ELIMINAR  PRODUCTOS     |\n");
        else if(change==2)
            printf("\t\t\t\t\t |      REGISTRAR COMPRAS      |\n");
        else
            printf("\t\t\t\t\t |         DAR DE BAJA         |\n");
        printf("\t\t\t\t\t  ----------------------------- \n");

        i=evaluarSimi(allProds, cantProd);

        if(i==-2){
            salir=true;
            keepBucle=true;
        }

        if(i>=0){
            salir=true;
            if(change<2){
            printf(">> ID | Nombre | Precio de compra | Precio de venta <<\n");
            printf("   %i   %s       %.2f               %.2f\n\n",
            allProds[i].id,
            allProds[i].nombre,
            allProds[i].precioCompra,
            allProds[i].precioVenta);
            } else {
            printf(">> ID | Nombre | cantidad <<\n");
            printf("   %i   %s      %i\n\n",
            allProds[i].id,
            allProds[i].nombre,
            allProds[i].cantidad);
            }
            fflush(stdin);
            printf("¿Este es el producto que deseaba encontrar(S/N)? - ");
            scanf("%c", &thatProd);
            if(thatProd == 's' || thatProd == 'S'){
                keepBucle=true;
            } else {
                fflush(stdin);
                printf("\n¿Desea buscarlo otra vez(S/N)? - ");
                scanf("%c", &repeat);
                printf("\n\n");
                if(repeat != 's' && repeat != 'S'){
                    keepBucle=true;
                    i=-2;
                }
            }
        }
        if(!salir){
            printf("\nProducto no encontrado en el registro\n");
                fflush(stdin);
                printf("\n¿Desea buscarlo otra vez(S/N)? - ");
                scanf("%c", &repeat);
            if(repeat != 's' && repeat != 'S'){
                keepBucle=true;
                i=-2;
            }
        }
    }while(!keepBucle);

return i;
}
