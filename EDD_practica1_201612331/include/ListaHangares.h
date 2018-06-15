#ifndef LISTAHANGARES_H
#define LISTAHANGARES_H
#include "NodoHangares.h"
#include "NodoVuelo.h"


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
        bool ingresar_vuelo(NodoVuelo *vuelo);

    protected:

    private:
};

#endif // LISTAHANGARES_H
