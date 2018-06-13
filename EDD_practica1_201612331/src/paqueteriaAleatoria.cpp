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

    if(entra_!= 1)
    {
        informacion_ = "Paquete Entrando -> Ingreso por Hangares";
    }
    else
    {
        informacion_ = "Paquete Saliendo -> Esperando Ingreso al Hangar";
    }

    NodoPaqueteria *paqueteria = new NodoPaqueteria(nombre_, tipo_, ubicacion_, informacion_);


    //se retorna el valor
    return paqueteria;
}
