#ifndef LISTAESTACIONES_H
#define LISTAESTACIONES_H
#include "NodoEstacion.h"
#include "NodoEmpleados.h"
#include "Lista_restaurantes.h"
#include "Lista_filaSalaEspera.h"

class ListaEstaciones
{
    public:
        ListaEstaciones();
        virtual ~ListaEstaciones();

        NodoEstacion *primero;
        NodoEstacion *ultimo;

        listas_restaurantes *restaurante = new listas_restaurantes();
        Lista_filaSalaEspera *SalaEspera = new Lista_filaSalaEspera();


        int id_actual = 0;

        bool a_estacionAtencion(NodoClientes *cliente);//ya

        bool a_estacionSeguridad(NodoClientes *cliente);//ya

        bool a_estacionSeguridad1(NodoEquipaje *cliente);//ya

        bool a_estacionSeguridad2(NodoPaqueteria *cliente);//ya

        bool elimnar_atencion();
        void eliminar_seguridad();//ya
        void eliminar_segurida(NodoEstacion* estacion);//ya

        bool enviar_arestaurantes(listas_restaurantes* restaurante, NodoClientes *clientes);
        bool enviar_aSalaEspera(Lista_filaSalaEspera* ColaEspera, NodoClientes *clientes);


        void ingresar_estacion(NodoEstacion *estacion);//ya
        void mostrar_datos();//ya
        bool ingresando_empleado(NodoEmpleados *empleado);//ya

    protected:

    private:
};

#endif // LISTAESTACIONES_H
