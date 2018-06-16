#include "ListaEmpleados.h"

ListaEmpleados::ListaEmpleados()
{
    //ctor
    this->primero = nullptr;
    this->ultimo = nullptr;
}

ListaEmpleados::~ListaEmpleados()
{
    //dtor
}
void ListaEmpleados::ingresar_datos(NodoEmpleados *novo)
{
    NodoEmpleados *nuevo = novo;
    nuevo->id = this->id_actual;

    if(this->primero==nullptr)
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        this->ultimo->siguiente = nuevo;
        nuevo->anterior = this->ultimo;
        this->ultimo = nuevo;
    }

}
void ListaEmpleados::mostrar_datos()
{
    NodoEmpleados *pivote = this->primero;

    while(pivote != nullptr)
    {
         cout<<"---------------------------------------------------"<<endl;
         cout<<" | "<<pivote->id<<" -  Nombre: "<<pivote->nombre<<"  \n | "<<pivote->id<<" -  Genero: "<< pivote->genero<<"  \n | "<<pivote->id<<" -  Tipo de Empleado: "<<pivote->tipo_empleado<<"  \n | "<<pivote->id<<" -  Turnos de hoy: "<<pivote->turno<<endl;
         cout<<"---------------------------------------------------"<<endl;
          pivote = pivote->siguiente;
    }
}
void ListaEmpleados::mostrar_unidad(NodoEmpleados *aux)
{
    NodoEmpleados *pivote = aux;
         cout<<"-------------------------[Unidad de Simulacion]---------------------------------"<<endl;
         cout<<"\n   | "<<pivote->id<<" -  Nombre: "<<pivote->nombre<<"  \n   | "<<pivote->id<<" -  Genero: "<< pivote->genero<<"  \n   | "<<pivote->id<<" -  Tipo de Empleado: "<<pivote->tipo_empleado<<"  \n   | "<<pivote->id<<" -  Turnos de hoy: "<<pivote->turno<<"\n"<<endl;
         cout<<"--------------------------------------------------------------------------------"<<endl;
}
int ListaEmpleados::contar()
{
   NodoEmpleados *pivote = this->primero;
   int n =0 ;

   while(pivote!=nullptr)
   {
       n++;
       pivote= pivote->siguiente;
   }

   return n;
}
