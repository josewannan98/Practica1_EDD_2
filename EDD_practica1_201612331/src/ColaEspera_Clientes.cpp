#include "ColaEspera_Clientes.h"
#include "NodoClientes.h"

ColaEspera_Clientes::ColaEspera_Clientes()
{
    //ctor
    this->primero = nullptr;
    this->ultimo = nullptr;
}

ColaEspera_Clientes::~ColaEspera_Clientes()
{
    //dtor
}
void ColaEspera_Clientes::insertar_alinicio(NodoClientes *nodo)
{
    NodoClientes *nuevo = nodo;

    if(primero==nullptr)
    {
        this->primero=nuevo;
        this->ultimo =nuevo;
    }
    else
    {
        NodoClientes *temp = nuevo;
        temp->siguiente = this->primero;
        temp->siguiente->antetior = temp;
        this->primero = temp;

    }
}
void ColaEspera_Clientes::insertar_normal(NodoClientes *nodo)
{
    NodoClientes *nuevo = nodo;

    if(primero==nullptr)
    {
        this->primero=nuevo;
        this->ultimo =nuevo;
    }
    else
    {
        this->ultimo->siguiente = nuevo;
        nuevo->antetior = this->ultimo;
        this->ultimo = nuevo;

    }
}

