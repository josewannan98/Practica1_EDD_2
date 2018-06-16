#ifndef COLAESPERA_PAQUETERIA_H
#define COLAESPERA_PAQUETERIA_H
#include "NodoPaqueteria.h"

class ColaEspera_Paqueteria
{
    public:
        ColaEspera_Paqueteria();
        virtual ~ColaEspera_Paqueteria();
        NodoPaqueteria *primero;
        NodoPaqueteria *ultimo;
        int id_actual = 0;
        void insertar(NodoPaqueteria *equipaje);
        void push_(string estacion);

    protected:

    private:
};

#endif // COLAESPERA_PAQUETERIA_H
