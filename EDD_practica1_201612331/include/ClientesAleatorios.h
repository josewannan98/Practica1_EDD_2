#ifndef CLIENTESALEATORIOS_H
#define CLIENTESALEATORIOS_H

#include "NodoClientes.h"


class ClientesAleatorios
{
    public:
        ClientesAleatorios();
        virtual ~ClientesAleatorios();

        NodoClientes* crearclientes(int id);

    protected:

    private:
};

#endif // CLIENTESALEATORIOS_H
