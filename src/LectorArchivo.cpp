/******************************************************************************
 *                                                                            *
 *                   Implementación clase LectorArchivo                       *
 *                                                                            *
 ******************************************************************************/

#include "LectorArchivo.h"

LectorArchivo::LectorArchivo(string ruta){
	this-> ruta = ruta;
	this-> archivo = new Tarchivo;
	this-> archivo-> open(this-> ruta.c_str());
}

LectorArchivo::~LectorArchivo(){
	this-> archivo-> close();
	delete archivo;
}

string LectorArchivo::getRuta(){
	return ruta;
}

string LectorArchivo::getPalabra(){
    *archivo >> this->palabra;
	if (this-> esComentario()){
		*archivo >> this->palabra;
	}
	return this-> palabra;
}

string LectorArchivo::getLinea(){
	getline (*archivo,this-> linea);
	return this-> linea;
}

bool LectorArchivo::finArchivo(){
	return (this-> archivo-> eof());
}

bool LectorArchivo::esComentario(){
	return (this-> palabra[0] == '-');
}
