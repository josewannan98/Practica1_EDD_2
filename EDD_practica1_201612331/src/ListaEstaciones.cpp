#include "ListaEstaciones.h"
#include "NodoEmpleados.h"
#include "Lista_filaSalaEspera.h"
#include "Lista_restaurantes.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


using namespace std;

ListaEstaciones::ListaEstaciones()
{
    this->primero = nullptr;
    this->ultimo = nullptr;
    restaurante = new Lista_restaurantes();
    SalaEspera = new Lista_filaSalaEspera();

    cola_espera = new ColaEspera_Clientes();
    cola_equipaje = new ColaEspera_Equipaje();
    cola_paqueteria = new ColaEspera_Paqueteria();

    cola_espera_atencion = new ColaEspera_Clientes();
    //ctor
}

ListaEstaciones::~ListaEstaciones()
{
    //dtor
}
void ListaEstaciones::ingresar_estacion(NodoEstacion *estacion)
{
    NodoEstacion *nuevo = estacion;
    nuevo->id = this->id_actual;

    if(this->primero == nullptr)
    {
        this->primero = nuevo;
        this->ultimo = nuevo;
    }
    else
    {
        this->ultimo->siguiente = nuevo;
        nuevo->anterior = this->ultimo;
        this->primero->anterior = nuevo;
        nuevo->siguiente = this->primero;
        this->ultimo = nuevo;

    }
}
void ListaEstaciones::mostrar_datos()
{
    NodoEstacion *pivote = this->primero;

    do
    {

        if(pivote->anterior != nullptr)
        {
            cout<<"ANTERIOR ["<<pivote->anterior->nombre<<"]";
        }
        cout<<" - NODO ["<<pivote->nombre<<"]";
        if(pivote->siguiente != nullptr)
        {
            cout<<" - SIGUIENTE ["<<pivote->siguiente->nombre<<"]"<<endl;
        }

        pivote = pivote->siguiente;

    }while(pivote != nullptr && pivote!= this->ultimo->siguiente);
}
bool ListaEstaciones::ingresando_empleado(NodoEmpleados *empleado_)
{
    NodoEstacion *pivote = this->primero;
    bool tts = false;
    do
    {
        if(pivote->tiene_empleado != true)
        {

            pivote->empleado_acargo = empleado_;

            pivote->tiene_empleado = true;
            tts = true;
            cout<<"\n El Empleado "<<empleado_->nombre<<" ingreso a la Estacion "<<pivote->nombre<<endl;
            break;
        }
        pivote = pivote->siguiente;
    }while(pivote != nullptr && pivote!= this->ultimo->siguiente);
    return tts;
}
bool ListaEstaciones::a_estacionAtencion(NodoClientes *cliente)
{
    NodoEstacion *pivote = this->primero;
    bool tts = false;
    while(pivote!=nullptr && pivote->Atencion_alCliente==true)
    {
        if(pivote->tiene_empleado==true && pivote->cliente_enatencion==nullptr)
        {
            cliente->informacion = cliente->informacion +"\n ingreso a estacion de atencion al cliente para hacer sus solicitudes";
            pivote->cliente_enatencion = cliente;
            tts = true;
            cout<<"\n El Cliente ["<<cliente->nombre<<"] tuvo suerte \n encontro la estacion vacia y avanzo a \n la Estacion ->"<<pivote->nombre<<"\n (Asunto: ingreso a la estacion de Atencion)"<<endl;
            break;

        }

        pivote = pivote->siguiente;
    }
    return tts;
}
bool ListaEstaciones::a_estacionSeguridad(NodoClientes *cliente)
{


        NodoEstacion *pivote = this->primero;
    bool tts = false;
    while(pivote!=nullptr && pivote->seguridad_Cliente_inicio==true)
    {
        if(pivote->tiene_empleado==true && pivote->cliente_enatencion==nullptr)
        {
            cliente->informacion = cliente->informacion +"\n ingreso a estacion de seguridad";
            pivote->cliente_enatencion = cliente;
            tts = true;
            cout<<"\n El Cliente ["<<cliente->nombre<<"] tuvo suerte \n encontro la estacion vacia y avanzo a \n la Estacion ->"<<pivote->nombre<<"\n (Asunto: ingreso a la estacion de Seguridad)"<<endl;
            break;

        }

        pivote = pivote->siguiente;
    }
    return tts;


}
bool ListaEstaciones::a_estacionSeguridad1(NodoEquipaje *equipaje)
{
   this->cola_equipaje->insertar(equipaje);
   this->cola_equipaje->id_actual++;
   return true;
}
bool ListaEstaciones::a_estacionSeguridad2(NodoPaqueteria *paquete)
{
    this->cola_paqueteria->insertar(paquete);
    this->cola_paqueteria->id_actual++;
    return true;

}

