/******************************************************************************
 *                                                                            *
 *                     Implementacion clase Personaje                         *
 *                                                                            *
 ******************************************************************************/

#include "Personaje.h"

Personaje::Personaje(Mochila* mochila){
	this-> mochila = mochila;
	this-> posicionActual = 0;
	this-> orientacion = '0';
	this-> camino = 0;
}

Personaje::~Personaje(){
}

void Personaje::girar(char orientacion){
	this-> orientacion = orientacion;
}

char Personaje::getOrientacion(){
	return this-> orientacion;
}

void Personaje::iniciarNuevoCamino(Camino* camino){
	this-> camino = camino;
}

void Personaje::avanzar(unsigned int cantidad){
	if (this-> camino-> caminoVacio()){
		this-> camino-> agregarPosicion(this-> orientacion);
		this-> camino-> moverCursorAlUltimo();
		this-> posicionActual = this-> camino-> obtenerElementoEnCursor();
		cantidad--;
	}
	for (unsigned int i = 0; i < cantidad; i++){
		this-> camino-> agregarPosicion(this-> orientacion);
		
		this-> camino-> moverCursorAlUltimo();
		this-> posicionActual = this-> camino-> obtenerElementoEnCursor();
	}
}

void Personaje::levantarElemento(string nombre){
	this-> mochila-> agregarElemento(nombre);
}

void Personaje::tirarElemento(string nombre){
	this-> mochila-> eliminarElemento(nombre);

}

Posicion* Personaje::getPosicionActual(){
	return this-> posicionActual;
}
