#include "ClientesAleatorios.h"
#include "ListaClientes.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "NodoClientes.h"

using namespace std;

ClientesAleatorios::ClientesAleatorios()
{

    //ctor
}

ClientesAleatorios::~ClientesAleatorios()
{
    //dtor
}
NodoClientes* ClientesAleatorios::crearclientes(int id_)
{

        int edad = 1 + rand() % (91-1);
        int tipo = 1 + rand() % (3-0);
        int conboleto = 0 + rand() % (2-0);
        int genero = 0 + rand() % (2-0);
        int discapacidad = 0 + rand() % (2-0);
        int embarazada = 0 + rand() % (2-0);

        string nombre_ = "sin informacion";
        string tipo_cliente_ = "sin informacion";
        string estado_ = "sin informacion";
        int edad_ = 0;
        string informacion_ = "sin informacion";
        string genero_ = "sin informacion";
        string ubicacion_ = "sin informacion";
        int id = id_;


        if(edad > 18 || edad == 18)
        {
            edad_ = edad;
            if(edad>75)
            {

                if(discapacidad == 1)
                {
                    estado_ = "Persona Discapacitada";

                }
                else
                {
                    estado_ = "Persona de la Tercera Edad";
                }
            }
            else
            {

                if(discapacidad==1)
                {
                    estado_ = "Persona Discapacitada";

                }
                else
                {
                    estado_ = "Persona Mayor de Edad";
                }
            }
        }
        else
        {
                edad_ = edad;
                if(discapacidad==1)
                {
                    estado_ = "Persona Discapacitada";

                }
                else
                {
                    estado_ = "Persona Menor de Edad";
                }
        }

        if(tipo == 1)
        {
            tipo_cliente_ = "Pasajero Premium";
        }
        else if (tipo == 2)
        {
            tipo_cliente_ = "Pasejero Regular";
        }
        else
        {
            tipo_cliente_ = "Pasajero Invitado";
        }

        nombre_ = "Cliente_" + to_string(id);


        if(genero == 1)
        {
            genero_ = "Mujer";
            if(embarazada == 1 && discapacidad != 1)
            {
                estado_ = "Mujer Embarazada";
            }
        }
        else
        {
            genero_ = "Hombre";
        }

        NodoClientes *clientesAleas = new NodoClientes(nombre_, tipo_cliente_, estado_, edad_, informacion_, ubicacion_, genero_, conboleto);





return clientesAleas;
}

