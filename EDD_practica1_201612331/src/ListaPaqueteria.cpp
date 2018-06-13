#include "ListaPaqueteria.h"

ListaPaqueteria::ListaPaqueteria()
{
    this->primero = nullptr;
    this->ultimo = nullptr;
    //ctor
}

ListaPaqueteria::~ListaPaqueteria()
{
    //dtor
}
void ListaPaqueteria::ingresar_dato(NodoPaqueteria *nuevo_nodo)
{
    NodoPaqueteria *nuevo = nuevo_nodo;
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
void ListaPaqueteria::Mostrar_datos()
{
    NodoPaqueteria *pivote = this->primero;

    while(pivote != nullptr)
    {

         cout<<" Nodo: [ "<<pivote->id<<" - "<<pivote->nombre<<" - "<< pivote->tipo<<" - "<<pivote->informacion<<" - "<<pivote->ubicacion<<" ] {}"<<endl;
         pivote = pivote->siguiente;

    }
}
