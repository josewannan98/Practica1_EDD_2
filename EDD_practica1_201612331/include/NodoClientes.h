#ifndef NODOCLIENTES_H
#define NODOCLIENTES_H


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


    protected:

    private:
        bool tiene_boleto = false;
        bool esta_enatencion = false;
        bool esta_enseguridad = false;
        bool
};

#endif // NODOCLIENTES_H
