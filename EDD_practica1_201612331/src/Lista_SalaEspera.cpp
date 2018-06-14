#include "Lista_SalaEspera.h"

Lista_SalaEspera::Lista_SalaEspera()
{
    //ctor
    this->primero = nullptr;
    this->ultimo = nullptr;
}

Lista_SalaEspera::~Lista_SalaEspera()
{
    //dtor
}
void Lista_SalaEspera::insertar_datos(NodoSalaEspera *nodo)
{
    NodoSalaEspera *nuevo = nodo;
    nuevo->id = this->id_actual;

    if(primero==nullptr)
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
int Lista_SalaEspera::personas_aqui()
{
    NodoSalaEspera *pivote = this->primero;
    int personas =0;
    do
    {
      personas++;
      pivote = pivote->siguiente;

    }
    while(pivote != nullptr && pivote != ultimo->siguiente);
    return personas;
}
