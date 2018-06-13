#ifndef VUELOSALEATORIOS_H
#define VUELOSALEATORIOS_H
#include "NodoVuelo.h"


class vuelosAleatorios
{
    public:
        vuelosAleatorios();
        virtual ~vuelosAleatorios();

        NodoVuelo* agregarvuelo(int id_);

    protected:

    private:
};

#endif // VUELOSALEATORIOS_H
