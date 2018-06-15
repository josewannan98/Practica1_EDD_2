#ifndef NODOESTACION_H
#define NODOESTACION_H
#include "NodoEmpleados.h"
#include "ListaClientes.h"
#include "ColaEspera_Clientes.h"
#include "ColaEspera_Equipaje.h"
#include "ColaEspera_Paqueteria.h"


class NodoEstacion
{
    public:
        NodoEstacion();
        NodoEstacion(string nombre,string informacion,int inicio);
        virtual ~NodoEstacion();

        NodoEstacion *anterior;
        NodoEstacion *siguiente;

        int id;
        string nombre;
        string informacion;

        NodoEmpleados *empleado_acargo;
        NodoClientes *cliente_enatencion;
        ColaEspera_Clientes *clientes_encola;
        ColaEspera_Equipaje *equipaje_encola;
        ColaEspera_Paqueteria *paqueteria_encola;

        bool Atencion_alCliente = false;
        bool seguridad_Cliente_inicio = false;
        bool tiene_empleado = false;


    protected:

    private:
};

#endif // NODOESTACION_H
