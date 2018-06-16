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
        int id_actual=0;

        void insertar(NodoEquipaje *equipaje);
        bool contiene();
        void push_(string estacion);
        void enviar_alv();


    protected:

    private:
};

#endif // COLAESPERA_EQUIPAJE_H
