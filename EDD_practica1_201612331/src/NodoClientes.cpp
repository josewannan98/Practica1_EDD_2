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
NodoClientes::NodoClientes(string nombre_, string tipo_cliente_, string estado_, int edad_, string informacion_, string ubicacion_, string genero_, int conboleto, int estado_o)
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

    if(estado_o==1)
    {
        this->discapacitado_ = true;
    }
    else if(estado_o==2)
    {
        this->terecera_edad = true;

    }
    else if(estado_o==3)
    {
        this->embarazada_ = true;
    }
    else if(estado_o==4)
    {
        this->mayor_edad = true;
    }
    else
    {
        this->menor_edad = true;
    }

}


NodoClientes::~NodoClientes()
{
    //dtor
}
