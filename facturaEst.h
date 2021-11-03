#ifndef FACTURAEST_H_INCLUDED
#define FACTURAEST_H_INCLUDED


struct fact{
    int estado=0;
    int codigo;
    char nombreCliente[20];
    float monto;
    int year;
    int mes;
    int dia;
    //Detalle de la factura
    int prod[10];
    int cant[10];
    int limite;
};



#endif // FACTURAEST_H_INCLUDED
