#ifndef NODOESTACION_H
#define NODOESTACION_H
#include "NodoEmpleados.h"
#include "ListaClientes.h"


class NodoEstacion
{
    public:
        NodoEstacion();
        virtual ~NodoEstacion();
        NodoEstacion *anterior;
        NodoEstacion *siguiente;
        NodoEmpleados *empleado_acargo;
        ListaClientes *clientes_encola;

        bool Atencion_alCliente = false;
        bool seguridad_Cliente_inicio = false;
        bool seguridad_Cliente_final = false;

    protected:

    private:
};

#endif // NODOESTACION_H
