#include "nodo.h"

NodoCamino::NodoCamino (int coordenadaX , int coordenadaY){
	this-> dato = new Posicion(coordenadaX, coordenadaY);
	this-> siguiente = 0;
	this-> anterior = 0;
}

NodoCamino::~NodoCamino () {
	delete this-> dato;
}

void NodoCamino::setDato (Posicion* nuevoDato){
	this-> dato = nuevoDato;
}

void NodoCamino::setAnterior(NodoCamino * anterior){
	this-> anterior = anterior;
}

void NodoCamino::setSiguiente(NodoCamino *siguiente){
	this-> siguiente = siguiente;
}

Posicion* NodoCamino::getDato(){
	return dato;
}

NodoCamino * NodoCamino::getAnterior(){
	return this-> anterior;
}

NodoCamino* NodoCamino::getSiguiente(){
	return this-> siguiente;
}