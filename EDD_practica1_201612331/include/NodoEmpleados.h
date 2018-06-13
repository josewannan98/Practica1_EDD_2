#ifndef NODOEMPLEADOS_H
#define NODOEMPLEADOS_H
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
class NodoEmpleados
{
    public:
        NodoEmpleados();
        NodoEmpleados(string nombre, int turno, string genero, string ubicacion, string tipo_empleado, int tipo);
        virtual ~NodoEmpleados();
        int id;

        string nombre;
        int turno;
        string genero;
        string ubicacion;
        string tipo_empleado;

        NodoEmpleados *anterior;
        NodoEmpleados *siguiente;
        bool en_puesto_trabajo = false;
        bool en_seguridad = false;
        bool en_atencion = false;

    protected:

    private:
};

#endif // NODOEMPLEADOS_H
