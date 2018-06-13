#include <iostream>
#include <stdio.h>

#include "ListaClientes.h"
#include "ClientesAleatorios.h"
#include "ListaEquipaje.h"
#include "NodoClientes.h"
#include "NodoEquipaje.h"
#include "equipajeAleatorio.h"
#include "ListaPaqueteria.h"
#include "NodoPaqueteria.h"
#include "paqueteriaAleatoria.h"
#include "ListaVuelo.h"
#include "NodoVuelo.h"
#include "vuelosAleatorios.h"
#include "empleadosAleatorios.h"
#include "NodoEmpleados.h"
#include "ListaEmpleados.h"


using namespace std;

int main()
{
       cout << "Hello world!" << endl;

       NodoClientes *Clientes;
       ListaClientes *lista_cliente = new ListaClientes();

       NodoEquipaje *Equipaje;
       ListaEquipaje *lista_equipaje = new ListaEquipaje();

       NodoPaqueteria *paquete;
       ListaPaqueteria *lista_paqueteria = new ListaPaqueteria();

       NodoVuelo *vuelo;
       ListaVuelo *lista_vuelo = new ListaVuelo();

       NodoEmpleados *empleado;
       ListaEmpleados *lista_empleado = new ListaEmpleados();


        ClientesAleatorios *ho = new ClientesAleatorios();

        Clientes = ho->crearclientes(lista_cliente->id_actual);
        lista_cliente->insertar_datos(Clientes);
        lista_cliente->id_actual++;

        Clientes = ho->crearclientes(lista_cliente->id_actual);
        lista_cliente->insertar_datos(Clientes);
        lista_cliente->id_actual++;

        lista_cliente->mostrar_datos();


        equipajeAleatorio *ho_1 = new equipajeAleatorio();

        Equipaje = ho_1->crearequipaje(lista_equipaje->id_actual);
        lista_equipaje->agregar_datos(Equipaje);
        lista_equipaje->id_actual++;

        Equipaje = ho_1->crearequipaje(lista_equipaje->id_actual);
        lista_equipaje->agregar_datos(Equipaje);
        lista_equipaje->id_actual++;

        lista_equipaje->mostrar_datos();



        paqueteriaAleatoria *ho_2 = new paqueteriaAleatoria();

        paquete = ho_2->crearpaquete(lista_paqueteria->id_actual);
        lista_paqueteria->ingresar_dato(paquete);
        lista_paqueteria->id_actual++;


        paquete = ho_2->crearpaquete(lista_paqueteria->id_actual);
        lista_paqueteria->ingresar_dato(paquete);
        lista_paqueteria->id_actual++;

       lista_paqueteria->Mostrar_datos();



        vuelosAleatorios *ho_3 = new vuelosAleatorios();

        vuelo = ho_3->agregarvuelo(lista_vuelo->id_actual);
        lista_vuelo->ingresar_datos(vuelo);
        lista_vuelo->id_actual++;


        vuelo = ho_3->agregarvuelo(lista_vuelo->id_actual);
        lista_vuelo->ingresar_datos(vuelo);
        lista_vuelo->id_actual++;

        vuelo = ho_3->agregarvuelo(lista_vuelo->id_actual);
        lista_vuelo->ingresar_datos(vuelo);
        lista_vuelo->id_actual++;

         lista_vuelo->mostrar_datos();



        empleadosAleatorios *ho_4 = new empleadosAleatorios();

        empleado = ho_4->crearempleados(lista_empleado->id_actual);
        lista_empleado->ingresar_datos(empleado);
        lista_empleado->id_actual++;

        empleado = ho_4->crearempleados(lista_empleado->id_actual);
        lista_empleado->ingresar_datos(empleado);
        lista_empleado->id_actual++;

        empleado = ho_4->crearempleados(lista_empleado->id_actual);
        lista_empleado->ingresar_datos(empleado);
        lista_empleado->id_actual++;


         lista_empleado->mostrar_datos();

    return 0;
}
