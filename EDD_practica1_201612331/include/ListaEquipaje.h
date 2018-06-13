#ifndef LISTAEQUIPAJE_H
#define LISTAEQUIPAJE_H
#include "NodoEquipaje.h"



class ListaEquipaje
{
    public:
        ListaEquipaje();
        virtual ~ListaEquipaje();
        NodoEquipaje *primero;
        NodoEquipaje *ultimo;
        int id_actual = 0;

        void agregar_datos(NodoEquipaje *novo);
        void mostrar_datos();

    protected:

    private:
};

#endif // LISTAEQUIPAJE_H
