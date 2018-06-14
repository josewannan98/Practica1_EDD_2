#ifndef COLAESPERA_EQUIPAJE_H
#define COLAESPERA_EQUIPAJE_H
#include "NodoEquipaje.h"

class ColaEspera_Equipaje
{
    public:
        ColaEspera_Equipaje();
        virtual ~ColaEspera_Equipaje();
        NodoEquipaje *primero;
        NodoEquipaje *ultimo;

        void insertar(NodoEquipaje *equipaje);

    protected:

    private:
};

#endif // COLAESPERA_EQUIPAJE_H
