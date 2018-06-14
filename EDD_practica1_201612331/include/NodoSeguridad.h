#ifndef NODOSEGURIDAD_H
#define NODOSEGURIDAD_H


class NodoSeguridad
{
    public:
        NodoSeguridad();
        virtual ~NodoSeguridad();
        NodoSeguridad *anterior;
        NodoSeguridad *siguiente;
        NodoEmpleados *empleado_acargo;
        ListaClientes *clientes_encola;

        bool Atencion_alCliente = false;
        bool seguridad_Cliente_inicio = false;
        bool seguridad_Cliente_final = false;

    protected:

    private:
};

#endif // NODOSEGURIDAD_H
