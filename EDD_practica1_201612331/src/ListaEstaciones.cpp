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
                    if(pivote->cliente_enatencion!= nullptr)
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
                    else
                    {
                        pivote->cliente_enatencion = cliente;
                        tts=true;
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
        if(pivote->seguridad_Cliente_inicio==true)
        {
                if(itera == random)
                {
                    if(pivote->cliente_enatencion!= nullptr)
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
                    else
                    {
                        pivote->cliente_enatencion = cliente;
                        tts=true;
                       break;
                    }

                    }

                    itera++;
                }


     pivote = pivote->siguiente;
    }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);
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
        if(pivote->seguridad_Cliente_inicio == true && pivote->tiene_empleado == true && pivote->cliente_enatencion!=nullptr)
        {
            if(pivote->clientes_encola->primero!=nullptr)
            {
                cout<<"ss"<<endl;
                eliminar_segurida(pivote);
            }
            else
            {
                cout<<"\n La Estacion de Seguridad No."<<pivote->id<<", Se encuentra vacia"<<endl;
            }


        }
        else
        {
            cout<<"\n ------ Aun no ha pasado nada interesante en la estacion de seguridad ------"<<endl;
        }
        pivote = pivote->siguiente;

    }while(pivote != nullptr && pivote!= ultimo->siguiente);
}
void ListaEstaciones::eliminar_segurida(NodoEstacion* estacion)
{
    cout<<"en metodo segurida"<<endl;
    NodoClientes *Envio = estacion->cliente_enatencion;
    estacion->cliente_enatencion = nullptr;

    if(estacion->tiene_empleado==true)
    {
        cout<<"wass"<<endl;
        NodoClientes *cliente_traido = traer_decolaseguridad(estacion);
        if(cliente_traido!=nullptr)
        {
         estacion->cliente_enatencion = cliente_traido;

        cout<<"\n El Cliente ["<<cliente_traido->nombre<<"] ingreso a una estacion de seguridad \n Estacion -> [ Estacion_"<<estacion->id<<"]"<<endl;

        }
        else
        {

        cout<<"\n La estacion -> [ Estacion_"<<estacion->id<<"] no tiene clientes que revisar"<<endl;

        }

    }
    else
    {
         cout<<"\n La Cola para avanzar a la estacion de seguridad No."<<estacion->id<<" esta vacia"<<endl;
    }
/*
    int random = 1 + rand() % (3-1);

    if(random==1)
    {
        enviar_arestaurantes(this->restaurante, Envio);
    }
    else
    {
        enviar_aSalaEspera(this->SalaEspera, Envio);

    }
*/
}
NodoClientes* ListaEstaciones::traer_decolaseguridad(NodoEstacion *estacion)
{
    NodoClientes *envio = estacion->clientes_encola->enviar_siguiente();
    estacion->clientes_encola->push_();
    return envio;
}
void ListaEstaciones::enviar_arestaurantes(Lista_restaurantes *restaurante, NodoClientes *clientes)
{
    Lista_restaurantes *lista_aux = restaurante;

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
        pivote = pivote->siguiente;
    }
}
void ListaEstaciones::enviar_aSalaEspera(Lista_filaSalaEspera *sala, NodoClientes *clientes)
{
    Lista_filaSalaEspera *pivote1 = sala;

    NodoColumna_espera *pivote = pivote1->primero;
    while(pivote!=nullptr)
    {
        NodoSalaEspera *pivote2 = pivote->fila->primero;

        do
        {
            if(pivote2->ocupado==false)
            {
                int kkl = 1 + rand() % (15-5);
                clientes->tiempo_vuelo = kkl;
                pivote2->cola_clientes = clientes;
                cout<<" El Cliente ["<<clientes->nombre<<"] ingreso a la sala de espera ["<<pivote->id<<" Fila # "<<pivote2->id<<" Columna #] "<<endl;
                break;
            }

            pivote2 = pivote2->siguiente;

        }while(pivote2!=nullptr && pivote2!= pivote->fila->ultimo->siguiente);
        pivote = pivote->siguiente;

    }
}
void ListaEstaciones::elimnar_atencion()
{
    NodoEstacion *pivote = this->primero;
    if(pivote!=nullptr)
    {
        do
        {
            if(pivote->Atencion_alCliente==true && pivote->tiene_empleado == true && pivote->cliente_enatencion!=nullptr)
            {
                cout<<"sld"<<endl;
                eliminar_atention(pivote);

            }
            else
            {
                cout<<"\n --- Aun no ha pasado nada interesante en la estacion de Atencion al Cliente ---"<<endl;
            }
            pivote = pivote->siguiente;

        }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);
    }

}
void ListaEstaciones::eliminar_atention(NodoEstacion *estacion)
{
    NodoClientes *clienteaMover = estacion->cliente_enatencion;
    estacion->cliente_enatencion = nullptr;
    if(cola_espera->cuantas_personas()>0)
    {
        NodoClientes *cliente_traido = llamar_coladeEspera();
        estacion->cliente_enatencion = cliente_traido;
        cout<<"\n El Cliente ["<<cliente_traido->nombre<<"] ingreso a una estacion de atencion al cliente \n Estacion -> [ Estacion_"<<estacion->id<<"]"<<endl;
     bool ingre = a_estacionSeguridad(clienteaMover);
     if(ingre == true)
     {
         cout<<"\n El Cliente ["<<cliente_traido->nombre<<"] ingreso a la estacion de seguridad \n Estacion -> [ Estacion_"<<estacion->id<<"]"<<endl;

     }
     else
     {
         cout<<"\n El Cliente ["<<cliente_traido->nombre<<"] decidio ya no viajar y se retiro del aeropuerto"<<endl;

     }
    }
    else
    {
        cout<<"\n La Cola par avanzar a centro de atencion esta Vacia"<<endl;

    }



}

NodoClientes* ListaEstaciones::llamar_coladeEspera()
{
    NodoClientes *a_llamar = cola_espera->primero;
    NodoClientes *envio = cola_espera->primero;

if(a_llamar!=nullptr)
{
    if(a_llamar->siguiente!=nullptr)
    {
        NodoClientes *nuevo_primero = a_llamar->siguiente;
        nuevo_primero->antetior = nullptr;
        cola_espera->primero = nuevo_primero;
        delete a_llamar;
    }
    else
    {
        delete a_llamar;

    }

}
    return envio;

}
void ListaEstaciones::setnuevoColaEspera(ColaEspera_Clientes *cola_clientes)
{
    this->cola_espera = cola_clientes;
}
void ListaEstaciones::enviar_aseguridad(NodoClientes *cliente)
{

   NodoEstacion *pivote = this->primero;
    NodoEstacion *estacion;

    do
    {
        if(pivote->seguridad_Cliente_inicio == true && pivote->tiene_empleado == true && pivote->cliente_enatencion==nullptr)
        {
           estacion = pivote;

        }
        pivote = pivote->siguiente;

    }while(pivote != nullptr && pivote!= ultimo->siguiente);

    estacion->cliente_enatencion = estacion->clientes_encola->primero;

    NodoClientes *NodoEliminar = estacion->clientes_encola->primero;
    NodoClientes *Envio = NodoEliminar;

    if(NodoEliminar->siguiente!=nullptr)
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
    estacion->clientes_encola->insertar_normal(cliente);
    cout<<"\n El Cliente ["<<cliente->nombre<<"] ingreso a la estacion de seguridad_["<<estacion->id<<"]"<<endl;

}
