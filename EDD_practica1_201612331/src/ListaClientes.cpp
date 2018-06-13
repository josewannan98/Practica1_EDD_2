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
void ListaClientes::insertar_dato(string nombre, string tipo_cliente, string estado, int edad, string informacion, string ubicacion, string genero)
{
    NodoClientes *nuevo = new NodoClientes(nombre, tipo_cliente, estado, edad, informacion, ubicacion, genero);
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
void ListaClientes::insertar_datos(NodoClientes *Nuevo)
{
    NodoClientes *nuevo = Nuevo;
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

         cout<<" Nodo: [ "<<pivote->id<<" - "<<pivote->nombre<<" - "<< pivote->edad<<" - "<<pivote->genero<<" - "<<pivote->tipo_cliente<<" - "<<pivote->estado<<" ] {}"<<endl;
         pivote = pivote->siguiente;

    }
}
