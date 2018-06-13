#include "ListaVuelo.h"
#include "NodoVuelo.h"
#include <iostream>
#include <string>

using namespace std;

ListaVuelo::ListaVuelo()
{
    this->primero = nullptr;
    this->ultimo = nullptr;
    //ctor
}

ListaVuelo::~ListaVuelo()
{
    //dtor
}
void ListaVuelo::ingresar_datos(NodoVuelo *nuevo_vuelo)
{
    NodoVuelo *nuevo = nuevo_vuelo;
    nuevo->id = this->id_actual;

    if(this->primero ==  nullptr)
    {
        this->primero = nuevo;
        this->ultimo = nuevo;
    }
    else
    {

        NodoVuelo *temp = nuevo;
        temp->siguiente = this->primero;
        temp->siguiente->anterior = temp;
        this->primero = temp;

    }

}
void ListaVuelo::mostrar_datos()
{
    NodoVuelo *pivote = this->primero;

    while(pivote != nullptr)
    {

        cout<<" Nodo: [ "<<pivote->id<<" - "<<pivote->nombre<<" - "<< pivote->pasajeros<<" - "<<pivote->equipaje<<" - "<<pivote->paqueteria<<" - "<<pivote->entra<<" ] {}"<<endl;


        pivote = pivote->siguiente;
    }
}
