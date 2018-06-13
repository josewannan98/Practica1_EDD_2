#ifndef EMPLEADOSALEATORIOS_H
#define EMPLEADOSALEATORIOS_H
#include "NodoEmpleados.h"


class empleadosAleatorios
{
    public:
        empleadosAleatorios();
        virtual ~empleadosAleatorios();

        NodoEmpleados*  crearempleados(int dato);

    protected:

    private:
};

#endif // EMPLEADOSALEATORIOS_H
