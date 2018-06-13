#ifndef LISTAVUELO_H
#define LISTAVUELO_H
#include "NodoVuelo.h"


class ListaVuelo
{
    public:
        ListaVuelo();
        virtual ~ListaVuelo();
        NodoVuelo *primero;
        NodoVuelo *ultimo;

        int id_actual=0;

        void ingresar_datos(NodoVuelo *vuelo_);
        void mostrar_datos();

    protected:

    private:
};

#endif // LISTAVUELO_H
