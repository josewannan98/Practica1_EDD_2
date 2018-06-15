#ifndef COLAESPERA_CLIENTES_H
#define COLAESPERA_CLIENTES_H
#include "NodoClientes.h"


class ColaEspera_Clientes
{
    public:
        ColaEspera_Clientes();
        virtual ~ColaEspera_Clientes();
        NodoClientes *primero;
        NodoClientes *ultimo;


        void insertar_alinicio(NodoClientes *cliente);
        void insertar_normal(NodoClientes *cliente);
        void insertar_ordenado(NodoClientes *cliente);


    protected:

    private:
};

#endif // COLAESPERA_CLIENTES_H
