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

        void insertar(NodoPaqueteria *equipaje);

    protected:

    private:
};

#endif // COLAESPERA_PAQUETERIA_H
