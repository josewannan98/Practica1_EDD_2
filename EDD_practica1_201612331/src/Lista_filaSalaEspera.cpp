#include "Lista_filaSalaEspera.h"
#include "NodoColumna_espera.h"
#include "Lista_SalaEspera.h"


Lista_filaSalaEspera::Lista_filaSalaEspera()
{
    //ctor
    this->primero=nullptr;
    this->ultimo =nullptr;
}

Lista_filaSalaEspera::~Lista_filaSalaEspera()
{
    //dtor
}
void Lista_filaSalaEspera::agregar_nodo(NodoColumna_espera *nodofila)
{
    NodoColumna_espera *nuevo = nodofila;
    nuevo->id = this->id_actual;

    if(this->primero == nullptr)
    {
        this->primero = nuevo;
        this->ultimo = nuevo;
    }
    else
    {
        this->ultimo->siguiente = nuevo;
        this->ultimo = nuevo;
    }

}
int Lista_filaSalaEspera::personas_aqui()
{
    NodoColumna_espera *aux = this->primero;

    int personas =0;
    while(aux!=nullptr)
    {
        personas = personas + aux->fila->personas_aqui();
        aux= aux->siguiente;
    }
}
