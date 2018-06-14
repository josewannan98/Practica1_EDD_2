#ifndef NODOCOLUMNA_ESPERA_H
#define NODOCOLUMNA_ESPERA_H
#include "Lista_SalaEspera.h"


class NodoColumna_espera
{
    public:
        NodoColumna_espera();
        virtual ~NodoColumna_espera();
        NodoColumna_espera *siguiente;
        int id;
        Lista_SalaEspera *fila;

        bool ocupado = false;


    protected:

    private:
};

#endif // NODOCOLUMNA_ESPERA_H
