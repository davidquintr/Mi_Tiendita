#include <stdio.h>
#include <stdlib.h>

#include "Prod.h"

int encontrarCantProd();
void cargarProductos(Prod allProds[]);
void mostrarRegistro(Prod allProds[], int cantProd);
void registrarProducto(Prod allProds[], int *cantProd);

void main_inventario(){

    printf("Cargando...\n");
    int opc;
    int cantProd;
    cantProd=encontrarCantProd();
    Prod allProds[cantProd+15];
    cargarProductos(allProds);

    do{
    system("cls");
    printf("\t\t\t\t\t  ----------------------------- \n");
    printf("\t\t\t\t\t |       MI TIENDITA:RE        |\n");
    printf("\t\t\t\t\t |    PRODUCTOS & REGISTROS    |\n");
    printf("\t\t\t\t\t  ----------------------------- \n");

    printf("[1] Agregar Producto. \n");
    printf("[2] Editar Producto. \n");
    printf("[3] Borrar Producto. \n");
    printf("[4] Mostrar Registro.\n");
    printf("[5] Guardar Registro. -En mantenimiento-\n");
    printf("[6] Salir.\n\n");
    printf("Digite su elección: ");
    scanf("%i", &opc);
    system("cls");

    switch(opc){
        case 1:
            registrarProducto(allProds, &cantProd);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4 :
            mostrarRegistro(allProds, cantProd);
            break;
        case 5 :
            break;
    }
}while (opc != 6);

}
