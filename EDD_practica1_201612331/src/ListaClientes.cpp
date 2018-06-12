#include "ListaClientes.h"
#include "NodoClientes.h"

ListaClientes::ListaClientes()
{
    this->primero = nullptr;
    this->ultimo = nullptr;
    //ctor
}

ListaClientes::~ListaClientes()
{
    //dtor
}
void ListaClientes::insertar_dato(string nombre, string tipo_cliente, string estado, int edad, string informacion, string ubicacion)
{
    NodoClientes *nuevo = new NodoClientes(nombre, tipo_cliente, estado, edad, informacion, ubicacion);
    nuevo->id = this->id_actual;

    if(this->primero == nullptr)
    {
        this->primero = nuevo;
        this->ultimo = nuevo;
    }
    else
    {
        this->ultimo->siguiente = nuevo;
        nuevo->antetior = this->ultimo;
        this->ultimo = nuevo;


    }
}
void ListaClientes::mostrar_datos()
{
    NodoClientes *pivote = this->primero;

    while(pivote != nullptr)
    {
        if(pivote->antetior != nullptr)
         {
            cout<<"Anterior: [ "<<pivote->antetior->nombre<<" ] - ";
         }
         cout<<" - Nodo: [ "<<pivote->nombre<<" ] - ";
         pivote = pivote->siguiente;
         if(pivote!=nullptr)
         {
             cout<<" - Siguiente: [ "<<pivote->nombre<<" ] \n ";
         }
    }
}
