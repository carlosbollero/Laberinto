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
	getline (*archivo,this-> palabra,' ');
	return this-> palabra;
}

string LectorArchivo::getLinea(){
	getline (*archivo,this-> linea);
	return this-> linea;
}

bool LectorArchivo::finArchivo(){
	return (archivo-> eof());
}
