#include "ListaVuelo.h"
#include "NodoVuelo.h"
#include <iostream>
#include <string>

using namespace std;

ListaVuelo::ListaVuelo()
{
    this->primero = nullptr;
    this->ultimo = nullptr;
    //ctor
}

ListaVuelo::~ListaVuelo()
{
    //dtor
}
void ListaVuelo::ingresar_datos(NodoVuelo *nuevo_vuelo)
{
    NodoVuelo *nuevo = nuevo_vuelo;
    nuevo->id = this->id_actual;

    if(this->primero ==  nullptr)
    {
        this->primero = nuevo;
        this->ultimo = nuevo;
    }
    else
    {

        NodoVuelo *temp = nuevo;
        temp->siguiente = this->primero;
        temp->siguiente->anterior = temp;
        this->primero = temp;

    }

}
void ListaVuelo::mostrar_datos()
{
    NodoVuelo *pivote = this->primero;

    while(pivote != nullptr)
    {

        cout<<"-------------------------[Unidad de Simulacion]---------------------------------"<<endl;
        cout<<"\n    | "<<pivote->id<<" - Nombre Vuelo: "<<pivote->nombre<<"\n    | "<<pivote->id<<" - Cantidad Pasajeros: "<< pivote->pasajeros<<"\n    | "<<pivote->id<<" - Cantidad Equipaje: "<<pivote->equipaje<<"\n    | "<<pivote->id<< " - Cantidad Paquetes: "<<pivote->paqueteria<<" \n    | "<<pivote->id<<" - informacion: "<<pivote->informacion<<"\n"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;

        pivote = pivote->siguiente;
    }
}
void ListaVuelo::mostrar_unidad(NodoVuelo *aux)
{
    NodoVuelo *pivote = aux;

        cout<<"---------------------------------------------------"<<endl;
        cout<<" | "<<pivote->id<<" - Nombre Vuelo: "<<pivote->nombre<<"\n | "<<pivote->id<<" - Cantidad Pasajeros: "<< pivote->pasajeros<<"\n | "<<pivote->id<<" - Cantidad Equipaje: "<<pivote->equipaje<<"\n | "<<pivote->id<< " - Cantidad Paquetes: "<<pivote->paqueteria<<" \n | "<<pivote->id<<" - informacion: "<<pivote->informacion<<endl;
        cout<<"---------------------------------------------------"<<endl;

}
int ListaVuelo::contar()
{
    NodoVuelo *pivote = this->primero;
   int n =0 ;
   while(pivote!=nullptr)
   {
       n++;
       pivote= pivote->siguiente;
   }
   return n;
}