void ListaEstaciones::eliminar_seguridad2()
{
    cout<<" Centro de seguridad para Equipajes... "<<"\n"<<endl;
    int random  = 1 + rand() % (3-1);
    NodoEstacion *pivote = this->primero;
    int n = 0;
    do
    {
        n++;
        if(n==random)
        {
            actualizarcolasEq(pivote);
        }

        pivote = pivote->siguiente;
    }while(pivote!=nullptr && pivote!= this->ultimo->siguiente);

}

void ListaEstaciones::eliminar_seguridad3()
{
    cout<<" Centro de seguridad para Paquetes... "<<"\n"<<endl;
    int random  = 1 + rand() % (3-1);
    NodoEstacion *pivote = this->primero;
    int n = 0;
    do
    {
        n++;
        if(n==random)
        {
            actualizarcolasPa(pivote);
        }

        pivote = pivote->siguiente;
    }while(pivote!=nullptr && pivote!= this->ultimo->siguiente);
}
void ListaEstaciones::actualizarcolasPa(NodoEstacion *estacion)
{
    cout<<" Revisando Paquetes... "<<"\n"<<endl;
    cola_paqueteria->push_(estacion->nombre);
}
void ListaEstaciones::actualizarcolasEq(NodoEstacion *estacion)
{
     cout<<" Revisando Equipajes... "<<"\n"<<endl;
     cola_equipaje->push_(estacion->nombre);

}

void ListaEstaciones::actualizarestado_empleados()
{
    cout<<" Preguntando el estado de animo de los empleados... "<<endl;
    cout<<" Preguntandoles cuando finalizan su turno... \n "<<endl;
    NodoEstacion *pivote = this->primero;

    do
    {
        if(pivote->tiene_empleado==true)
        {
            pivote->empleado_acargo->turno--;
            if(pivote->empleado_acargo->turno<1)
            {
                cout<<" El empleado ["<<pivote->empleado_acargo->nombre<<"] termino su turno y decidio \n irse a descansar, debido a que estaba demasiado cansado. \n"<<endl;
                pivote->empleado_acargo = nullptr;
                pivote->tiene_empleado = false;
            }
        }
    }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);

    cout<<" Retirandose de las estaciones... \n"<<endl;
}


void ListaEstaciones::reducir_enRestaurantes()
{
    cout<<endl;
    cout<<" Ingresando a los restaurantes... "<<endl;
    cout<<" preguntandoles a los clientes su hora de despegue... "<<endl<<endl;
    NodoRestaurantes *pivote = this->restaurante->primero;

    while(pivote!=nullptr)
    {

        reduce_fatfat(pivote);
        pivote = pivote->siguiente;


    }
}
void ListaEstaciones::reduce_fatfat(NodoRestaurantes *restaurante)
{
    //cout<<" ingresando a restaurante_"<<restaurante->id<<" ... "<<endl<<endl;

        if(restaurante->cliente->id_actual>0){
      NodoClientes *pivote_c = restaurante->cliente->primero;

      while(pivote_c!=nullptr)
      {
          pivote_c->tiempo_vuelo--;
          if(pivote_c->tiempo_vuelo<1)
          {
              personas_salieronalAvion++;
              cout<<" El cliente ["<<pivote_c->nombre<<"] abordo su vuelo \n (Asunto: Vamos a Russia) \n"<<endl;
              mandar_alvAvion(pivote_c);
              restaurante->capacidad++;
              break;
          }
          pivote_c = pivote_c->siguiente;
      }
    }


      cout<<" saliendo del restaurante_"<<restaurante->id<<" ..."<<endl<<endl;

}
void ListaEstaciones::mandar_alvAvion(NodoClientes *cliente)
{
    cout<<" ingresando al centro de control de hangares... \n "<<endl;
    NodoHangares *hangar = this->hangares->primero;

    while(hangar!=nullptr)
    {
        if(hangar->ocupado==true)
        {
            hangar->vuelo->clientes_envuelo->insertar_datos(cliente);
            hangar->vuelo->clientes_envuelo->id_actual++;
            hangar->vuelo->pasajeros--;
            if(hangar->vuelo->pasajeros<1)
            {
                cout<<" El vuelo ["<<hangar->vuelo<<"] se fue del aeropuerto con destino al mundial de Russia 2018"<<endl;
                aviones_despegaron++;
                this->hangares->push_(hangar->vuelo);
                hangar->ocupado = false;
                break;
            }
            break;
        }
        hangar = hangar->siguiente;
    }
    cout<<" saliendo del centro de control de hangares... \n "<<endl;
}


