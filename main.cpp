#include <iostream>
#include <stdio.h>

/*
      Aplicación para la gestión de inventarios
                  "Mi tiendita"
      Versión 1.0 Estable

            Grupo #7 (Team Factorización)
                •Riuske Nishime Robleto
                •David Parrales Ponce
                •Erick González Gallegos
                •David Quintanilla Ruiz
    */

/** Este módulo sirve para entrelazar Login y seleccion de modo **/

using namespace std;

int first_login(char pass[25],char user[25],bool &FFlog);
void setup_login(char pass[25],char user[25],bool &setup);
void seleccion_modo(char user[]);

int main()
{

    system("color 70");
    bool FFlog=false;
    char pass[25];
    char user[25];
    bool setup=false;

    first_login(pass,user,FFlog);



    if(FFlog==true){
        setup_login(pass,user,setup);
    }

    if(setup == true){
    seleccion_modo(user);
    }
}
    /** FFlog Determina que ya se había realizado o se realizó el
    proceso de configurar el primer inicio

    el valor lógico Setup es el que determina si ya se realizó
    correctamente la operación de iniciar sesión, se lo contrario
    este módulo no será ejecutado.**/
