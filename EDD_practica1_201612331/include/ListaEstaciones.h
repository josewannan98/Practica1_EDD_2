#ifndef LISTAESTACIONES_H
#define LISTAESTACIONES_H
#include "NodoEstacion.h"
#include "NodoEmpleados.h"
#include "Lista_restaurantes.h"
#include "Lista_filaSalaEspera.h"
#include "ColaEspera_Clientes.h"
#include "ColaEspera_Equipaje.h"
#include "ColaEspera_Paqueteria.h"
#include "ListaHangares.h"


class ListaEstaciones
{
    public:
        ListaEstaciones();
        virtual ~ListaEstaciones();

        NodoEstacion *primero;
        NodoEstacion *ultimo;

        Lista_restaurantes *restaurante = new Lista_restaurantes();
        Lista_filaSalaEspera *SalaEspera = new Lista_filaSalaEspera();

        ListaHangares *hangares = new ListaHangares();

        ColaEspera_Clientes *cola_espera = new ColaEspera_Clientes();
        ColaEspera_Equipaje *cola_equipaje = new ColaEspera_Equipaje();
        ColaEspera_Paqueteria *cola_paqueteria = new ColaEspera_Paqueteria();

        ColaEspera_Clientes *cola_espera_atencion = new ColaEspera_Clientes();


        int id_actual = 0;
        int personas_salieronalAvion =0;
        int aviones_despegaron=0;
        int perdieron_suvuelodeRestaurantes =0;
        int perdieron_suvuelodeSaladeEspera=0;
        int personas_ensalaespera=0;
        int pesonasRestau = 0;


        void pasarARestaurantes(NodoEstacion *estacion);
        bool a_estacionAtencion(NodoClientes *cliente);//ya

        bool a_estacionSeguridad(NodoClientes *cliente);//ya

        bool a_estacionSeguridad1(NodoEquipaje *cliente);//ya

        bool a_estacionSeguridad2(NodoPaqueteria *cliente);//ya


        void mandar_alvAvion(NodoClientes *Clientes);
        void reduce_fatfat(NodoRestaurantes *restaurante);
        void reducir_enRestaurantes();

        void actualizarcolasEq(NodoEstacion *estacion);//ya

        void actualizarcolasPa(NodoEstacion *estacion);//ya


        void eliminar_seguridad2();//ya
        void eliminar_seguridad3();





        void ingresar_estacion(NodoEstacion *estacion);//ya
        void mostrar_datos();//ya
        bool ingresando_empleado(NodoEmpleados *empleado);//ya


        void actualizarestado_empleados();

        int encontrarempleados();



        //[Atencion]--ESTACION

        void actualizarestacionAtencion();

        void adquirirestado_atencion(); // adquirimos si posee cliente y empleado
        NodoClientes* nuevo_clienteAtencion();// mandamos a llamar un nuevo cliente;
        void actualizarEstacion(NodoClientes *cliente, NodoEstacion *estacion);
        void enviarCliente_aSeguridad(NodoClientes *cliente);
        NodoEstacion* preguntar_estadoSeguridad();// mandamos a preguntar si hay una estacion vacia

        //[Seguridad] -- SEGURIDAD

        void actualizarestacionSeguridad();

        void adquirirestado_seguridad(); // adquirimos si posee cliente y empleado [igual que en atencion]
        void actualizarEstacion1(NodoClientes *cliente, NodoEstacion *estacion);
        NodoClientes* nuevo_clienteSeguridad();
        void enviarCliente_aEsperar(NodoClientes *clientes);

        int personas_enrestaurante(); // extra-> para saber cuantos entraron aqui
        int personas_enSaladeEspera(); // extra-> para saber cuantos entraron aqui

        //Salas de Espera con random
        bool enviar_arestaurantes(NodoClientes *clientes);//envio a restaurantes
        bool enviar_aSalaEspera(NodoClientes *clientes);//encio a sala de espera


        //reduciendo en sala de espera
        void reducir_salasdeEspera();
    protected:

    private:
};

#endif // LISTAESTACIONES_H
