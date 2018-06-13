#include "ClientesAleatorios.h"

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

        //en esta parte del codigo se crea el random con los que trabajaremos las condicionales de
        //personalidad[atributos] del Nodo

        int edad = 1 + rand() % (91-1);
        int tipo = 1 + rand() % (3-0);
        int conboleto = 0 + rand() % (2-0);
        int genero = 0 + rand() % (2-0);
        int discapacidad = 0 + rand() % (2-0);
        int embarazada = 0 + rand() % (2-0);

        //Inicializamos la informacion puede iniciarse con cualquier valor incluso vacio pero si se inicializa vacio se pierde la info
        //preferiblemente iniciar con alguna cadena cualquiera

        string nombre_ = "sin informacion";
        string tipo_cliente_ = "sin informacion";
        string estado_ = "sin informacion";
        int edad_ = 0;
        string informacion_ = "sin informacion";
        string genero_ = "sin informacion";
        string ubicacion_ = "sin informacion";
        int id = id_;
        int estado_o = 0;

        //se inicializan las condicionales con las que usamos los random

        //iniciamos con edad

        if(edad > 18 || edad == 18)
        {
            edad_ = edad;
            if(edad>75)
            {


            //si esta discapacitado cambia su estado
                if(discapacidad == 1)
                {
                    estado_ = "Persona Discapacitada";
                    estado_o = 1;

                }
                else
                {
                    estado_ = "Persona de la Tercera Edad";
                    estado_o = 2;
                }
            }
            else
            {

            //si no es mayor a 75 se imagina es nicamente mayor de edad

            //si es discapacitada se cambia el estado
                if(discapacidad==1)
                {
                    estado_o = 1;
                    estado_ = "Persona Discapacitada";

                }
                else
                {
                    estado_o = 4;
                    estado_ = "Persona Mayor de Edad";
                }
            }
        }
        else
        {
                edad_ = edad;

                // si es menor de edad

                //si esta discapacitado
                if(discapacidad==1)
                {
                    estado_ = "Persona Discapacitada";
                    estado_o = 1;

                }
                else
                {
                    estado_ = "Persona Menor de Edad";
                    estado_o = 5;
                }
        }

        //seteas los tipos de clientes conforme a tu random

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


        //seteas su genero de acuerdo al randmon

        if(genero == 1)
        {
            genero_ = "Mujer";
            if(embarazada == 1 && discapacidad != 1)
            {
                estado_ = "Mujer Embarazada";
                estado_o = 3;
            }


        }
        else
        {
            genero_ = "Hombre";
        }

        //se crean el Nodo a agregar al cliente se envia el int boleto para reconstruir si posee boleto

        NodoClientes *clientesAleas = new NodoClientes(nombre_, tipo_cliente_, estado_, edad_, informacion_, ubicacion_, genero_, conboleto, estado_o);




//se retorna los nodos

return clientesAleas;
}

