#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <string.h>

using namespace std;

void first_login(char pass[25],char user[25],bool &FFlog){

    /** Este módulo configura el primer inicio del programa, lo hace
    detectando si el archivo "userdata.bin" existe, si es así entonces
    salta todo esto y carga a las variables "Pass, User" los valores
    que se encuentran el archivo.

    Si no existe el archivo, procede a configurar unas credenciales
    para un posterior acceso. **/

    setlocale(LC_ALL, "spanish");

    FILE *login;
    login=fopen("userdata.bin","r");
    char tuser[25];
    char tpass[25];
    char tsetup[25];
    int status;

    fscanf(login,"%s %s %s",user,pass,tsetup);

    if(login==NULL || tsetup==NULL){
        login=fopen("userdata.bin","w");

        printf("\t\t*****************\n");
        printf("\t\t* Primer inicio *\n");
        printf("\t\t*****************\n\n");

        printf("Crear un nombre de usuario: \n>");
        scanf("%s",tuser);
        printf("\n");
        fflush(stdin);

        do{
                if(status==1){
                    printf("\t\t*****************\n");
                    printf("\t\t* Primer inicio *\n");
                    printf("\t\t*****************\n");
                }

        printf("Crear una contraseña: \n>");
        scanf("%s",tpass);
        printf("\n");
        fflush(stdin);

        char ttpass[25];
        printf("Confirme la contraseña: \n>");
        scanf("%s",ttpass);

            if(strcmp(tpass,ttpass)!=0){
                system("cls");
                printf("Contraseña incorrecta!, ingrese de nuevo.\n\n");
                status=1;
            }
            else{
                fprintf(login, "%s %s %s",tuser,tpass,tsetup);
                status=0;
            }


        }while(status==1);

    }

    else{
        FFlog=true;
        printf("Cargando...");
        fscanf(login,"%s %s %s",user,pass,tsetup);
    }
    fclose(login);
}
