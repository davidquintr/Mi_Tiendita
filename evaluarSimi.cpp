#include <iostream>
#include <string.h>

#include "Estructuras.h"

int evaluarSimi(Prod allProds[], int cantProd){

    /** Este es el proceso avanzado de la búsqueda de productos por ID o por Nombres **/

    int opc;
    int id;
    char nombre[20];
    char backChar[20];
    int masSimi=-1;
    int o=0;

    printf("Buscar producto por: \n");
    printf("\t[1] Nombre         \n");
    printf("\t[2] ID             \n");
    printf("\t[3] Descartar     \n\n");
    printf("Digite su elección > ");
    scanf("%i", &opc);
    printf("\n");

    switch(opc){
        case 1:
                /** La búsqueda de nombre y coincidencia funciona con una calificacion interna
                se toma el nombre del producto ingresado por el usuario, luego se califica,
                este proceso se hace dividiendo cada uno de los carácteres y su extensión
                a base de lo ingresado por el usuario.

                Esto se compara con el registro de productos, y lo divide de igual manera como
                lo hace con el producto del usuario

                Para conseguir la calificacion se divide 100/longitud(del producto ingresado)
                esto, si coinciden cada uno de los carácteres dará igual a 100% de coincidencia

                para mostrar al usuario una respuesta requiere del 60% de coincidencia.
                Lo único que se manda de regreso es el ID del producto encontrado**/


            printf("Digite el nombre del producto: ");
            scanf("%s", nombre);
            for(int e=0; e<cantProd; e++){
                if(allProds[e].estado!=3){
                    strcpy(backChar,allProds[e].nombre);
                    int longitud = strlen(nombre);
                    float calificacion= (100/longitud);
                    float caliFin=0;

                    for(int i=0; i<longitud; i++){
                        if(nombre[i]==backChar[i]){
                            caliFin+=calificacion;
                        }
                    }
                    while(caliFin>o){
                        masSimi=e;
                        o++;
                    }
                }
            }
            break;
        case 2:

            /** Esta es la búsqueda por ID simple, básicamente lo que hace es compararla
            con la que está en la estructura y la manda de regreso al módulo que la llama**/

            printf("Digite el id del producto: ");
            scanf("%i", &id);
            std::cin.ignore(); fflush(stdin);
            for(int i=0; i<cantProd; i++){
                if(allProds[i].id==id && allProds[i].estado!=3){
                    masSimi=i;
                }
            }
            break;
        case 3:
            masSimi=-2;
            break;
    }
return masSimi;
}
