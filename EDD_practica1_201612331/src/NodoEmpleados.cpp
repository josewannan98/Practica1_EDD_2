#include "NodoEmpleados.h"

NodoEmpleados::NodoEmpleados()
{
    this->id = -1;
    this->turno = -1;
    this->nombre = "";
    this->genero= "";
    this->tipo_empleado="";
    this->ubicacion= "";
    this->en_puesto_trabajo = false;

    this->siguiente = nullptr;
    this->anterior = nullptr;
    //ctor
}
NodoEmpleados::NodoEmpleados(string nombre_, int turno_, string genero_, string ubicacion_, string tipo_empleado_, int tipo_)
{
    this->turno = turno_;
    this->nombre = nombre_;
    this->genero= genero_;
    this->tipo_empleado=tipo_empleado_;
    this->ubicacion= ubicacion_;

    if(tipo_ == 1)
    {
        this->en_atencion = true;
    }
    else
    {
        this->en_seguridad = true;
    }

}

NodoEmpleados::~NodoEmpleados()
{
    //dtor
}

