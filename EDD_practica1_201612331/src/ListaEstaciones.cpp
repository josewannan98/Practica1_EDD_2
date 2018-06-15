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
        if(pivote->tiene_empleado == false)
        {
            pivote->empleado_acargo = empleado_;
            pivote->tiene_empleado = true;
            tts = true;
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
            pivote->cliente_enatencion = cliente;
            tts = true;
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
    int random = 1 + rand() % (2-1);
    int itera = 0;

    do
    {
        if(pivote->seguridad_Cliente_inicio==true)
        {
                if(itera == random)
                {
                            if(cliente->embarazada_==true || cliente->discapacitado_ ==true || cliente->terecera_edad==true)
                            {
                                pivote->clientes_encola->insertar_alinicio(cliente);
                                tts= true;
                                break;

                            }
                            else
                            {
                                pivote->clientes_encola->insertar_normal(cliente);
                                tts= true;
                                break;


                            }
                    }

                    itera++;
                }


     pivote = pivote->siguiente;
    }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);

    if((itera<random || itera==random) && tts==false)
    {
        NodoEstacion *pivote1 = this->primero;

        do
        {
            if(pivote1->seguridad_Cliente_inicio==true)
                {
                    if(itera == random)
                    {
                                if(cliente->embarazada_==true || cliente->discapacitado_ ==true || cliente->terecera_edad==true)
                                {
                                    pivote1->clientes_encola->insertar_alinicio(cliente);
                                    tts= true;
                                    break;

                                }
                                else
                                {
                                    pivote1->clientes_encola->insertar_normal(cliente);
                                    tts= true;
                                    break;


                                }
                        }

                        itera++;
                    }


         pivote1 = pivote1->siguiente;
    }while(pivote1!=nullptr && pivote1!=this->ultimo->siguiente);

    }
    return tts;
}
bool ListaEstaciones::a_estacionSeguridad1(NodoEquipaje *equipaje)
{
    NodoEstacion *pivote = this->primero;
    bool tts = false;
    int random = 1 + rand() % (2-1);
    int itera = 0;

    do
    {
        if(pivote->seguridad_Cliente_inicio==true)
        {
                if(itera == random)
                {
                          pivote->equipaje_encola->insertar(equipaje);
                          tts=true;
                          break;
                }
                else
                {

                 itera++;
                }

        }
     pivote = pivote->siguiente;
    }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);

    if((itera<random || itera==random) && tts==false)
    {
        NodoEstacion *pivote1 = this->primero;

        do
    {
        if(pivote->seguridad_Cliente_inicio==true)
        {
                if(itera == random)
                {
                          pivote->equipaje_encola->insertar(equipaje);
                          tts= true;
                          break;
                }
                else
                {

                 itera++;
                }
        }


     pivote = pivote->siguiente;
    }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);

    }
    return tts;
}
bool ListaEstaciones::a_estacionSeguridad2(NodoPaqueteria *paquete)
{
    NodoEstacion *pivote = this->primero;
    bool tts = false;
    int random = 1 + rand() % (2-1);
    int itera = 0;

    do
    {
        if(pivote->seguridad_Cliente_inicio==true)
        {
                if(itera == random)
                {
                          pivote->paqueteria_encola->insertar(paquete);
                          tts = true;
                          break;

                }
                else
                {

                 itera++;
                }

        }
     pivote = pivote->siguiente;
    }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);

    if((itera<random || itera==random) && tts==false)
    {
        NodoEstacion *pivote1 = this->primero;

        do
    {
        if(pivote->seguridad_Cliente_inicio==true)
        {
                if(itera == random)
                {
                          pivote->paqueteria_encola->insertar(paquete);
                          tts=true;
                          break;
                }
                else
                {

                 itera++;
                }
        }


     pivote = pivote->siguiente;
    }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);

    }
    return tts;

}
void ListaEstaciones::eliminar_seguridad()
{
    NodoEstacion *pivote = this->primero;

    do
    {
        if(pivote->seguridad_Cliente_inicio==true && pivote->tiene_empleado == true)
        {

        }

    }while(pivote != nullptr && pivote!= ultimo->siguiente);
}
void ListaEstaciones::eliminar_segurida(NodoEstacion* estacion)
{
    NodoClientes *NodoEliminar = estacion->clientes_encola->primero;
    NodoClientes *Envio = NodoEliminar;

    if(NodoEliminarl->siguiente!=nullptr)
    {
        NodoClientes *aux = NodoEliminar;
        NodoEliminar = NodoEliminar->siguiente;
        NodoEliminar->antetior = nullptr;
        estacion->clientes_encola->primero = NodoEliminar;

        delete aux;

    }
    else
    {

        delete estacion->clientes_encola->primero;
        estacion->clientes_encola->primero = nullptr;

    }


}
void ListaEstaciones::enviar_arestaurantes(listas_restaurantes *restaurante, NodoClientes *clientes)
{
    listas_restaurantes *lista_aux = restaurante;

    NodoRestaurantes *pivote = lista_aux->primero;

    while(pivote!=nullptr)
    {
        if(pivote->capacidad!=0)
        {
          int kkl = 1 + rand() % (15-5);
          clientes->tiempo_vuelo = kkl;
          pivote->cliente->insertar_alinicio(clientes);
          cout<<" El Cliente ["<<clientes->nombre<<"] ingreso al restaurante ["<<pivote->id<<"] "<<endl;
          break;
        }
    }
}

