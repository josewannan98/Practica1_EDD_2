#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
#include "ListaEstaciones.h"
#include "NodoEstacion.h"
#include "NodoHangares.h"
#include "ListaHangares.h"

using namespace std;

void iniciandosimulacion();
void iniciar();
void crearunidad_simulacion();
void crear_hangares();
void crear_Estaciones();
void crear_Restaurante();
void crear_salaEspera();




int iteraciones = 0;
int puestos_atencion = 0;
int puestos_seguridad_inicio = 0;
int numero_hangares = 0;
int numero_restaurantes = 0;
int numero_columnas = 0;
int numero_sillas = 0;

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

NodoEstacion *estacion;
ListaEstaciones *lista_estacion = new ListaEstaciones();

NodoHangares *hangar;
ListaHangares *lista_hangares = new ListaHangares();

int main()
{
       cout << "Hello world!" << endl;




       cout<<" SISTEMA DE SIMULACION DE AEROPUERTO: ENTRADAS/SALIDAS "<<endl;
       for(int n=0;n<10;n++)
       {
           cout<<"loading..."<<endl;
       }
       cout<<"\n \n \n \n \n \n \n"<<endl;
       cout<<"iniciando sistema...."<<endl;
       for(int n=0;n<10;n++)
       {
           cout<<"loading..."<<endl;
       }

        cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<endl;
        bool inciando = true;
       while(inciando ==true)
       {

           cout<<"---------------------------------[MENU]-----------------------------------------"<<endl;
           cout<<" [1] - Iniciar Simulacion                                           {presione 1}"<<endl;
           cout<<" [2] - Salir                                                        {presione 2}"<<endl;
           cout<<"--------------------------------------------------------------------------------"<<endl;
           int opcion;
           cin>>opcion;
           switch(opcion)
           {
           case 1:
               cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<endl;
               cout<<"Iniciando simulacion..."<<endl;
               cout<<"-----------------------"<<endl;
               iniciandosimulacion();
            break;
           case 2:
               cout<<"   Creado por: Jose Wannan - 201612331 - Codeblocks"<<endl;
               cout<<"-----------------------"<<endl;

               inciando = false;
            break;
           }
       }

    return 0;
}

void iniciandosimulacion()
{
    bool inciando = true;
    cout<<" [1] - Ingrese el numero de iteraciones que poseera la simulacion "<<endl;
    cin>>iteraciones;
    cout<<" [2] - Ingrese el numero de puestos de atencion al cliente que existira en el sistema "<<endl;
    cin>>puestos_atencion;
    cout<<" [3] - Ingrese el numero de puestos de seguridad que existira en el sistema "<<endl;
    cin>>puestos_seguridad_inicio;
    cout<<" [4] - Ingrese el numero de Hangares  que poseera  el aeropuerto "<<endl;
    cin>>numero_hangares;
    cout<<" [5] - Ingrese el numero de restaurantes  que poseera  el aeropuerto "<<endl;
    cin>>numero_hangares;
    cout<<" [6] - Ingrese el numero de sillas que poseeran las salas de esperas "<<endl;
    cout<<" [6-1] Columnas"<<endl;
    cin>>numero_columnas;
    cout<<" [6-2] Filas"<<endl;
    cin>>numero_columnas;

     for (int n1 = 0; n1<5; n1++)
     {
         cout<<" \n "<<endl;
     }
    cout<<" ---------------------------------------------- "<<endl;
    cout<<" creando simulacion, Por favor Espere "<<endl;

    crear_hangares();
    crear_Estaciones();
    iniciar();


}
void iniciar()
{
    for(int n=1; n<iteraciones+1;n++)
    {
        cout<<" ############################################################# \n \n Iteracion No. "<<n<<"\n \n"<<endl;
        crearunidad_simulacion();
        cout<<" ############################################################# \n \n "<<endl;
    }
}
void crearunidad_simulacion()
{
    int unidad = 1 + rand() % (5-0);

    if(unidad == 1)
    {
        ClientesAleatorios *nuevo = new ClientesAleatorios();
        Clientes = nuevo->crearclientes(lista_cliente->id_actual);
        lista_cliente->insertar_datos(Clientes);
        lista_cliente->id_actual++;
        lista_cliente->mostrar_unidad(Clientes);

    }
    else if(unidad == 2)
    {
        equipajeAleatorio *nuevo = new equipajeAleatorio();
        Equipaje = nuevo->crearequipaje(lista_equipaje->id_actual);
        lista_equipaje->agregar_datos(Equipaje);
        lista_equipaje->id_actual++;
        lista_equipaje->mostrar_unidad(Equipaje);

    }
    else if(unidad == 3)
    {
        paqueteriaAleatoria *nuevo = new paqueteriaAleatoria();
        paquete = nuevo->crearpaquete(lista_paqueteria->id_actual);
        lista_paqueteria->ingresar_dato(paquete);
        lista_paqueteria->id_actual++;
        lista_paqueteria->Mostrar_unidad(paquete);

    }
    else if(unidad == 4)
    {
        vuelosAleatorios *nuevo = new vuelosAleatorios();
        vuelo = nuevo->agregarvuelo(lista_vuelo->id_actual);
        lista_vuelo->ingresar_datos(vuelo);
        lista_vuelo->id_actual++;
        lista_vuelo->mostrar_unidad(vuelo);

    }
    else
    {
        empleadosAleatorios *nuevo = new empleadosAleatorios();
        empleado = nuevo->crearempleados(lista_empleado->id_actual);
        lista_empleado->ingresar_datos(empleado);
        lista_empleado->id_actual++;
        lista_empleado->mostrar_unidad(empleado);

    }
}
void crear_hangares()
{
    for(int n = 1; n<(numero_hangares+1);n++)
    {
        hangar = new NodoHangares("hangar_"+to_string(lista_hangares->id_actual));
        lista_hangares->ingresar_dato(hangar);
        lista_hangares->id_actual++;
    }
}
void crear_Estaciones()
{
    for(int n=1; n<(puestos_atencion+1);n++)
    {
        estacion = new NodoEstacion("Estacion_Atencion_"+to_string(lista_estacion->id_actual),"Atencion al Cliente", 1);
        lista_estacion->ingresar_estacion(estacion);
        lista_estacion->id_actual++;
    }
    for(int n = 1; n<(puestos_seguridad_inicio+1);n++)
    {
        estacion = new NodoEstacion("Estacion_Seguridad_"+to_string(lista_estacion->id_actual),"Seguridad entrada", 2);
        lista_estacion->ingresar_estacion(estacion);
        lista_estacion->id_actual++;
    }
}