//adquirir cuantos empleados tiene
int ListaEstaciones::encontrarempleados()
{
    int empleados=0;
    NodoEstacion *pivote = this->primero;
    do
    {
        if(pivote->tiene_empleado==true)
        {
            empleados++;
        }
        pivote = pivote->siguiente;

    }while(pivote!=nullptr && pivote != this->ultimo->siguiente);
    return empleados;
}


//inicio de proceso clientes
void ListaEstaciones::actualizarestacionAtencion()
{
    NodoEstacion *pivote = this->primero;
    do
    {
        if(pivote->Atencion_alCliente==true)
        {
            if(pivote->tiene_empleado==true)
            {
                if(pivote->cliente_enatencion==nullptr)
                {
                    NodoClientes *cliente = cola_espera_atencion->enviar_siguiente();
                    if(cliente!=nullptr)
                    {
                        pivote->cliente_enatencion = cliente;
                        cout<<" El cliente ["<<cliente->nombre<<"] ingreso a la estacion ["<<pivote->nombre<<"] \n"<<endl;
                        cola_espera_atencion->push_();
                        break;
                    }
                    else
                    {
                        cout<<" ya no hay clientes en la cola de espera de atencion \n"<<endl;
                        break;
                    }
                }
            }
        }
        pivote = pivote->siguiente;

    }while(pivote!=nullptr && pivote!=ultimo->siguiente);
}

void ListaEstaciones::adquirirestado_atencion()
{

    cout<<" Adquiriendo informacion Estacion_Atencion... "<<endl;
    NodoEstacion *pivote = this->primero;


    do
    {
        if(pivote->Atencion_alCliente==true)
        {
            if(pivote->tiene_empleado==true)
            {
                if(pivote->cliente_enatencion!=nullptr)
                {
                    actualizarEstacion(pivote->cliente_enatencion, pivote);
                }
            }
        }
        pivote= pivote->siguiente;
    }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);

    cout<<" Asunto ( [Solicitud de Boleto - Informacion - Solicitudes]) \n"<<endl;
}
NodoClientes* ListaEstaciones::nuevo_clienteAtencion()
{
    if(cola_espera_atencion->actual>0)
    {
        NodoClientes *nuevo = cola_espera_atencion->enviar_siguiente();
        cola_espera_atencion->push_();
        return nuevo;
    }
    else
    {
        return nullptr;
    }
}
void ListaEstaciones::actualizarEstacion(NodoClientes *clientes, NodoEstacion *estacion)
{
    NodoClientes *nuevo_atencion = nuevo_clienteAtencion();
    if(nuevo_atencion!=nullptr)
    {
        estacion->cliente_enatencion= nuevo_atencion;
        cout<<" EL cliente ["<<nuevo_atencion->nombre<<"] ingreso a la estacion ["<<estacion->nombre<<"] \n"<<endl;

    }
    else
    {
        estacion->cliente_enatencion = nullptr;
        cout<<" La estacion ["<<estacion->nombre<<"] quedo vacia \n"<<endl;
    }
    enviarCliente_aSeguridad(clientes);

}
void ListaEstaciones::enviarCliente_aSeguridad(NodoClientes *clientes)
{
    NodoEstacion *estacion_1 = preguntar_estadoSeguridad();
    if(estacion_1!=nullptr)
    {
        estacion_1->cliente_enatencion = clientes;
        cout<<" El cliente ["<<clientes->nombre<<"] ingreso a la Estacion ["<<estacion_1->nombre<<"] \n"<<endl;
    }
    else
    {
        cola_espera->insertar_normal(clientes);
        cola_espera->id_actual++;
        cout<<" El cliente ["<<clientes->nombre<<"]  ingreso a la cola para Estacion de Seguridad \n"<<endl;
    }

}
NodoEstacion* ListaEstaciones::preguntar_estadoSeguridad()
{
    cout<<" Preguntando en Estaciones de Seguridad... "<<endl;
    NodoEstacion *pivote = this->primero;
    NodoEstacion *aux = nullptr;
    do
    {
        if(pivote->seguridad_Cliente_inicio==true)
        {
            if(pivote->tiene_empleado==true)
            {
                aux = pivote;
                break;
            }
        }
        pivote = pivote->siguiente;
    }while(pivote!=nullptr && pivote!=ultimo->siguiente);

    return aux;
}

