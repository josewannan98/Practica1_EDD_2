#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H
#include "NodoEmpleados.h"


class ListaEmpleados
{
    public:
        ListaEmpleados();
        virtual ~ListaEmpleados();
        int id_actual=0;

        NodoEmpleados *primero;
        NodoEmpleados *ultimo;

        void ingresar_datos(NodoEmpleados *empleado);
        void mostrar_datos();
        void mostrar_unidad(NodoEmpleados *empleado);

    protected:

    private:
};

#endif // LISTAEMPLEADOS_H
