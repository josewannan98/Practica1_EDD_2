#ifndef PAQUETERIAALEATORIA_H
#define PAQUETERIAALEATORIA_H
#include "NodoPaqueteria.h"


class paqueteriaAleatoria
{
    public:
        paqueteriaAleatoria();
        virtual ~paqueteriaAleatoria();

        NodoPaqueteria* crearpaquete(int id);

    protected:

    private:
};

#endif // PAQUETERIAALEATORIA_H
