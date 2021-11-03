#include <iostream>
#include <stdio.h>

/*
      Aplicaci�n para la gesti�n de inventarios
                  "Mi tiendita"
      Versi�n 1.0 Estable

            Grupo #7 (Team Factorizaci�n)
                �Riuske Nishime Robleto
                �David Parrales Ponce
                �Erick Gonz�lez Gallegos
                �David Quintanilla Ruiz
    */

/** Este m�dulo sirve para entrelazar Login y seleccion de modo **/

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
    /** FFlog Determina que ya se hab�a realizado o se realiz� el
    proceso de configurar el primer inicio

    el valor l�gico Setup es el que determina si ya se realiz�
    correctamente la operaci�n de iniciar sesi�n, se lo contrario
    este m�dulo no ser� ejecutado.**/
