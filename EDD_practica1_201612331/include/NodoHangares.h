#ifndef NODOHANGARES_H
#define NODOHANGARES_H
#include "NodoVuelo.h"


class NodoHangares
{
    public:
        NodoHangares();
        NodoHangares(string nombre);
        virtual ~NodoHangares();
        int id;
        string nombre;
        NodoVuelo *vuelo;


        NodoHangares *siguiente;
        bool ocupado = false;


    protected:

    private:
};

#endif // NODOHANGARES_H
