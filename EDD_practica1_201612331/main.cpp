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
#include "NodoRestaurantes.h"
#include "Lista_restaurantes.h"
#include "NodoColumna_espera.h"
#include "Lista_SalaEspera.h"
#include "Lista_filaSalaEspera.h"
#include "NodoSalaEspera.h"

using namespace std;

void iniciandosimulacion();
void iniciar();
//crear unidades
void crearunidad_simulacion();
//iniciar variables
void crear_hangares();
void crear_Estaciones();
void crear_Restaurante();
void crear_salaEspera();
//primer proceso
void entrada_principal2(NodoClientes *cliente);
void entrada_principal1(NodoClientes *cliente);
void a_hangar(NodoVuelo *vuelo);
void entrada_secundaria1(NodoEquipaje *equipaje);
void entrada_secundaria2(NodoPaqueteria *paquete);
void a_estaciones(NodoEmpleados *empleado);

void actualizar_estaciones();
void actualizar_colaEspera();


int iteraciones = 0;
int puestos_atencion = 0;
int puestos_seguridad_inicio = 0;
int numero_hangares = 0;
int numero_restaurantes = 0;
int numero_columnas = 0;
int numero_filas = 0;


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

NodoRestaurantes *restaurante;
Lista_restaurantes *listas_restaurantes = new Lista_restaurantes();

NodoColumna_espera *filassalaespera;
Lista_filaSalaEspera *filas = new Lista_filaSalaEspera();

ColaEspera_Clientes *atencion_ = new ColaEspera_Clientes();

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

lista_cliente = new ListaClientes();

lista_equipaje = new ListaEquipaje();

lista_paqueteria = new ListaPaqueteria();
lista_vuelo = new ListaVuelo();

lista_empleado = new ListaEmpleados();

lista_estacion = new ListaEstaciones();

lista_hangares = new ListaHangares();

listas_restaurantes = new Lista_restaurantes();

filas = new Lista_filaSalaEspera();

