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
            pivote->cliente_enatencion = cliente;
            tts = true;
            cout<<"\n El Cliente ["<<cliente->nombre<<"] tuvo suerte \n encontro la estacion vacia y avanzo a \n la Estacion ->"<<pivote->nombre <<endl;
            break;

        }
        pivote = pivote->siguiente;
    }
    return tts;
}
bool ListaEstaciones::a_estacionSeguridad(NodoClientes *cliente)
{

    bool tts = false;

    if(cliente->embarazada_==true || cliente->discapacitado_==true || cliente->terecera_edad == true)
    {
        this->cola_espera->insertar_alinicio(cliente);
        this->cola_espera->id_actual++;
        return true;
    }
    else
    {
        this->cola_espera->insertar_normal(cliente);
        this->cola_espera->id_actual++;
        return true;
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






void ListaEstaciones::eliminar_seguridad()
{

    cout<<" Estacion Centro de Seguridad... "<<endl;
    NodoEstacion *pivote = this->primero;

    do
    {
        if(pivote->seguridad_Cliente_inicio == true && pivote->tiene_empleado == true && pivote->cliente_enatencion!=nullptr)
        {
            if(cola_espera->primero!=nullptr)
            {

                eliminar_segurida(pivote);
            }
            else
            {
                cout<<"\n La Estacion de Seguridad No."<<pivote->id<<", Se encuentra vacia"<<endl;
            }


        }


        pivote = pivote->siguiente;

    }while(pivote != nullptr && pivote!= ultimo->siguiente);
}


void ListaEstaciones::eliminar_seguridad2()
{
    cout<<" Centro de seguridad para Equipajes... "<<endl;
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
    cout<<" Centro de seguridad para Paquetes... "<<endl;
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
    cout<<" Revisando Paquetes... "<<endl;
    cola_paqueteria->push_(estacion->nombre);
}
void ListaEstaciones::actualizarcolasEq(NodoEstacion *estacion)
{
     cout<<" Revisando Equipajes... "<<endl;
     cola_equipaje->push_(estacion->nombre);

}


void ListaEstaciones::eliminar_segurida(NodoEstacion* estacion)
{
    cout<<" Estacion -> "<<estacion->nombre<<endl;
    NodoClientes *Envio = estacion->cliente_enatencion;
    estacion->cliente_enatencion = nullptr;

    if(estacion->tiene_empleado == true)
    {

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
         cout<<"\n En la estacion de seguridad No."<<estacion->id<<" no hay un empleado atendiendo"<<endl;
    }

    int random = 1 + rand() % (2-0);

    if(random==1)
    {
        enviar_aSalaEspera(this->SalaEspera, Envio);

    }
    else
    {
        enviar_arestaurantes(this->restaurante, Envio);

    }

}
NodoClientes* ListaEstaciones::traer_decolaseguridad(NodoEstacion *estacion)
{
    NodoClientes *envio = cola_espera->enviar_siguiente();
    cola_espera->push_();
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
          cout<<" El Cliente ["<<clientes->nombre<<"] ingreso al restaurante [ Restaurante_"<<pivote->id<<"] "<<endl;
          pivote->capacidad--;
          break;
        }
        else
        {
            cout<<" Ya no hay espacio en el Restaurante resturante_"<<pivote->id<<endl;
        }
        pivote = pivote->siguiente;
    }
}
void ListaEstaciones::enviar_aSalaEspera(Lista_filaSalaEspera *sala, NodoClientes *clientes)
{
    Lista_filaSalaEspera *pivote1 = sala;
    bool entra = true;

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
                pivote2->cola_clientes = clientes;
                cout<<" El Cliente ["<<clientes->nombre<<"] ingreso a la sala de espera \n Lugar [$[ Fila: "<<pivote->id<<"] - [ Columna :"<<pivote2->id<<"] $] "<<endl;
                pivote2->ocupado=true;
                entra = false;
                break;
            }

            pivote2 = pivote2->siguiente;

        }while(pivote2!=nullptr && pivote2!= pivote->fila->ultimo->siguiente);
        pivote = pivote->siguiente;

    }
}
void ListaEstaciones::elimnar_atencion()
{
    cout<<" Estacion Centros de Atencion... "<<endl;

    NodoEstacion *pivote = this->primero;
    if(pivote!=nullptr)
    {
        do
        {
            if(pivote->Atencion_alCliente==true && pivote->tiene_empleado == true && pivote->cliente_enatencion!=nullptr)
            {

                eliminar_atention(pivote);

            }

            pivote = pivote->siguiente;

        }while(pivote!=nullptr && pivote!=this->ultimo->siguiente);
    }

}
void ListaEstaciones::eliminar_atention(NodoEstacion *estacion)
{
    cout<<" Estacion -> "<<estacion->nombre<<endl;
    NodoClientes *clienteaMover = estacion->cliente_enatencion;
    estacion->cliente_enatencion = nullptr;
    if(cola_espera_atencion->actual>0)
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
        cout<<"\n La Cola para avanzar a centro de atencion esta Vacia"<<endl;
        bool ingre = a_estacionSeguridad(clienteaMover);
         if(ingre == true)
         {
             cout<<"\n El Cliente ["<<clienteaMover->nombre<<"] ingreso a la estacion de seguridad \n Estacion -> [ Estacion_"<<estacion->id<<"]"<<endl;

         }
         else
         {
             cout<<"\n El Cliente ["<<clienteaMover->nombre<<"] decidio ya no viajar y se retiro del aeropuerto"<<endl;

         }

    }

}

NodoClientes* ListaEstaciones::llamar_coladeEspera()
{
    NodoClientes *a_llamar = cola_espera_atencion->primero;
    NodoClientes *envio = cola_espera_atencion->primero;

if(a_llamar!=nullptr)
{
    if(a_llamar->siguiente!=nullptr)
    {
        NodoClientes *nuevo_primero = a_llamar->siguiente;
        nuevo_primero->antetior = nullptr;
        cola_espera_atencion->primero = nuevo_primero;
        cola_espera_atencion->actual--;
        delete a_llamar;
    }
    else
    {
        delete a_llamar;

    }

}
    return envio;

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

    estacion->cliente_enatencion = cola_espera->primero;

    NodoClientes *NodoEliminar = cola_espera->primero;
    NodoClientes *Envio = NodoEliminar;

    if(NodoEliminar->siguiente!=nullptr)
    {
        NodoClientes *aux = NodoEliminar;
        NodoEliminar = NodoEliminar->siguiente;
        NodoEliminar->antetior = nullptr;
        cola_espera->primero = NodoEliminar;

        delete aux;

    }
    else
    {

        delete cola_espera->primero;
        cola_espera->primero = nullptr;

    }
    cola_espera->insertar_normal(cliente);
    cout<<"\n El Cliente ["<<cliente->nombre<<"] ingreso a la estacion de seguridad_["<<estacion->id<<"]"<<endl;

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

//ya no se usan -presentaban bugs-
int ListaEstaciones::encontrar_empleadoslab()
{
    NodoEstacion *pivote = this->primero;
    int empleado= 0;
    do
    {
        if(pivote->tiene_empleado==true)
        {
            empleado++;

        }
        pivote = pivote->siguiente;

    }while(pivote!=nullptr && pivote!= this->ultimo->siguiente);
return empleado;
}
int ListaEstaciones::personas_cola()
{
    NodoClientes *pivote = cola_espera_atencion->primero;
    int n=0;
    while(pivote!=nullptr)
    {
        n++;
        pivote = pivote->siguiente;
    }
    return n;
}
