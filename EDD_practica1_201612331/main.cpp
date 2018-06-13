#include <iostream>
#include "ListaClientes.h"
#include <stdio.h>
#include "ClientesAleatorios.h"
#include "ListaEquipaje.h"
#include "NodoClientes.h"
#include "NodoEquipaje.h"
#include "equipajeAleatorio.h"

using namespace std;

int main()
{
       cout << "Hello world!" << endl;

       NodoClientes *Clientes;
       ListaClientes *lista_cliente = new ListaClientes();

       NodoEquipaje *Equipaje;
       ListaEquipaje *lista_equipaje = new ListaEquipaje();

       cout << " \n \n \n ------------------------" << endl;
        ClientesAleatorios *ho = new ClientesAleatorios();

        Clientes = ho->crearclientes(lista_cliente->id_actual);
        lista_cliente->insertar_datos(Clientes);
        lista_cliente->id_actual++;

        Clientes = ho->crearclientes(lista_cliente->id_actual);
        lista_cliente->insertar_datos(Clientes);
        lista_cliente->id_actual++;

        lista_cliente->mostrar_datos();
        cout << " \n \n \n  ---------------------------" << endl;

        equipajeAleatorio *ho_1 = new equipajeAleatorio();

        Equipaje = ho_1->crearequipaje(lista_equipaje->id_actual);
        lista_equipaje->agregar_datos(Equipaje);
        lista_equipaje->id_actual++;

        Equipaje = ho_1->crearequipaje(lista_equipaje->id_actual);
        lista_equipaje->agregar_datos(Equipaje);
        lista_equipaje->id_actual++;

        lista_equipaje->mostrar_datos();


    return 0;
}