atencion_ = new ColaEspera_Clientes();


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
    cin>>numero_filas;

     for (int n1 = 0; n1<5; n1++)
     {
         cout<<" \n "<<endl;
     }
    cout<<" ---------------------------------------------- "<<endl;
    cout<<" creando simulacion, Por favor Espere "<<endl;

    crear_hangares();
    crear_Estaciones();
    crear_Restaurante();
    crear_salaEspera();
    iniciar();


}
void iniciar()
{
    for(int n=1; n<iteraciones+1;n++)
    {


        cout<<" ############################################################# \n \n Iteracion No. "<<n<<"\n \n"<<endl;
        crearunidad_simulacion();
        cout<<" ############################################################# \n \n "<<endl;
        cout<<" En cola, "<<atencion_->cuantas_personas()<<" personas"<<endl;

         actualizar_estaciones();
         actualizar_colaEspera();


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

        if(Clientes->tiene_boleto == true)
        {
            Clientes->esta_enseguridad = true;
            entrada_principal2(Clientes);
        }
        else
        {
            Clientes->esta_enatencion = true;
            entrada_principal1(Clientes);
        }

    }
    else if(unidad == 2)
    {
        equipajeAleatorio *nuevo = new equipajeAleatorio();
        Equipaje = nuevo->crearequipaje(lista_equipaje->id_actual);
        lista_equipaje->agregar_datos(Equipaje);
        lista_equipaje->id_actual++;
        lista_equipaje->mostrar_unidad(Equipaje);
        if(Equipaje->entrando==false)
        {
            entrada_secundaria1(Equipaje);
        }
        else
        {
             cout<<" \n El equipaje ["<<Equipaje->nombre<<"] se ha transportado desde el hangar"<<endl;
        }

    }
    else if(unidad == 3)
    {
        paqueteriaAleatoria *nuevo = new paqueteriaAleatoria();
        paquete = nuevo->crearpaquete(lista_paqueteria->id_actual);
        lista_paqueteria->ingresar_dato(paquete);
        lista_paqueteria->id_actual++;
        lista_paqueteria->Mostrar_unidad(paquete);

        if(paquete->entrando==false)
        {
            entrada_secundaria2(paquete);
        }
        else
        {
             cout<<" \n El paquete ["<<paquete->nombre<<"] se ha transportado desde el hangar"<<endl;
        }

    }
    else if(unidad == 4)
    {
        vuelosAleatorios *nuevo = new vuelosAleatorios();
        vuelo = nuevo->agregarvuelo(lista_vuelo->id_actual);
        lista_vuelo->ingresar_datos(vuelo);
        lista_vuelo->id_actual++;
        lista_vuelo->mostrar_unidad(vuelo);
        a_hangar(vuelo);

    }
    else
    {
        empleadosAleatorios *nuevo = new empleadosAleatorios();
        empleado = nuevo->crearempleados(lista_empleado->id_actual);
        lista_empleado->ingresar_datos(empleado);
        lista_empleado->id_actual++;
        lista_empleado->mostrar_unidad(empleado);
        a_estaciones(empleado);

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
void crear_Restaurante()
{
    for(int n=1; n<(numero_restaurantes+1);n++)
    {
        int capacidad = 15 + rand() % (35-10);
        restaurante = new NodoRestaurantes(capacidad);
        listas_restaurantes->ingresar_restaurante(restaurante);
        listas_restaurantes->id_actual++;

    }
    lista_estacion->restaurante = listas_restaurantes;

}
void crear_salaEspera()
{
    for(int a=0; a<(numero_filas+1); a++)
    {
        filassalaespera = new NodoColumna_espera();
        NodoSalaEspera *columnassalaespera;
        Lista_SalaEspera *columnas = new Lista_SalaEspera();

        for(int b=0;b<(numero_columnas+1);b++)
        {
            columnassalaespera = new NodoSalaEspera();
            columnas->insertar_datos(columnassalaespera);
            columnas->id_actual++;
        }

        filassalaespera->fila = columnas;
        filas->agregar_nodo(filassalaespera);
        filas->id_actual++;
    }

    lista_estacion->SalaEspera = filas;
}
void entrada_principal1(NodoClientes *atencion)
{

    bool entro  = lista_estacion->a_estacionAtencion(atencion);
    if(entro == true)
    {
        cout<<"\n El Cliente ["<<atencion->nombre<<"] tuvo suerte \n encontro la estacion vacia y avanzo"<<endl;
    }
    else
    {
         cout<<"\n El Cliente ["<<atencion->nombre<<"] ingreso a la cola de Espera \n del Centro de Atencion"<<endl;

         if(atencion->embarazada_==true || atencion->discapacitado_ ==true || atencion->terecera_edad==true)
         {
            atencion_->insertar_alinicio(atencion);
            cout<<" Debido a su estado ["<<atencion->estado<<"] ingreso al inicio de la cola de Espera \n del Centro de Atencion"<<endl;
         }
         else
         {
            atencion_->insertar_normal(atencion);

         }
    }


}
void entrada_principal2(NodoClientes *seguridad)
{
    bool intros = lista_estacion->a_estacionSeguridad(seguridad);
    if(intros==true)
    {
         cout<<"\n El Cliente ["<<seguridad->nombre<<"] ingreso a la estacion de seguridad"<<endl;
    }


}
void a_hangar(NodoVuelo *vuelo)
{
    bool ingresando = lista_hangares->ingresar_vuelo(vuelo);
    if(ingresando == true)
    {
        cout<<"\n El vuelo ["<<vuelo->nombre<<"] fue asignado a un hangar"<<endl;

    }
    else
    {
        cout<<"\n El vuelo ["<<vuelo->nombre<<"] no encontro hangar disponible y se retiro"<<endl;
    }

}
void entrada_secundaria1(NodoEquipaje *equipaje)
{
    bool ingrea = lista_estacion->a_estacionSeguridad1(equipaje);
    if(ingrea == true)
    {
        cout<<" \n El equipaje ["<<equipaje->nombre<<"] entro a la cola para revision"<<endl;

    }

}
void entrada_secundaria2(NodoPaqueteria *paqueteria)
{
    bool ingrea = lista_estacion->a_estacionSeguridad2(paqueteria);
    if(ingrea == true)
    {
        cout<<" \n El paquete ["<<paqueteria->nombre<<"] entro a la cola para revision"<<endl;

    }

}
void a_estaciones(NodoEmpleados *empleado)
{


    bool ingresando = lista_estacion->ingresando_empleado(empleado);
    if(ingresando == true)
    {
        cout<<"\n El empleado ["<<empleado->nombre<<"] fue asignado a una estacion"<<endl;

    }
    else
    {
        cout<<"\n El empleado ["<<empleado->nombre<<"] no encontro estacion y decidio trabajar mañana"<<endl;
    }

}
void actualizar_colaEspera()
{

         atencion_ = lista_estacion->cola_espera;
    cout<<" \n La cola de Espera para Atencion, posee ahora - "<<atencion_->cuantas_personas()<<" personas"<<endl;



}
void actualizar_estaciones()
{

 cout<<" entrando a centro de atencion "<<endl;
 lista_estacion->elimnar_atencion();
 cout<<" saliendo de centro de atencion "<<endl;
 lista_estacion->setnuevoColaEspera(atencion_);
 cout<<" entrando a seguridad "<<endl;
 lista_estacion->eliminar_seguridad();
 cout<<" saliendo de seguridad "<<endl;

}
