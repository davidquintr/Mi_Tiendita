#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"

void mostrarRegistro(Prod allProds[], int cantProd, int change);
void registrarProducto(Prod allProds[], int *cantProd3);
void editarProducto(Prod allProds[], int cantProd, Prod allEdits[10]);
void eliminarProducto(Prod allProds[], int cantProd, Prod allEdits[10]);
void restaurarProducto(Prod allProds[], int cantProd, Prod allEdits[10]);

void menuInventario (Prod allProds[], int *cantProd2){
    printf("Cargando...\n");
    int cantProd3=*cantProd2;

    int change=2;
    Prod allEdits[10];

    int opc;
    do{
        system("cls");
        printf("\t\t\t\t\t  ----------------------------- \n");
        printf("\t\t\t\t\t |      MI TIENDITA 1.0        |\n");
        printf("\t\t\t\t\t |    PRODUCTOS & REGISTROS    |\n");
        printf("\t\t\t\t\t  ----------------------------- \n");

        printf("\t[1] Agregar Producto   \n");
        printf("\t[2] Editar Producto    \n");
        printf("\t[3] Borrar Producto    \n");
        printf("\t[4] Restaurar Producto \n");
        printf("\t[5] Mostrar Registro   \n");
        printf("\t[6] Salir            \n\n");
        printf("Digite su elección > ");
        scanf("%i", &opc);

        switch(opc){
            case 1:
                registrarProducto(allProds, &cantProd3);
                *cantProd2=cantProd3;
                break;
            case 2:
                editarProducto(allProds, cantProd3, allEdits);
                break;
            case 3:
                eliminarProducto(allProds, cantProd3, allEdits);
                break;
            case 4:
                restaurarProducto(allProds, cantProd3, allEdits);
                break;
            case 5 :
                mostrarRegistro(allProds, cantProd3, change);
                break;
            case 6:
                break;
            default:
                printf("\nOpcion no disponible. \n");
                system("pause");
        }
    }while (opc != 6);
}
