#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"

void mostrarFacts(int cantProd, Prod allProds[], int cantFact, fact allFacts[]){

    int a;
    system("cls");
    for(int o=0; o<cantFact; o++){

        printf("\t-----------------------------------------------------------------------------\n");
        printf("\t| Cliente: %s | Fact #%d | Fecha: %d/%d/%d |\n",allFacts[o].nombreCliente,
                                                                            allFacts[o].codigo,
                                                                            allFacts[o].dia,
                                                                            allFacts[o].mes,
                                                                            allFacts[o].year);
        printf("\t\t\t\t  ------------------------\n");
        printf("\t\t\t\t   Factura de tu tiendita \n");
        printf("\t\t\t\t  ------------------------\n");
        printf("\n");
        printf("\t|     PRODUCTO    |      PRECIO       |       CANTIDAD        |    MONTO    |\n");

        for(int i=0; i<allFacts[o].limite; i++){
            a = allFacts[o].prod[i];
        printf("\t\t%s\t\tC$%.2f\t\t\t%d\t\tC$ %.2f \n",allProds[a].nombre,
                                                        allProds[a].precioVenta,
                                                        allFacts[o].cant[i],
                                                       (allFacts[o].cant[i]*allProds[a].precioVenta));
            }
        printf("\n\tTotal : C$ %.2f \n",allFacts[o].monto);
        printf("\n\n\n");
    }
    printf("\t-----------------------------------------------------------------------------\n");
    system("pause");
}
