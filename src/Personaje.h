<<<<<<< HEAD
/******************************************************************************
 *                                                                            *
 *                        Definición clase Personaje                          *
 *                                                                            *
 ******************************************************************************/

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "tipos.h"
#include "Posicion.h"
#include "Mochila.h"
#include "Camino.h"



class Personaje{
private:
	Mochila* mochila;
    Posicion* posicionActual;
    Camino* camino;
    char orientacion;  //Indica hacia donde esta mirando (N,S,E,O)

public:
    /* Pre:
     * Post: Se crea el personaje y su mochila con condiciones iniciales previas
     * a generar un camino. */
	Personaje(Mochila* mochila);
	/* Pre:
	 * Post:  */
	~Personaje();
    /* Pre:
     * Post: La orientacion del personaje queda modificada a la nueva
     * orientación hacia donde continuar. */
    void girar(char orientacion);
    /* Pre: 
     * Post: Devuelve hacia donde está mirando el personaje. */
    char getOrientacion();
    /* Pre:
     * Post: El personaje se para en un nuevo camino para realizar el recorrido. */
    void iniciarNuevoCamino(Camino* camino);
	/* Pre:
	 * Post: Se crea una posicion nueva y se actualiza posicionActual a la nueva
     * posición, tantas veces como cantidad lo indique. */
	void avanzar(unsigned int cantidad);
    /* Pre:
     * Post: Queda creado un nuevo elemento con el nombre del argumento y se
     * agrega a la mochila. */
    void levantarElemento(string elemento);
    /* Pre: La mochila debe contener al elemento.
     * Post: Se elimina el elemento de la mochila y se lo agrega a la posicion
     * actual. */
    void tirarElemento(string nombre);
    /* Pre:
     * Post: Devuelve un puntero a donde se encuentra el personaje. */
    Posicion* getPosicionActual();

};

#endif