// estacion seguridad


void ListaEstaciones::actualizarestacionSeguridad()
{
    cout<<" Actualizando estacion seguridad... "<<endl;
    NodoEstacion *pivote = this->primero;
    do
    {
        if(pivote->seguridad_Cliente_inicio==true)
        {
            if(pivote->tiene_empleado==true)
            {
                if(pivote->cliente_enatencion==nullptr)
                {
                    NodoClientes *cliente = cola_espera->enviar_siguiente();
                    if(cliente!=nullptr)
                    {
                        pivote->cliente_enatencion = cliente;
                        cout<<" El cliente ["<<cliente->nombre<<"] ingreso a la estacion ["<<pivote->nombre<<"] \n"<<endl;
                        cola_espera->push_();
                        break;
                    }
                    else
                    {
                        cout<<" ya no hay clientes en la cola de espera de seguridad \n"<<endl;
                        break;
                    }
                }
            }
        }
        pivote = pivote->siguiente;

    }while(pivote!=nullptr && pivote!= this->ultimo->siguiente);
}

void ListaEstaciones::adquirirestado_seguridad()
{
    cout<<" Adquiriendo informacion Estacion_Seguridad... "<<endl;
    NodoEstacion *pivote = this->primero;

    do
    {
        if(pivote->seguridad_Cliente_inicio==true)
        {
            if(pivote->tiene_empleado==true)
            {
                if(pivote->cliente_enatencion!=nullptr)
                {
                    actualizarEstacion1(pivote->cliente_enatencion, pivote);
                }
            }
        }
        pivote = pivote->siguiente;
    }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);

    cout<<" Asunto ( [Revision de Clientes - Revision de Paquetes - Revision de Equipaje]) \n"<<endl;
}
NodoClientes* ListaEstaciones::nuevo_clienteSeguridad()
{
    if(cola_espera->actual>0)
    {
        NodoClientes *nuevo = cola_espera->enviar_siguiente();
        cola_espera->push_();
        return nuevo;
    }
    else
    {
        return nullptr;
    }
}
void ListaEstaciones::actualizarEstacion1(NodoClientes *clientes, NodoEstacion *estacion)
{
    NodoClientes *nuevo_seguridad = nuevo_clienteSeguridad();
    if(nuevo_seguridad!=nullptr)
    {
        estacion->cliente_enatencion= nuevo_seguridad;
        cout<<" EL cliente ["<<nuevo_seguridad->nombre<<"] ingreso a la estacion ["<<estacion->nombre<<"] \n"<<endl;

    }
    else
    {
        estacion->cliente_enatencion = nullptr;
        cout<<" La estacion ["<<estacion->nombre<<"] quedo vacia \n"<<endl;
    }

    enviarCliente_aEsperar(clientes);
}
void ListaEstaciones::enviarCliente_aEsperar(NodoClientes *cliente)
{
    int random = 1+ rand() % (3-0);

    if(random>0 && random<2)
    {
        bool ingresa = enviar_arestaurantes(cliente);
        if(ingresa != true)
        {
            perdieron_suvuelodeRestaurantes++;
            cout<<" El cliente ["<<cliente->nombre<<"], fue al baño, pero en el camino se perdio \n  el perdio su vuelo y se retiro a su casa - Restaurantes\n"<<endl;
        }
        else
        {
            pesonasRestau++;
        }
    }
    else
    {
        bool ingresa = enviar_aSalaEspera(cliente);
        if(ingresa != true)
        {
            perdieron_suvuelodeRestaurantes++;
            cout<<" El cliente ["<<cliente->nombre<<"], fue al baño, pero en el camino se perdio \n el perdio su vuelo y se retiro a su casa - Sala de Espera\n"<<endl;
        }
        else
        {
            personas_ensalaespera++;
        }
    }

}





