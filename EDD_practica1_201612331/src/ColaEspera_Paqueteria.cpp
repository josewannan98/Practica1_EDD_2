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
