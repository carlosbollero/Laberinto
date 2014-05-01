/******************************************************************************
 *                                                                            *
 *                     Implementación clase Personaje                         *
 *                                                                            *
 ******************************************************************************/

#include "Pensonaje.h"

Personaje::Personaje(){
	this-> mochila = new Mochila;
	this-> posicionActual = 0;
	this-> orientacion = '0';
	this-> camino = 0;
}

Personaje::~Personaje(){

}

void Personaje::girar(char orientacion){
	this-> orientacion = orientacion;
}

void Personaje::avanzar(unsigned int cantidad){
	switch (this-> orientacion){
		case 'N':
			for (unsigned int i = 1; i <= cantidad; i++){
				Posicion* nuevaposicion = new Posicion;
				this-> posicionActual-> setSiguienteNorte(nuevaPosicion);
				this-> posicionActual = this->posicionActual-> getSiguienteNorte();
			}
		break;
		case 'S':
			for (unsigned int i = 1; i <= cantidad; i++){
				Posicion* nuevaposicion = new Posicion;
				this-> posicionActual-> setSiguienteSur(nuevaPosicion);
				this-> posicionActual = this->posicionActual-> getSiguienteSur();
			}
		break;
		case 'E':
			for (unsigned int i = 1; i <= cantidad; i++){
				Posicion* nuevaposicion = new Posicion;
				this-> posicionActual-> setSiguienteEste(nuevaPosicion);
				this-> posicionActual = this->posicionActual-> getSiguienteEste();
			}
		break;
		case 'O':
			for (unsigned int i = 1; i <= cantidad; i++){
				Posicion* nuevaposicion = new Posicion;
				this-> posicionActual-> setSiguienteOeste(nuevaPosicion);
				this-> posicionActual = this->posicionActual-> getSiguienteOeste();
			}
		break;
	}	
}

void Personaje::Unir(Posicion* ){

}

void Personaje::levantarElemento(string elemento){
	Elemento* nuevoElemento = new Elemento(elemento);
	this-> mochila-> insertarElemento(nuevoElemento);
}

void Personaje::tirarElemento(string nombre){
	Elemeto* elemento = this-> mochila-> buscarElemento(nombre);
	this-> posicionActual-> setElemento(elemento);
	this-> mochila-> eliminarElemento(elemento->nombre);//consultar si el parametro es el elemento o el nombre

}

Posicion* Personaje::getPosicionActual(){
	return this-> posicionActual;
}

void Personaje::marcarBifurcacion(){

}

/*bool Personaje::validarOrientacion(){
	return (this-> orientacion != 'N' || this-> orientacion != 'S' || 
		this-> orientacion != 'E' || this-> orientacion != 'O' );
}*/
