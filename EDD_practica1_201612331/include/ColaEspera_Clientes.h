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
        int id_actual =0;
        int actual = 0;

        void insertar_alinicio(NodoClientes *cliente);
        void insertar_normal(NodoClientes *cliente);
        int cuantas_personas();



        NodoClientes* enviar_siguiente();
        void push_();


    protected:

    private:
};

#endif // COLAESPERA_CLIENTES_H
