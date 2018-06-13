#include "empleadosAleatorios.h"
#include "NodoEmpleados.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

empleadosAleatorios::empleadosAleatorios()
{
    //ctor
}

empleadosAleatorios::~empleadosAleatorios()
{
    //dtor
}
NodoEmpleados* empleadosAleatorios::crearempleados(int id)
{
    int turnos = 3 + rand() % (25-3);
    int genero = 1 + rand() % (2-0);
    int tipo = 1 + rand() % (2-0);


    string nombre_ = "sin informacion";
    int turno_ = 0;
    string genero_ = "sin informacion";
    string ubicacion_ = "sin informacion";
    string tipo_empleado_ = "sin informacion";

    if(genero == 1)
    {
        genero_ = "Mujer";
    }
    else
    {
        genero_ = "Hombre";
    }
    turno_ = turnos;
    nombre_ = "Empleado_0" + to_string(id);

    if(tipo == 1)
    {
       tipo_empleado_ = "Atencion al Cliente";
    }
    else
    {
        tipo_empleado_ = "Seguridad";
    }

    NodoEmpleados *novo = new NodoEmpleados(nombre_,turno_,genero_,ubicacion_,tipo_empleado_, tipo);

    return novo;
}

