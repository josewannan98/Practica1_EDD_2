#ifndef NODOCLIENTES_H
#define NODOCLIENTES_H
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
class NodoClientes
{
    public:
        NodoClientes();
        NodoClientes(string nombre, string tipo_cliente, string estado, int edad, string informacion, string ubicacion);
        virtual ~NodoClientes();
        int id;

        string nombre;
        string tipo_cliente;
        string estado;
        int edad;
        string informacion;
        string ubicacion;

        NodoClientes *siguiente;
        NodoClientes *antetior;


    protected:

    private:
        bool tiene_boleto = false;
        bool esta_enatencion = false;
        bool esta_enseguridad = false;

};

#endif // NODOCLIENTES_H
