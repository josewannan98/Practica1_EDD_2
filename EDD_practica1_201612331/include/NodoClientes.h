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
        NodoClientes(string nombre, string tipo_cliente, string estado, int edad, string informacion, string ubicacion, string genero, int conboleto, int estado_o);
        virtual ~NodoClientes();
        int id;

        string nombre;
        string tipo_cliente;
        string estado;
        int edad;
        string informacion;
        string genero;
        string ubicacion;
        int tiempo_vuelo;

        NodoClientes *siguiente;
        NodoClientes *antetior;

        bool tiene_boleto = false;
        bool esta_enatencion = false;
        bool esta_enseguridad = false;

        bool mayor_edad = false;
        bool menor_edad = false;
        bool terecera_edad = false;
        bool discapacitado_ = false;
        bool embarazada_ = false;

    protected:

    private:


};

#endif // NODOCLIENTES_H
