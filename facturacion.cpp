#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"

int evaluarSimi(Prod allProds[], int cantProd);
int imprimirFacturacion(int cantFacts, int o, fact allFacts[], int cantProd, Prod allProds[]);

void facturacion(int cantProd, Prod allProds[], int *cantFacts, fact allFacts[]){

    /** Función principal de Facturación

    Básicamente lo que hace es un llamado al módulo evaluarSimi para hacer la búsqueda de ID
    y ocuparlo para realizar la hermosa factura.

    Nuestra factura dará una vista previa cada vez que agregamos un producto, al hacer esta acción
    podemos añadir la cantidad.**/

    int cantFact=*cantFacts;
    int o=0;
    int p[10];




    bool used[cantProd];
    char siFact;
    bool imFact = false;
    int i;
    bool done;

    for(int i = 0 ; i < cantProd ; i++){
        used[i] = false;
    }

    do{
        system("cls");
        printf("\t\t\t\t\t  ----------------------------- \n");
        printf("\t\t\t\t\t |      MI TIENDITA 1.0        |\n");
        printf("\t\t\t\t\t |     RELIZAR FACTURACION     |\n");
        printf("\t\t\t\t\t  ----------------------------- \n");
        printf("\t\t\t\t\t    %d Productos Registrados\n",cantProd);
        printf("\t\t\t\t\t     %d Facturas registradas\n\n",cantFact);

        i = evaluarSimi(allProds, cantProd);

        if(i>=0 && !used[i] && allProds[i].estado!=3){
            printf("--------------------\n");
            printf("El producto es %s\n", allProds[i].nombre);
            printf("Precio: %.2f\n", allProds[i].precioVenta);
            printf("Disponibles: %i\n", allProds[i].cantidad);
            printf("--------------------\n");
            printf("Digite la cantidad de productos.\n");
            printf("(0 para cancelar)\n");
            printf("> "); scanf("%i", &allFacts[cantFact].cant[o]);
            if(allFacts[cantFact].cant[o]!=0){
                if(allFacts[cantFact].cant[o]<=allProds[i].cantidad){
                    used[i]=true;
                    printf("\n");
                    printf("________________________________________________\n");
                    printf("Producto    |   Precio   |   Cantidad |  Monto  |\n");

                    for(int a = 0; a<=o; a++){
                        allFacts[cantFact].prod[o] = i;
                        p[o] = allFacts[cantFact].prod[o];
                        float monto = allProds[p[a]].precioVenta*allFacts[cantFact].cant[a];
                        printf("%s\t\t%.2f\t\t%i\t%.2f\n", allProds[p[a]].nombre,
                                                         allProds[p[a]].precioVenta,
                                                         allFacts[cantFact].cant[a],
                                                         monto);
                    }
                    o++;
                    fflush(stdin);
                    printf("\n\n¿Desea imprimir factura(S/N)? - ");
                    scanf("%c", &siFact);
                    if(siFact=='S' || siFact=='s'){
                        imFact=true;
                    }

                }
                else {
                    printf("Se excede la cantidad de productos disponibles\n\n");
                    system("pause");
                }
            }

            if(imFact){
                printf("\nDigite el nombre del cliente: ");
                scanf("%s", allFacts[cantFact].nombreCliente);
                done=imprimirFacturacion(cantFact, o, allFacts, cantProd, allProds);
                if(done){
                    *cantFacts=cantFact+1;
                }
                i=-2;
            }
        } else if(i!=-2){
            printf("\nProducto ya utlizado o no se encuentra en el registro.\n");
            system("pause");
        }
   }while(i!=-2);
}
