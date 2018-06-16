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

         cout<<"---------------------------------------------------"<<endl;
         cout<<" | "<<pivote->id<<" -  Nombre: "<<pivote->nombre<<"  \n | "<<pivote->id<<" -  Tipo de Paquete: "<< pivote->tipo<<"  \n | "<<pivote->id<<" -  informacion: "<<pivote->informacion<<endl;
         cout<<"---------------------------------------------------"<<endl;
         pivote = pivote->siguiente;


    }
}
void ListaPaqueteria::Mostrar_unidad(NodoPaqueteria *aux)
{
    NodoPaqueteria *pivote = aux;

         cout<<"-------------------------[Unidad de Simulacion]---------------------------------"<<endl;
         cout<<"\n   | "<<pivote->id<<" -  Nombre: "<<pivote->nombre<<"  \n   | "<<pivote->id<<" -  Tipo de Paquete: "<< pivote->tipo<<"  \n   | "<<pivote->id<<" -  informacion: "<<pivote->informacion<<"\n"<<endl;
         cout<<"--------------------------------------------------------------------------------"<<endl;
}
int ListaPaqueteria::contar()
{
    NodoPaqueteria *pivote = this->primero;
   int n =0 ;
   while(pivote!=nullptr)
   {
       n++;
       pivote= pivote->siguiente;
   }
   return n;
}
