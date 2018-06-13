#include <iostream>
#include "ListaClientes.h"
#include <stdio.h>
#include "ClientesAleatorios.h"

using namespace std;

int main()
{
       cout << "Hello world!" << endl;

       NodoClientes *Clientes;
       ListaClientes *lista_cliente = new ListaClientes();


       ClientesAleatorios *ho = new ClientesAleatorios();

       Clientes = ho->crearclientes(lista_cliente->id_actual);
        cout << " \n \n \n " << endl;

        lista_cliente->insertar_datos(Clientes);
        lista_cliente->id_actual++;

        Clientes = ho->crearclientes(lista_cliente->id_actual);
        lista_cliente->insertar_datos(Clientes);
        lista_cliente->id_actual++;

        lista_cliente->mostrar_datos();







    return 0;
}
