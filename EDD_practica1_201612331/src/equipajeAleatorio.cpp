#include "equipajeAleatorio.h"
#include "NodoEquipaje.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>

equipajeAleatorio::equipajeAleatorio()
{
    //ctor
}

equipajeAleatorio::~equipajeAleatorio()
{
    //dtor
}
// se crea el equipaje se envia la id actual de la lista - al giaual que clietes aleatorios
NodoEquipaje* equipajeAleatorio::crearequipaje(int id_)
{
    //seteeo random

    int tipo = 1 + rand() % (2-0);
    int entra_ = 1 +rand() % (2-0);

    //seteo informacion

    string tipo_ = "no informacion";
    string informacion_ = "no informacion";
    string ubicacion_ = "no informacion";
    string nombre_ = "Equipaje_0" + to_string(id_);

    //seteo de tipo de equipaje

    if(tipo == 1)
    {
        tipo_ = "Equipaje no Comercial";

    }
    else
    {
        tipo_ = "Equipaje Comercial";
    }


    int entrando = 0;
    if(entra_!= 1)
    {
        informacion_ = "Equipaje Entrando -> Ingreso por Hangares";
        entrando = 1;
    }
    else
    {
        informacion_ = "Equipaje Saliendo -> Esperando Ingreso al Hangar";
    }

    NodoEquipaje *equipaje = new NodoEquipaje(nombre_, tipo_, ubicacion_, informacion_, entrando);
    //se retorna el valor
    return equipaje;

}
