#include <iostream>
#include "ListaClientes.h"
#include <stdio.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    ListaClientes *Clientes = new ListaClientes();

    Clientes->insertar_dato("Jose","premium","con pito grande",19,"pito grande","Guatemala");
    Clientes->id_actual++;
    Clientes->insertar_dato("Manuel","premium","con pito pequeño",19,"pito pequeño","Guatemala");
    Clientes->id_actual++;
    Clientes->insertar_dato("Koka","premium","con pito grande",19,"pito grande","Guatemala");

    cout << "\n \n Hello world! \n \n \n" << endl;
    Clientes->mostrar_datos();




    return 0;
}
