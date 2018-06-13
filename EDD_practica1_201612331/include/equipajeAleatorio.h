#ifndef EQUIPAJEALEATORIO_H
#define EQUIPAJEALEATORIO_H
#include "NodoEquipaje.h"


class equipajeAleatorio
{
    public:
        equipajeAleatorio();
        virtual ~equipajeAleatorio();

        NodoEquipaje* crearequipaje(int id);

    protected:

    private:
};

#endif // EQUIPAJEALEATORIO_H
