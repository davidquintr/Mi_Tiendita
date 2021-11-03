#include <iostream>
#include "Estructuras.h"

using namespace std;

int encontrarCantProd();
void cargarProductos(Prod allProds[]);
void gestionarInventario(Prod allProds[], int *cantProd);
void menuFact(int cantProd, Prod allProds[]);
void mostrarRegistro(Prod allProds[], int cantProd, int change);

/** Este es el módulo principal, que interconecta los dos grandes bloques
 de funciones, Inventario y Facturación**/


void seleccion_modo(char user[]){

    int cantProd;
    cantProd=encontrarCantProd();
    Prod allProds[cantProd+15];
    cargarProductos(allProds);

    int change=0;

    int opc;
    do{
        system("cls");

        printf("Bienvenido, %s\n",user);
        printf("\t\t\t\t\t  ----------------------------- \n");
        printf("\t\t\t\t\t |      MI TIENDITA 1.0        |\n");
        printf("\t\t\t\t\t |       MENU PRINCIPAL        |\n");
        printf("\t\t\t\t\t  ----------------------------- \n");

        printf("\t[1] Inventario  \n");
        printf("\t[2] Facturación \n");
        printf("\t[3] Lista de productos \n");
        printf("\t[4] Cerrar sesión \n");
        printf("\nDigite su elección > ");
        scanf("%d",&opc);
        cin.ignore(); fflush(stdin);

        switch(opc){
            case 1:
                gestionarInventario(allProds, &cantProd);
                break;
            case 2:
                menuFact(cantProd, allProds);
                break;
            case 3:
                mostrarRegistro(allProds, cantProd, change);
                break;
            case 4:
                break;
            default:
                printf("\nOpcion no disponible. \n");
                system("pause");
        }
    }while(opc!=4);

            printf("\n\t Se cerrará la sesión\n");
            system("PAUSE");
}
