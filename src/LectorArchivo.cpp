/******************************************************************************
 *                                                                            *
 *                   Implementación clase LectorArchivo                       *
 *                                                                            *
 ******************************************************************************/

#include "LectorArchivo.h"

LectorArchivo::LectorArchivo(string ruta, string nombre){
	this-> ruta = new string;
	this-> nombre = new string;
}

LectorArchivo::~LectorArchivo(){

}

string LectorArchivo::getRuta(){
	return ruta->;
}

string LectorArchivo::getNombre(){

}

string LectorArchivo::getLinea(){

}
