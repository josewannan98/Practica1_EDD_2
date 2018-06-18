#ifndef NODORESTAURANTES_H
#define NODORESTAURANTES_H
#include "ColaEspera_Clientes.h"


class NodoRestaurantes
{
    public:
        NodoRestaurantes();
        NodoRestaurantes(int capacidad);
        virtual ~NodoRestaurantes();
        NodoRestaurantes *anterior;
        NodoRestaurantes *siguiente;
        int id;
        int id_actual = 0;
        ColaEspera_Clientes *cliente = new ColaEspera_Clientes();
        int capacidad = 0;
        bool restaurante_lleno = false;

    protected:

    private:
};

#endif // NODORESTAURANTES_H
