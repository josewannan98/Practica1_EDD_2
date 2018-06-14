#include "NodoRestaurantes.h"

NodoRestaurantes::NodoRestaurantes()
{
    //ctor
    this->id = -1;
}
NodoRestaurantes::NodoRestaurantes(int capacidad_)
{
    this->capacidad = capacidad_;
}

NodoRestaurantes::~NodoRestaurantes()
{
    //dtor
}
