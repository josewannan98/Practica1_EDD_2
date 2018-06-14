#include "NodoHangares.h"

NodoHangares::NodoHangares()
{
    this->id = -1;
    this->nombre = "";
    //ctor
}
NodoHangares::NodoHangares(string nombre_)
{
    this->nombre = nombre_;
}

NodoHangares::~NodoHangares()
{
    //dtor
}
