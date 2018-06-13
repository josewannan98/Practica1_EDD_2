#ifndef NODOVUELO_H
#define NODOVUELO_H
#include "ListaClientes.h"
#include "ListaPaqueteria.h"
#include "ListaEquipaje.h"


class NodoVuelo
{
    public:
        NodoVuelo();
        NodoVuelo(string nombre_, int pasajeros_, int equipaje_, int paqueteria, int entra_);
        virtual ~NodoVuelo();

        NodoVuelo *anterior;
        NodoVuelo *siguiente;

        int id;
        string nombre;
        ListaClientes *clientes_envuelo;
        ListaPaqueteria *paqueteria_envuelo;
        ListaEquipaje *equipaje_envuelo;
        int pasajeros;
        int equipaje;
        int paqueteria;

        bool entra = false;


    protected:

    private:
};

#endif // NODOVUELO_H
