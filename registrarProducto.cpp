#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "Estructuras.h"

bool verifNomRep(Prod allProds[], int cantProd, char nomProd[20]);
void establecerProducto(Prod allProds[], int cantProd, Prod newProd);

void registrarProducto(Prod allProds[], int *cantProd3){

    /** Esta es la manera de como se registra un producto a la estructura **/

    Prod newProd;
    bool verifIsRep=false;
    bool keepMenu=false;
    char siCant, siCancel;

    int opc;
    do{
        newProd.cantidad=0;
        verifIsRep=false;
        while(!verifIsRep){
            system("cls");
            printf("\t\t\t\t\t  ----------------------------- \n");
            printf("\t\t\t\t\t |      MI TIENDITA 1.0        |\n");
            printf("\t\t\t\t\t |    REGISTRAR PRODUCTO(S)    |\n");
            printf("\t\t\t\t\t  ----------------------------- \n");
            printf("Nombre del Producto : ");
            scanf("%s", newProd.nombre);
            verifIsRep=verifNomRep(allProds, *cantProd3, newProd.nombre);
        if(!verifIsRep){
                printf("Nombre de producto ya reservado. \n\n\n");
                system("pause");
            }
         }

         /** Al verificar que el nombre del producto no está repetido

         Te pide los datos como la cantidad de productos en disponibilidad y
         el precio, el precio está dividido por el precio compra y precio venta
         a través del precio de compra te sugiere el precio de venta

         ya luego puedes decidir si guardar o no, para hacerlo se auxilia de
         establecerProducto, ahí le estaría mandando los datos de la estructura
         para guardarlo finalmente en archivo**/

        printf("\n");
        printf("Precio de Compra : ");
        scanf("%f", &newProd.precioCompra);
        std::cin.ignore(); fflush(stdin);
        printf("\n");
        printf("Precio de venta sugerido : %.2f\n", newProd.precioCompra*1.2);
        printf("Precio de venta : ");
        scanf("%f", &newProd.precioVenta);
        std::cin.ignore(); fflush(stdin);

        fflush(stdin);
        printf("\n¿Deseas agregar la cantidad de producto(S/N)? - ");
        scanf("%c", &siCant);
        if(siCant=='S' || siCant=='s'){
            printf("Cantidad de producto: ");
            scanf("%i", &newProd.cantidad);
        }
        printf("\n\n");
        printf("\t[1] Guardar y salir \n");
        printf("\t[2] Guardar y agregar otro \n");
        printf("\t[3] Cancelar \n\n");
        printf("Digite su elección > ");
        scanf("%i", &opc);

        if(opc==1 || opc==2){
            establecerProducto(allProds, *cantProd3, newProd);
            *cantProd3=*cantProd3+1;
            printf("\nSe ha guardado con exito. \n");
            system("pause");
        }

        switch(opc){
            case 1:
                keepMenu=true;
                break;
            case 2:
                break;
            default:
                printf("\n¿Seguro que deseas descartar cambios(S/N)? - ");
                scanf("%s", &siCancel);
                if(siCancel=='S' || siCancel=='s'){
                    keepMenu=true;
                }
        }
    }while(!keepMenu);
}

/** Se pueden descartar los cambios, cancelar, agregar y guardar ... **/
