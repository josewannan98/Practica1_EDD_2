#include "NodoClientes.h"

NodoClientes::NodoClientes()
{
    //ctor
    this->edad = -1;
    this->estado ="";
    this->informacion = "";
    this->nombre = "";
    this->tipo_cliente = "";
    this->ubicacion = "";

    this->siguiente = nullptr;
}
NodoClientes::NodoClientes(string nombre_, string tipo_cliente_, string estado_, int edad_, string informacion_, string ubicacion_)
{
    this->nombre = nombre_;
    this->tipo_cliente = tipo_cliente_;
    this->estado = estado_;
    this->edad = edad_;
    this->informacion = informacion_;
    this->ubicacion = ubicacion_;

}


NodoClientes::~NodoClientes()
{
    //dtor
}
