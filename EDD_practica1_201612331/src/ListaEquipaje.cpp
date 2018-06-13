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
         cout<<" | "<<pivote->id<<" -  Nombre: "<<pivote->nombre<<"  \n | "<<pivote->id<<" -  Edad: "<< pivote->edad<<"  \n | "<<pivote->id<<" -  Genero: "<<pivote->genero<<"  \n | "<<pivote->id<<" -  Tipo de Cliente: "<<pivote->tipo_cliente<<" \n | "<<pivote->id<<" -  Estado: "<<pivote->estado<<endl;
         cout<<"---------------------------------------------------"<<endl;
         pivote = pivote->siguiente;

    }
}
