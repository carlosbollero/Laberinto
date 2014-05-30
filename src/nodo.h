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

	NodoCamino (int coordenadaX, int coordenadaY, string identificador);

	~NodoCamino ();

	void setDato (Posicion* nuevoDato);

	Posicion * getDato ();

	void setSiguiente (NodoCamino * siguiente);

	NodoCamino * getSiguiente ();

	NodoCamino * getAnterior ();

	void setAnterior (NodoCamino * anterior);
};

#endif // NODOCAMINO_H
