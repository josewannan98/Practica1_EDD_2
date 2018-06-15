#include "ListaHangares.h"

ListaHangares::ListaHangares()
{
    //ctor
    this->primero = nullptr;
    this->ultimo = nullptr;
}

ListaHangares::~ListaHangares()
{
    //dtor
}
void ListaHangares::ingresar_dato(NodoHangares* nodo)
{
    NodoHangares *nuevo = nodo;
    nuevo->id = this->id_actual;
    if(this->primero==nullptr)
    {
        this->primero = nuevo;
        this->ultimo = nuevo;
    }
    else
    {
        NodoHangares *temp = nuevo;
        temp->siguiente = this->primero;

        this->primero = temp;

    }
}
bool ListaHangares::ingresar_vuelo(NodoVuelo *vuelo_)
{
    NodoHangares *pivote = this->primero;
    bool tts = false;
    while(pivote != nullptr)
    {
        if(pivote->ocupado == false)
        {

            pivote->ocupado = true;
            pivote->vuelo = vuelo_;
            tts = true;
            break;

        }
        pivote = pivote->siguiente;
    }
    return tts;
}
