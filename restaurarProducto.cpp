#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras.h"

void restaurarModificado(Prod allProds[], int cantProd, Prod allEdits[10]);
void restaurarEliminado(Prod allProds[], int cantProd, Prod allEdits[10]);

void restaurarProducto(Prod allProds[], int cantProd, Prod allEdits[10]){

    int opc;
    do{
        system("cls");
        printf("\t\t\t\t\t  ----------------------------- \n");
        printf("\t\t\t\t\t |       MI TIENDITA:RE        |\n");
        printf("\t\t\t\t\t |     RESTAURAR  PRODUCTO     |\n");
        printf("\t\t\t\t\t  ----------------------------- \n");
        printf("[1] Eliminados \n");
        printf("[2] Modificados recientemente \n");
        printf("[3] Salir \n\n");
        printf("Digite su eleccion > ");
        scanf("%i", &opc);
        system("cls");
        switch(opc){
            case 1:
                restaurarEliminado(allProds, cantProd, allEdits);
                system("pause");

                break;
            case 2:
                restaurarModificado(allProds, cantProd, allEdits);
                system("pause");
                break;
            case 3:
                break;
            default:
                printf("\nOpcion no disponible. \n");
                system("pause");
        }
    }while(opc!=3);
}
