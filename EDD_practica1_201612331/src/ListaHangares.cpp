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
void ListaHangares::push_(NodoVuelo *vuelo)
{
     NodoHangares *Lista = this->primero;
     if(Lista!=nullptr)
     {
         NodoHangares *aux;

         while((Lista!=nullptr)&& Lista->vuelo!=vuelo)
         {
            Lista = Lista->siguiente;
         }
         if(Lista->vuelo==vuelo)
         {
             cout<<" El Vuelo "<<Lista->vuelo->nombre<<" ha salido del hangar "<<Lista->nombre<<endl;
             cout<<" El Vuelo poseia "<<Lista->vuelo->clientes_envuelo->id_actual<<" clientes en el \n"<<endl;
             Lista->vuelo = nullptr;
             Lista->ocupado = false;
         }
     }
     else
     {
         cout<<" No hay Vuelos por Despegar "<<endl;
     }
}
