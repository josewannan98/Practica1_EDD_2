#include "ListaEstaciones.h"
#include "NodoEmpleados.h"

ListaEstaciones::ListaEstaciones()
{
    this->primero = nullptr;
    this->ultimo = nullptr;
    //ctor
}

ListaEstaciones::~ListaEstaciones()
{
    //dtor
}
void ListaEstaciones::ingresar_estacion(NodoEstacion *estacion)
{
    NodoEstacion *nuevo = estacion;
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
        this->primero->anterior = nuevo;
        nuevo->siguiente = this->primero;
        this->ultimo = nuevo;

    }
}
void ListaEstaciones::mostrar_datos()
{
    NodoEstacion *pivote = this->primero;

    do
    {

        if(pivote->anterior != nullptr)
        {
            cout<<"ANTERIOR ["<<pivote->anterior->nombre<<"]";
        }
        cout<<" - NODO ["<<pivote->nombre<<"]";
        if(pivote->siguiente != nullptr)
        {
            cout<<" - SIGUIENTE ["<<pivote->siguiente->nombre<<"]"<<endl;
        }

        pivote = pivote->siguiente;

    }while(pivote != nullptr && pivote!= this->ultimo->siguiente);
}
bool ListaEstaciones::ingresando_empleado(NodoEmpleados *empleado_)
{
    NodoEstacion *pivote = this->primero;
    bool tts = false;
    do
    {
        if(pivote->tiene_empleado == false)
        {
            pivote->empleado_acargo = empleado_;
            pivote->tiene_empleado = true;
            tts = true;
            break;
        }
        pivote = pivote->siguiente;
    }while(pivote != nullptr && pivote!= this->ultimo->siguiente);
    return tts;
}
