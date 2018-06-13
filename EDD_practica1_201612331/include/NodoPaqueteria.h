#ifndef NODOPAQUETERIA_H
#define NODOPAQUETERIA_H
#include "NodoEquipaje.h"
#include <iostream>

using namespace std;


class NodoPaqueteria
{
    public:
        NodoPaqueteria();
        NodoPaqueteria(string nombre, string tipo, string ubicacion, string informacion, int entrandos);
        virtual ~NodoPaqueteria();

        int id;

         string nombre;
         string tipo;//randomizando
         string informacion;
         string ubicacion;

         NodoPaqueteria *anterior;
         NodoPaqueteria *siguiente;


         bool esta_enrevision = false;
         bool entrando = false;

    protected:

    private:
};

#endif // NODOPAQUETERIA_H
