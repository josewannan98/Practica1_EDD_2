#ifndef LISTA_SALAESPERA_H
#define LISTA_SALAESPERA_H
#include "NodoSalaEspera.h"


class Lista_SalaEspera
{
    public:
        Lista_SalaEspera();
        virtual ~Lista_SalaEspera();
        int id_actual =0 ;
        NodoSalaEspera *primero;
        NodoSalaEspera *ultimo;

        void insertar_datos(NodoSalaEspera *nevo);
        bool sala_llena = false;
        int personas_aqui();

    protected:

    private:
};

#endif // LISTA_SALAESPERA_H
