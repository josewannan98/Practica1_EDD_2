#ifndef LISTA_RESTAURANTES_H
#define LISTA_RESTAURANTES_H
#include "NodoRestaurantes.h"


class Lista_restaurantes
{
    public:
        Lista_restaurantes();
        virtual ~Lista_restaurantes();
        int id_actual= 0;

        NodoRestaurantes *primero;
        NodoRestaurantes *ultimo;

        void ingresar_restaurante(NodoRestaurantes *nodo);
        int personas_aqui();


    protected:

    private:
};

#endif // LISTA_RESTAURANTES_H
