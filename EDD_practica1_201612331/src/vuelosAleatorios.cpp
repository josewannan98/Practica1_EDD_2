#include "vuelosAleatorios.h"
#include "NodoVuelo.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

vuelosAleatorios::vuelosAleatorios()
{
    //ctor
}

vuelosAleatorios::~vuelosAleatorios()
{
    //dtor

}

NodoVuelo* vuelosAleatorios::agregarvuelo(int id_)
{

int pasajeros = 10 + rand() % (15-5);
int equipaje = 10 + rand() % (15-5);
int paqueteria = 10 + rand() % (15-5);

int entrando_ = 0 + rand() % (2-0);

string nombre_ = "sin informacion";
int pasajeros_ = 0;
int equipaje_ = 0;
int paqueteria_ = 0;


pasajeros_ = pasajeros;
equipaje_ = equipaje;
paqueteria_ = paqueteria;
nombre_ = "Vuelo_0"+to_string(id_);

NodoVuelo *novo = new NodoVuelo(nombre_,pasajeros_,equipaje_,paqueteria_, entrando_);

return novo;
}
