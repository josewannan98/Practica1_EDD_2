#include "NodoVuelo.h"

NodoVuelo::NodoVuelo()
{
        this->id = -1;
        this->nombre="";

        this->pasajeros = -1;
        this->equipaje = -1;
        this->paqueteria = -1;

        this->siguiente = nullptr;
        this->anterior = nullptr;

    //ctor
}
NodoVuelo::NodoVuelo(string nombre_, int pasajeros_, int equipaje_, int paqueteria_, int entra_)
{

        this->nombre=nombre_;

        this->pasajeros = pasajeros_;
        this->equipaje = equipaje_;
        this->paqueteria = paqueteria_;

if(entra_==1)
{
    this->entra = true;
}
else
{
    this->entra = false;
}




}

NodoVuelo::~NodoVuelo()
{
    //dtor
}
