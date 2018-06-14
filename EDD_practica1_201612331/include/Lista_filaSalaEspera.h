#ifndef LISTA_FILASALAESPERA_H
#define LISTA_FILASALAESPERA_H
#include "Lista_SalaEspera.h"
#include "NodoColumna_espera.h"


class Lista_filaSalaEspera
{
    public:
        Lista_filaSalaEspera();
        virtual ~Lista_filaSalaEspera();
        NodoColumna_espera *primero;
        NodoColumna_espera *ultimo;
        int id_actual = 0 ;



        void agregar_nodo(NodoColumna_espera *fila);
        int personas_aqui();

    protected:

    private:
};

#endif // LISTA_FILASALAESPERA_H
