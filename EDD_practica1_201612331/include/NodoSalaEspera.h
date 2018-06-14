#ifndef NODOSALAESPERA_H
#define NODOSALAESPERA_H
#include "NodoClientes.h"


class NodoSalaEspera
{
    public:
        NodoSalaEspera();

        virtual ~NodoSalaEspera();

        int id;
        NodoClientes *cola_clientes;

        NodoSalaEspera *anterior;
        NodoSalaEspera *siguiente;

    protected:

    private:
};

#endif // NODOSALAESPERA_H
