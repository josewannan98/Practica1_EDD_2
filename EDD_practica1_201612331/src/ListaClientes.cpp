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
//para agregar en vbase se recibe un nodo
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

         cout<<"---------------------------------------------------"<<endl;
         cout<<" | "<<pivote->id<<" -  Nombre: "<<pivote->nombre<<"  \n | "<<pivote->id<<" -  Edad: "<< pivote->edad<<"  \n | "<<pivote->id<<" -  Genero: "<<pivote->genero<<"  \n | "<<pivote->id<<" -  Tipo de Cliente: "<<pivote->tipo_cliente<<" \n | "<<pivote->id<<" -  Estado: "<<pivote->estado<<endl;
         cout<<"---------------------------------------------------"<<endl;
         pivote = pivote->siguiente;

    }
}
