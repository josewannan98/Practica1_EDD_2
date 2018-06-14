#include "ColaEspera_Equipaje.h"
#include "NodoEquipaje.h"

ColaEspera_Equipaje::ColaEspera_Equipaje()
{
    //ctor
    this->primero = nullptr;
    this->ultimo = nullptr;
}

ColaEspera_Equipaje::~ColaEspera_Equipaje()
{
    //dtor
}
void ColaEspera_Equipaje::insertar(NodoEquipaje *nodo)
{
    NodoEquipaje *nuevo = nodo;
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
