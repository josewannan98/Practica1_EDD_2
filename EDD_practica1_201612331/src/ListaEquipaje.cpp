#include "ListaEquipaje.h"

ListaEquipaje::ListaEquipaje()
{
    this->primero = nullptr;
    this->ultimo = nullptr;
    //ctor
}

ListaEquipaje::~ListaEquipaje()
{
    //dtor
}
void ListaEquipaje::agregar_datos(NodoEquipaje *Novo)
{
    NodoEquipaje *nuevo = Novo;
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
void ListaEquipaje::mostrar_datos()
{
NodoEquipaje *pivote = this->primero;

    while(pivote != nullptr)
    {

         cout<<"---------------------------------------------------"<<endl;
         cout<<" | "<<pivote->id<<" -  Nombre: "<<pivote->nombre<<"  \n | "<<pivote->id<<" -  Tipo de Equipaje: "<< pivote->tipo<<"  \n | "<<pivote->id<<" -  informacion: "<<pivote->informacion<<endl;
         cout<<"---------------------------------------------------"<<endl;
         pivote = pivote->siguiente;

    }
}
void ListaEquipaje::mostrar_unidad(NodoEquipaje *nodo)
{

    NodoEquipaje *pivote = nodo;

         cout<<"---------------------------------------------------"<<endl;
         cout<<" | "<<pivote->id<<" -  Nombre: "<<pivote->nombre<<"  \n | "<<pivote->id<<" -  Tipo de Equipaje: "<< pivote->tipo<<"  \n | "<<pivote->id<<" -  informacion: "<<pivote->informacion<<endl;
         cout<<"---------------------------------------------------"<<endl;
}
