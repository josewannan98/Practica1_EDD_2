#ifndef LISTAHANGARES_H
#define LISTAHANGARES_H
#include "NodoHangares.h"


class ListaHangares
{
    public:
        ListaHangares();
        virtual ~ListaHangares();

        NodoHangares *primero;
        NodoHangares *ultimo;

        int id_actual = 0;

        void ingresar_dato(NodoHangares *asd);
        void mostrar_datos();

    protected:

    private:
};

#endif // LISTAHANGARES_H