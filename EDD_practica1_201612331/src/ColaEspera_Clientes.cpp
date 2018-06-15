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

    if(this->primero == nullptr)
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
int ColaEspera_Clientes::cuantas_personas()
{
    int personas=0;
    NodoClientes *pivote = this->primero;

    while(pivote!=nullptr)
    {
        personas++;
        pivote = pivote->siguiente;
    }
    return personas;

}
NodoClientes* ColaEspera_Clientes::enviar_siguiente()
{
    return this->primero;
}
void ColaEspera_Clientes::push_()
{
    NodoClientes *a_eliminar = this->primero;

    NodoClientes *anterior = nullptr;
    NodoClientes *aux;
    aux = a_eliminar;

    if(a_eliminar!=nullptr)
    {
        if(a_eliminar->antetior==nullptr)
        {
             cout<<"error aqui en push eliminar 1"<<endl;
             a_eliminar = a_eliminar->siguiente;
             a_eliminar->antetior = nullptr;
             this->primero = a_eliminar;
             delete aux;


        }
        else
        {
            cout<<"error aqui en push eliminar 2"<<endl;

            this->primero = nullptr;
            delete aux;


        }

    }

}

