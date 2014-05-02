#ifndef MOCHILA_H
#define MOCHILA_H

#include <iostream>
#include <string>

#include "elemento.h"

using namespace std;

class Mochila
{
    private:
        Elemento* primero;
        int cantidad;

    public:
		/*
			Pre: Ninguna.
			Post: Crea la Mochila.
		*/
        Mochila();

		/*
			Pre: Lista existente.
			Post: Destruye la Mochila.
		*/
        ~Mochila();

		/*
			Pre: Ninguna.
			Post: Agrega un elemento a la Mochila, si el elemento ya existe incrementa su cantidad.
		*/
        void agregarElemento(string nombreElemento);

		/*
			Pre: El elemento debe existir en la Mochila.
			Post: Elimina un elemento de la mochila, si la cantidad del elemento es mayor a 1 la reduce.
		*/
        void eliminarElemento(string nombreElemento);

        /*
			Pre: Ninguna.
			Post: Devuelve verdadero si la Mochila no contiene elementos.
		*/
        bool estaVacia();

        /*
			Pre: Ninguna.
			Post: Retorna la cantidad de elementos en la mochila.
		*/
        int obtenerCantidad();

        /*
			Pre: Ninguna.
			Post: Retorna la dirección del elemento buscado, si no lo encuentra devuelve una dirección nula.
		*/
        Elemento* buscarElemento(string nombreElemento);

        /*
			Pre: La posicion del elemento debe ser mayor a cero y menor o igual a la cantidad total de elementos.
			Post: Retorna la dirección del elemento en dicha posicion.
		*/
        Elemento* obtenerElemento(int posicion);
};

#endif // MOCHILA_H
