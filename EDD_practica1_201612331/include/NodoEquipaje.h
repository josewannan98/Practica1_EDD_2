#ifndef NODOEQUIPAJE_H
#define NODOEQUIPAJE_H
#include "NodoClientes.h"
#include <iostream>

using namespace std;

class NodoEquipaje
{
    public:
        NodoEquipaje();
        NodoEquipaje(string nombre, string tipo, string ubicacion);
        virtual ~NodoEquipaje();

         int id;

         string nombre;
         string tipo;

         string ubicacion;


    protected:

    private:
};

#endif // NODOEQUIPAJE_H
