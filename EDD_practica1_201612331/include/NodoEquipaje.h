#ifndef NODOEQUIPAJE_H
#define NODOEQUIPAJE_H
#include "NodoClientes.h"
#include <iostream>

using namespace std;

class NodoEquipaje
{
    public:
        NodoEquipaje();

        NodoEquipaje(string nombre, string tipo, string ubicacion, string informacion);
        virtual ~NodoEquipaje();

         int id;

         string nombre;
         string tipo;//randomizando
         string informacion;
         string ubicacion;

         NodoEquipaje *anterior;
         NodoEquipaje *siguiente;


         bool esta_enrevision = false;


    protected:

    private:
};

#endif // NODOEQUIPAJE_H
