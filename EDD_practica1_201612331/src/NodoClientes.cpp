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
    this->genero = "";
    this->siguiente = nullptr;
    this->antetior = nullptr;
}
//se crea un constructor normal
NodoClientes::NodoClientes(string nombre_, string tipo_cliente_, string estado_, int edad_, string informacion_, string ubicacion_, string genero_)
{
    this->nombre = nombre_;
    this->tipo_cliente = tipo_cliente_;
    this->estado = estado_;
    this->edad = edad_;
    this->informacion = informacion_;
    this->ubicacion = ubicacion_;
    this->genero = genero_;


}
//constructor para setear si posee boleto
NodoClientes::NodoClientes(string nombre_, string tipo_cliente_, string estado_, int edad_, string informacion_, string ubicacion_, string genero_, int conboleto)
{
    this->nombre = nombre_;
    this->tipo_cliente = tipo_cliente_;
    this->estado = estado_;
    this->edad = edad_;
    this->informacion = informacion_;
    this->ubicacion = ubicacion_;
    this->genero = genero_;
    if(conboleto==1)
    {
        this->tiene_boleto = true;
    }

}


NodoClientes::~NodoClientes()
{
    //dtor
}
