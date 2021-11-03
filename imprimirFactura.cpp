#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include "Estructuras.h"

void guardarFact(int cantFact, fact allFacts[]);
void cambiarRegistro(Prod allProds[], int cantProd);
void guardarLegibleFact(int cantFact, int o, fact allFacts[], int cantProd, Prod allProds[]);

int imprimirFacturacion(int cantFact, int o, fact allFacts[], int cantProd, Prod allProds[]){

    int that=0;
    float total;
    char siFact;
    char siG;

    time_t now = time(0);
    tm * time = localtime(&now);
    allFacts[cantFact].dia = time->tm_mday;
    allFacts[cantFact].mes = time->tm_mon + 1;
    allFacts[cantFact].year = time->tm_year - 100;
    allFacts[cantFact].estado = 0;
    allFacts[cantFact].limite=o;
    allFacts[cantFact].codigo=cantFact+1;
    system("cls");

    printf("Facturación: Proceso de impresión\n");
    printf("\t-----------------------------------------------------------------------------\n");
    printf("\t Cliente : %s\n", allFacts[cantFact].nombreCliente);
    printf("\t Fact #%d\n",allFacts[cantFact].codigo);
    printf("\t %d/%d/%d\n",allFacts[cantFact].dia, allFacts[cantFact].mes, allFacts[cantFact].year);
    printf("\t\t\t\t  ------------------------\n");
    printf("\t\t\t\t   Factura de tu tiendita \n");
    printf("\t\t\t\t  ------------------------\n");
    printf("\n");
    printf("\t|     PRODUCTO    |      PRECIO       |       CANTIDAD        |    MONTO    |\n");
    for(int i=0; i<o; i++){
        that=allFacts[cantFact].prod[i];
        float monto = allProds[that].precioVenta*allFacts[cantFact].cant[i];
        printf("\t\t%s\t\tC$%.2f\t\t\t%d\t\tC$ %.2f \n", allProds[that].nombre,
                                                         allProds[that].precioVenta,
                                                         allFacts[cantFact].cant[i],
                                                         monto);
            total += monto;
        }
    allFacts[cantFact].monto = total;
    printf("\n\t-----------------------------------------------------------------------------\n");
    printf("\t|Total:              |                                           C$ %.2f |",total);
    printf("\n\t-----------------------------------------------------------------------------\n");
    printf("\n\n");
    fflush(stdin);

    printf("¿Deseas imprimir? - (S/N)");
    scanf("%c", &siG);
    if(siG=='s' || siG=='S'){
        guardarLegibleFact(cantFact,o,allFacts,cantProd,allProds);
    }
    std::cin.ignore();fflush(stdin);

    printf("¿Desea guardar esta factura? - (S/N)");
    scanf("%c", &siFact);

    if(siFact=='s' || siFact=='S'){
        for(int i=0; i<o; i++){
            that=allFacts[cantFact].prod[i];
            allProds[that].cantidad-=allFacts[cantFact].cant[i];
        }

        cambiarRegistro(allProds, cantProd);
        guardarFact(cantFact, allFacts);
        printf("\nLa factura se ha guardado en el registro. \n");

        system("pause");

            return true;
        }



    return false;
}

/** Se da la vista final de la factura y se procede a cambiar los registros de los inventarios, para
restar del mismo y también, para registrar al final del todo la factura en el formato legible del programa. **/

void guardarLegibleFact(int cantFact, int o, fact allFacts[], int cantProd, Prod allProds[]){

    int that;
    float total=0;

    FILE *Legible;

    char Salida[7];
    sprintf(Salida, "Fact%d.txt",allFacts[cantFact].codigo);

    Legible = fopen(Salida,"a");

    fprintf(Legible,"\t-----------------------------------------------------------------------------\n");
    fprintf(Legible,"\t Cliente : %s\n", allFacts[cantFact].nombreCliente);
    fprintf(Legible,"\t Fact #%d\n",allFacts[cantFact].codigo);
    fprintf(Legible,"\t %d/%d/%d\n",allFacts[cantFact].dia, allFacts[cantFact].mes, allFacts[cantFact].year);
    fprintf(Legible,"\t\t\t\t  ------------------------\n");
    fprintf(Legible,"\t\t\t\t   Factura de tu tiendita \n");
    fprintf(Legible,"\t\t\t\t  ------------------------\n");
    fprintf(Legible,"\n");
    fprintf(Legible,"\t|     PRODUCTO    |      PRECIO       |       CANTIDAD        |    MONTO    |\n");
    for(int i=0; i<o; i++){
        that=allFacts[cantFact].prod[i];
        float monto = allProds[that].precioVenta*allFacts[cantFact].cant[i];
        fprintf(Legible,"\t\t%s\t\tC$%.2f\t\t\t%d\t\tC$ %.2f \n", allProds[that].nombre,
                                                         allProds[that].precioVenta,
                                                         allFacts[cantFact].cant[i],
                                                         monto);
            total += monto;
        }
    allFacts[cantFact].monto = total;
    fprintf(Legible,"\n\t-----------------------------------------------------------------------------\n");
    fprintf(Legible,"\t|Total:              |                                           C$ %.2f |",total);
    fprintf(Legible,"\n\t-----------------------------------------------------------------------------\n");
    fprintf(Legible,"\n\n");

    fclose(Legible);

    printf("\nLa factura se ha guardado en el archivo con el nombre %s \n\n",Salida);
}
