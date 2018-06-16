#include "ColaEspera_Equipaje.h"
#include "NodoEquipaje.h"


ColaEspera_Equipaje::ColaEspera_Equipaje()
{
    //ctor
    this->primero = nullptr;
    this->ultimo = nullptr;
}

ColaEspera_Equipaje::~ColaEspera_Equipaje()
{
    //dtor
}
void ColaEspera_Equipaje::insertar(NodoEquipaje *nodo)
{
    NodoEquipaje *nuevo = nodo;
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

void ColaEspera_Equipaje::push_(string estacion)
{
    cout<<" eliminando... \n"<<endl;

       if(this->primero!=nullptr)
        {
           if(this->primero->siguiente!=nullptr)
           {
             cout<<" El Equipaje ["<<this->primero->nombre<<"] paso a ser revisado y,";
             NodoEquipaje *temp = this->primero;
             NodoEquipaje *aux = temp->siguiente;
             aux->anterior = nullptr;
             this->primero = aux;
             delete temp;
             cout<<"\n Salio de la estacion ["<<estacion<<"] y se retiro del aeropuerto \n en un vuelo comercial"<<endl;
           }
           else
           {
               cout<<" El Equipaje ["<<this->primero->nombre<<"] paso a ser revisado y,";
               this->primero = nullptr;
               delete this->primero;
               cout<<"\n Salio de la estacion ["<<estacion<<"] y se retiro del aeropuerto \n en un vuelo comercial"<<endl;
           }

        }
        else
        {
            cout<<" Los agentes de Seguridad no encuentran equipajes por revisar.."<<endl;
        }
        cout<< " finalizando... "<<endl;

}
bool ColaEspera_Equipaje::contiene()
{
    NodoEquipaje *pivote = this->primero;
    int tiene = 0;
    while(pivote!=nullptr)
    {
        cout<<pivote->id<<endl;
        tiene++;
        break;
        pivote = pivote->siguiente;
    }

    if(tiene>0)
    {
        return true;
    }
    else
    {
      return false;
    }
}
