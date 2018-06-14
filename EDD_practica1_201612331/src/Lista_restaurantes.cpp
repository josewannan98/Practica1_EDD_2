#include "Lista_restaurantes.h"

Lista_restaurantes::Lista_restaurantes()
{
    //ctor
    this->primero = nullptr;
    this->ultimo = nullptr;
}

Lista_restaurantes::~Lista_restaurantes()
{
    //dtor
}
void Lista_restaurantes::ingresar_restaurante(NodoRestaurantes *nodo)
{
     NodoRestaurantes *nuevo = nodo;

    if(primero==nullptr)
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
int Lista_restaurantes::personas_aqui()
{
    NodoRestaurantes *pivote = this->primero;
    int personas = 0;
    while(pivote!=nullptr)
    {
        personas++;
        pivote = pivote->siguiente;
    }
    return personas;
}
