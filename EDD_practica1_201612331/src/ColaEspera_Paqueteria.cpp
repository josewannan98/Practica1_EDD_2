#include "ColaEspera_Paqueteria.h"
#include "NodoPaqueteria.h"

ColaEspera_Paqueteria::ColaEspera_Paqueteria()
{
    //ctor
    this->primero = nullptr;
    this->ultimo = nullptr;
}

ColaEspera_Paqueteria::~ColaEspera_Paqueteria()
{
    //dtor
}
void ColaEspera_Paqueteria::insertar(NodoPaqueteria *nodo)
{
    NodoPaqueteria *nuevo = nodo;
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
        this->ultimo = nuevo;

    }
}
void ColaEspera_Paqueteria::push_(string estacion)
{
    cout<<" eliminando... \n"<<endl;

    NodoPaqueteria *temp = this->primero;
     NodoPaqueteria *aux = temp;
       if(temp!=nullptr)
        {
           if(temp->anterior == nullptr && temp->siguiente!=nullptr )
           {
             cout<<" El Paquete ["<<this->primero->nombre<<"] paso a ser revisado y,";
             temp = temp->siguiente;
             temp->anterior = nullptr;
             this->primero = temp;

             delete aux;
             cout<<"\n Salio de la estacion ["<<estacion<<"] y se retiro del aeropuerto \n en un vuelo comercial"<<endl;
           }
           else
           {
               cout<<" El Paquete ["<<this->primero->nombre<<"] paso a ser revisado y,";
               this->primero = nullptr;
               delete this->primero;
               cout<<"\n Salio de la estacion ["<<estacion<<"] y se retiro del aeropuerto \n en un vuelo comercial"<<endl;
           }

        }
        else
        {
            cout<<" Los agentes de Seguridad no encuentran paquetes por revisar.."<<endl;
        }
        cout<< " finalizando... "<<endl;

}
