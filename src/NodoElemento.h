#ifndef NODOELEMENTO_H
#define NODOELEMENTO_H

#include "elemento.h"


class NodoElemento
{
    private:
    NodoElemento* siguiente;
    Elemento* elemento;

public:
	/* Pre: El string recibido debe ser el nombre de un elemento.
	 * Post: Crea el elemento. */
    NodoElemento(string nombreElemento);
	/* Pre:
	 * Post: Libera la memoria pedida para guardar el elemento. */
    ~NodoElemento();
	/* Pre:
	 * Post: Devuelve lo apuntado en *elemento. */
    Elemento* obtenerElemento();
	/* Pre: *nodoSiguiente debe apuntar a un nodo o a NULL.
	 * Post: Deja definido el siguiente nodo de la lista. */
    void asignarSiguiente(NodoElemento* nodoSiguiente);
	/* Pre: 
	 * Post: Devuelve el siguiente nodo de la lista. */
    NodoElemento* obtenerSiguiente();

};

#endif // NODOELEMENTO_H
