#ifndef NODOCAMINO_H
#define NODOCAMINO_H

#include "tipos.h"
#include "Posicion.h"


class NodoCamino {

private:
	NodoCamino * siguiente;
	NodoCamino *anterior;
	Posicion * dato;


public:
	/* Pre: Debe recibir coordenadas válidas con respecto a la posición 
	 * anterior o 0,0 si es la primera posición del camino.
	 * Post:  */
	NodoCamino (int coordenadaX, int coordenadaY);
	/* Pre:
	 * Post: Elimina de memoria lo contenido en dato. */
	~NodoCamino ();
	/* Pre: 
	 * Post: Deja el dato apuntando a una posición válida o NULL. */
	void setDato (Posicion* nuevoDato);
	/* Pre:
	 * Post: Devuelve el puntero definido como dato. */
	Posicion * getDato ();
	/* Pre: Debe recivir un puntero a algo válido o NULL.
	 * Post: Deja *siguiente apuntado al nodo siguiente */
	void setSiguiente (NodoCamino * siguiente);
	/* Pre:
	 * Post: Devuelve el siguiente nodo del camino o NULL, si es la última
	 * posición. */
	NodoCamino * getSiguiente ();
	/* Pre: 
	 * Post: Devuelve el nodo anterior del camino o NULL, si es la primera
	 * posicón. */
	NodoCamino * getAnterior ();
	/* Pre:
	 * Post: Deja *anterior apuntado al nodo anterior o NULL, si es la primera
	 * posición. */
	void setAnterior (NodoCamino * anterior);
};

#endif // NODOCAMINO_H
