#include "paqueteriaAleatoria.h"
#include "NodoPaqueteria.h"

paqueteriaAleatoria::paqueteriaAleatoria()
{
    //ctor
}

paqueteriaAleatoria::~paqueteriaAleatoria()
{
    //dtor
}
NodoPaqueteria* paqueteriaAleatoria::crearpaquete(int id_)
{
 int tipo = 1 + rand() % (2-0);
    int entra_ = 1 +rand() % (2-0);


    //seteo informacion

    string tipo_ = "no informacion";
    string informacion_ = "no informacion";
    string ubicacion_ = "no informacion";
    string nombre_ = "Paquete_0" + to_string(id_);

    //seteo de tipo de paquete

    if(tipo == 1)
    {
        tipo_ = "Paqueteria no Comercial";

    }
    else
    {
        tipo_ = "Paqueteria Comercial";
    }
    int etrando = 0;

    if(entra_!= 1)
    {
        informacion_ = "Paquete Entrando -> Ingreso por Hangares";
        etrando = 1;
    }
    else
    {
        informacion_ = "Paquete Saliendo -> Esperando Ingreso al Hangar";
    }

    NodoPaqueteria *paqueteria = new NodoPaqueteria(nombre_, tipo_, ubicacion_, informacion_, etrando);


    //se retorna el valor
    return paqueteria;
}
