#ifndef LISTAESTACIONES_H
#define LISTAESTACIONES_H
#include "NodoEstacion.h"

class ListaEstaciones
{
    public:
        ListaEstaciones();
        virtual ~ListaEstaciones();

        NodoEstacion *primero;
        NodoEstacion *ultimo;
        int id_actual = 0;

        void ingresar_estacion(NodoEstacion *estacion);
        void mostrar_datos();

    protected:

    private:
};

#endif // LISTAESTACIONES_H
