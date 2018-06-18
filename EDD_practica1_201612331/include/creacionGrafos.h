#ifndef CREACIONGRAFOS_H
#define CREACIONGRAFOS_H
#include "ListaEstaciones.h"
#include "ListaClientes.h"
#include "ClientesAleatorios.h"
#include "ListaEquipaje.h"
#include "NodoClientes.h"
#include "NodoEquipaje.h"
#include "equipajeAleatorio.h"
#include "ListaPaqueteria.h"
#include "NodoPaqueteria.h"
#include "paqueteriaAleatoria.h"
#include "ListaVuelo.h"
#include "NodoVuelo.h"
#include "vuelosAleatorios.h"
#include "empleadosAleatorios.h"
#include "NodoEmpleados.h"
#include "ListaEmpleados.h"
#include "ListaEstaciones.h"
#include "NodoEstacion.h"
#include "NodoHangares.h"
#include "ListaHangares.h"
#include "NodoRestaurantes.h"
#include "Lista_restaurantes.h"
#include "NodoColumna_espera.h"
#include "Lista_SalaEspera.h"
#include "Lista_filaSalaEspera.h"
#include "NodoSalaEspera.h"
#include "creacionGrafos.h"

class creacionGrafos
{
    public:
        creacionGrafos(){};

        virtual ~creacionGrafos();

        ListaEstaciones *lista_estaciones = new ListaEstaciones();

        ListaVuelo *listavuel = new ListaVuelo();
        ListaClientes *listacien = new ListaClientes();
        ListaEquipaje *listaeq = new ListaEquipaje();
        ListaPaqueteria *listapaq = new ListaPaqueteria();
        ListaEmpleados *listaemp = new ListaEmpleados();

        string grafohistorial = "";
        string col = "";
        string col1 = "";

        string grafoClientes= "";
        string grafoVuelo = "";

        string grafosim="";

        void crear_grafo();
        void agregar_ListaEstacion();//Grafo del cual nacen todos los demas
        void adquirir_atencion(NodoEstacion *atencion);//para cada estacion de atencion

        void adquirir_colaEsperaAtencion(string col);//adquiriendo cola espera atencion
        void adquirir_seguridad(NodoEstacion *seguridad);// para cada estacion seguridad
        void adquierir_colaSeguridad(string col1);//adquiriendo cola espera seguridad
        void adquirir_restaurantes();//adquiere Restaurantes
        void adquiere_restaurant(NodoRestaurantes *restauran);

        void sala_de_Espera();//para sala de espera
        void hangares();

        void generardot();

        void generardotClientes();
        void generardotVuelos();
        void generardotSimulaciones();

        void parasimula1();
        void parasimula2();
        void parasimula3();
        void parasimula4();
        void parasimula5();



    protected:

    private:
};

#endif // CREACIONGRAFOS_H
