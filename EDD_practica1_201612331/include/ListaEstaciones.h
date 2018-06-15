#ifndef LISTAESTACIONES_H
#define LISTAESTACIONES_H
#include "NodoEstacion.h"
#include "NodoEmpleados.h"
#include "Lista_restaurantes.h"
#include "Lista_filaSalaEspera.h"
#include "ColaEspera_Clientes.h"

class ListaEstaciones
{
    public:
        ListaEstaciones();
        virtual ~ListaEstaciones();

        NodoEstacion *primero;
        NodoEstacion *ultimo;

        Lista_restaurantes *restaurante = new Lista_restaurantes();
        Lista_filaSalaEspera *SalaEspera = new Lista_filaSalaEspera();

        ColaEspera_Clientes *cola_espera = new ColaEspera_Clientes();


        int id_actual = 0;

        bool a_estacionAtencion(NodoClientes *cliente);//ya

        bool a_estacionSeguridad(NodoClientes *cliente);//ya

        bool a_estacionSeguridad1(NodoEquipaje *cliente);//ya

        bool a_estacionSeguridad2(NodoPaqueteria *cliente);//ya

        void elimnar_atencion();
        void eliminar_atention(NodoEstacion *estacion);

        NodoClientes* llamar_coladeEspera();

        void setnuevoColaEspera(ColaEspera_Clientes *cola_clientes);
        void enviar_aseguridad(NodoClientes *cliente);

        NodoClientes* traer_decolaseguridad(NodoEstacion *estacion);


        void eliminar_seguridad();//ya
        void eliminar_segurida(NodoEstacion *estacion);//ya

        void enviar_arestaurantes(Lista_restaurantes *restaurante, NodoClientes *clientes);//ya
        void enviar_aSalaEspera(Lista_filaSalaEspera *ColaEspera, NodoClientes *clientes);//ya


        void ingresar_estacion(NodoEstacion *estacion);//ya
        void mostrar_datos();//ya
        bool ingresando_empleado(NodoEmpleados *empleado);//ya

    protected:

    private:
};

#endif // LISTAESTACIONES_H
