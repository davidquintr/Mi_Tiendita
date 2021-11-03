#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Estructuras.h"

void menuInventario(Prod allProds[], int *cantProd2);
void registrarCompra(Prod allProds[], int cantProd);
void darDeBaja(Prod allProds[], int cantProd);
void mostrarRegistro(Prod allProds[], int cantProd, int change);

using namespace std;

void gestionarInventario(Prod allProds[], int *cantProd){

    printf("Cargando...\n");
    int cantProd2 = *cantProd;
    int change=1;

    int opc;
    do{
        system("cls");
        printf("\t\t\t\t\t  ----------------------------- \n");
        printf("\t\t\t\t\t |      MI TIENDITA 1.0        |\n");
        printf("\t\t\t\t\t |    GESTIÓN DE INVENTARIO    |\n");
        printf("\t\t\t\t\t  ----------------------------- \n");

        printf("\t[1] Gestionar Productos     \n");
        printf("\t[2] Registrar Compra        \n");
        printf("\t[3] Dar de baja un producto \n");
        printf("\t[4] Mostrar inventario      \n");
        printf("\t[5] Atrás                 \n\n");
        printf("Digite su elección > ");
        scanf("%i", &opc);
        cin.ignore(); fflush(stdin);

        switch(opc){
            case 1:
                menuInventario(allProds, &cantProd2);
                *cantProd=cantProd2;
                break;
            case 2:
                registrarCompra(allProds, cantProd2);
                break;
            case 3:
                darDeBaja(allProds, cantProd2);
                break;
            case 4:
                mostrarRegistro(allProds, cantProd2, change);
                break;
            case 5:
                break;
            default:
                printf("\nOpcion no disponible. \n");
                system("pause");
        }
    }while (opc != 5);

}
