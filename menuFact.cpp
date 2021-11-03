#include <stdio.h>
#include <stdlib.h>

#include "Estructuras.h"

int encontrarCantFact();
void cargarFacts(fact allFacts[]);
void mostrarFacts(int cantProd, Prod allProds[], int cantFacts, fact allFacts[]);
void facturacion(int cantProd, Prod allProds[], int *cantFacts, fact allFacts[]);

void menuFact(int cantProd, Prod allProds[]){

    int cantFacts;
    cantFacts = encontrarCantFact();
    fact allFacts[cantFacts+15];
    cargarFacts(allFacts);

    int opc;
    do{
        system("cls");
        printf("\t\t\t\t\t  ----------------------------- \n");
        printf("\t\t\t\t\t |      MI TIENDITA 1.0        |\n");
        printf("\t\t\t\t\t |     MENU DE FACTURACION     |\n");
        printf("\t\t\t\t\t  ----------------------------- \n");

        printf("\t[1] Mostrar facturas   \n");
        printf("\t[2] Facturar           \n");
        printf("\t[3] Volver            \n\n");
        printf("> ");
        scanf("%i", &opc);

        switch(opc){
            case 1:
                mostrarFacts(cantProd, allProds, cantFacts, allFacts);
                break;
            case 2:
                facturacion(cantProd, allProds, &cantFacts, allFacts);
                break;
        }
    }while(opc!=3);
}
