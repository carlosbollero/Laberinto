/******************************************************************************
 *                                                                            *
 *                   Implementación clase LectorArchivo                       *
 *                                                                            *
 ******************************************************************************/

#include "LectorArchivo.h"

LectorArchivo::LectorArchivo(string ruta){
	this-> ruta = ruta;

	this-> archivo = new Tarchivo;

	this-> archivo->open(this-> ruta.c_str());
}

LectorArchivo::~LectorArchivo(){
	this-> archivo-> close();
	delete archivo;
}

string LectorArchivo::getRuta(){
	return ruta;
}

string LectorArchivo::getPalabra(){
	// char* palabra;
	// palabra = new char[10];
	// this-> archivo-> get(this-> palabra.c_str(),' ');

	

	return this-> palabra;
}

string LectorArchivo::getLinea(){
	getline (*archivo,linea);
	return this-> linea;
}

bool LectorArchivo::finArchivo(){
	return (archivo-> eof());
}
