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
        NodoClientes(string nombre, string tipo_cliente, string estado, int edad, string informacion, string ubicacion, string genero);
        NodoClientes(string nombre, string tipo_cliente, string estado, int edad, string informacion, string ubicacion, string genero, int conboleto);
        virtual ~NodoClientes();
        int id;

        string nombre;
        string tipo_cliente;
        string estado;
        int edad;
        string informacion;
        string genero;
        string ubicacion;

        NodoClientes *siguiente;
        NodoClientes *antetior;

        bool tiene_boleto = false;
        bool esta_enatencion = false;
        bool esta_enseguridad = false;

    protected:

    private:


};

#endif // NODOCLIENTES_H