bool ListaEstaciones::enviar_arestaurantes(NodoClientes *clientes)
{
    cout<<" Enviando Cliente a Restaurante... \n"<<endl;
    Lista_restaurantes *lista_aux = this->restaurante;
    bool entro = false;
    NodoRestaurantes *pivote = lista_aux->primero;

    while(pivote!=nullptr)
    {
        if(pivote->capacidad != 0)
        {
          int kkl = 1 + rand() % (15-5);
          clientes->tiempo_vuelo = kkl;
          clientes->informacion = clientes->informacion + " \n ingreso a Restaurantes";
          pivote->cliente->insertar_alinicio(clientes);
          pivote->id_actual++;
          cout<<" El Cliente ["<<clientes->nombre<<"] ingreso al restaurante [ Restaurante_"<<pivote->id<<"] \n "<<endl;
          pivote->capacidad--;
          entro = true;
          break;
        }

        pivote = pivote->siguiente;
    }
    return entro;
}
bool ListaEstaciones::enviar_aSalaEspera(NodoClientes *clientes)
{
     cout<<" Enviando Cliente a Sala de Espera... \n"<<endl;
    Lista_filaSalaEspera *pivote1 = this->SalaEspera;
    bool entra = true;
    bool si_sesento =false;
    NodoColumna_espera *pivote = pivote1->primero;
    while(pivote!=nullptr)
    {
        NodoSalaEspera *pivote2 = pivote->fila->primero;

        do
        {
            if(pivote2->ocupado == false && entra == true)
            {
                int kkl = 1 + rand() % (15-5);
                clientes->tiempo_vuelo = kkl;
                clientes->informacion = clientes->informacion + " \n ingreso a la Sala de Espera";
                pivote2->cola_clientes = clientes;
                cout<<" El Cliente ["<<clientes->nombre<<"] ingreso a la sala de espera \n Lugar [ Fila: "<<pivote->id<<"] - [ Columna :"<<pivote2->id<<"] \n (Asunto: Esperando para ingresar al avion) \n "<<endl;
                pivote2->ocupado=true;
                entra = false;
                si_sesento = true;
                break;
            }

            pivote2 = pivote2->siguiente;

        }while(pivote2!=nullptr && pivote2!= pivote->fila->ultimo->siguiente);
        pivote = pivote->siguiente;

    }
    return si_sesento;
}

int ListaEstaciones::personas_enrestaurante()
{
  int personas=0;
  NodoRestaurantes *resta = this->restaurante->primero;
  while(resta!=nullptr)
  {
      personas = personas + resta->id_actual;
      resta = resta->siguiente;
  }
  return personas;
}
int ListaEstaciones::personas_enSaladeEspera()
{
    Lista_filaSalaEspera *pivote1 = this->SalaEspera;
    int personas =0;
    NodoColumna_espera *pivote = pivote1->primero;
    while(pivote!=nullptr)
    {
        NodoSalaEspera *pivote2 = pivote->fila->primero;

        do
        {
            if(pivote2->ocupado == true)
            {
                personas++;
            }

            pivote2 = pivote2->siguiente;

        }while(pivote2!=nullptr && pivote2!= pivote->fila->ultimo->siguiente);
        pivote = pivote->siguiente;

    }
    return personas;
}

void ListaEstaciones::reducir_salasdeEspera()
{
    Lista_filaSalaEspera *pivote1 = this->SalaEspera;
    NodoColumna_espera *pivote = pivote1->primero;
    while(pivote!=nullptr)
    {
        NodoSalaEspera *pivote2 = pivote->fila->primero;

        do
        {
            if(pivote2->ocupado == true)
            {
                pivote2->cola_clientes->tiempo_vuelo--;
                if(pivote2->cola_clientes->tiempo_vuelo<1)
                {
                    personas_salieronalAvion++;
                    cout<<" El cliente ["<<pivote2->cola_clientes->nombre<<"] abordo su vuelo \n (Asunto: Vamos a Russia) \n"<<endl;
                    mandar_alvAvion(pivote2->cola_clientes);
                    pivote2->ocupado=false;
                }
            }

            pivote2 = pivote2->siguiente;

        }while(pivote2!=nullptr && pivote2!= pivote->fila->ultimo->siguiente);
        pivote = pivote->siguiente;

    }
}
