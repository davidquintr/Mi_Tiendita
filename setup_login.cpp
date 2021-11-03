#include <stdio.h>
#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

void setup_login(char pass[25],char user[25],bool &setup){

    system("cls");
    setlocale(LC_ALL, "spanish");

    char tuser[25];
    char tpass[25];
    int status[1];
    int counter=5;

        printf("\t\t---------------------\n");
        printf("\t\t* Inicio de sesión *\n");
        printf("\t\t---------------------\n");

    /* El inicio de sesion, no tiene mucha relevancia y solo se ocupa como
    manera simbolica de acceso al programa, no hace falta ser un genio para
    descubrir sus credenciales*/

do{
    if(status[0]==1){
        printf("\t\t---------------------\n");
        printf("\t\t* Inicio de sesión *\n");
        printf("\t\t---------------------\n");
    }

    system("color 70");
    printf("Usuario: \n>");
    scanf("%s",tuser);
    if(strcmp(tuser,user)==0){
        status[0]=0;
        system("cls");
    }

    else{
        system("cls");
        printf("Usuario incorrecto, repita\n\n");
        system("color 74");
        status[0]=1;
    }

}while(status[0]==1);

    do{
        if(counter==0){
            printf("  ------------------------------------------------------- \n");
            printf(" * Fuera del rango de intentos, el programa será cerrado *\n");
            printf("  ------------------------------------------------------- \n");
            exit(0);
        }

        printf("\t\t---------------------\n");
        printf("\t\t* Inicio de sesión *\n");
        printf("\t\t---------------------\n");
            system("color 70");
            printf("\n");
            printf("Contraseña: \n>");
            scanf("%s", tpass);

            if(strcmp(pass,tpass)==0){
                setup=true;
                printf("\nAcceso Obtenido");
                status[1]=0;
            }
            else{
                system("cls");
                printf("Contraseña incorrecta");
                counter--;
                /** Cantidad de intentos limitados a 5 **/
                printf("| Intentos restantes %d\n\n",counter);
                system("color 74");
                status[1]=1;
            }

    }while(status[1]==1);

    /** Este programa obtiene dos estados con otros dos sub-estados, cuando se ingresa la
    el usuario correcto se salta de Status 0 a 1 - estos poseen dos fases, que son cuando
    estos mismos son incorrectos**/

    /** Este mismo manda el valor modificado del booleano setup, que manda a iniciar las
    operaciones del programa. **/
}
