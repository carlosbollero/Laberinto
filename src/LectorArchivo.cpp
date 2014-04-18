/******************************************************************************
 *                                                                            *
 *                   Implementación clase LectorArchivo                       *
 *                                                                            *
 ******************************************************************************/

#include "LectorArchivo.h"

LectorArchivo::LectorArchivo(string ruta, string nombre){
	this-> ruta = ruta;
	this-> nombre = nombre;

	this-> archivo->open(this-> ruta, ios::in);
}

LectorArchivo::~LectorArchivo(){
	this-> archivo-> close();
}

/*string LectorArchivo::getRuta(){
	return ruta->;
}

string LectorArchivo::getNombre(){

}
*/

string LectorArchivo::getLinea(){
	getline (*archivo,linea);
	return this-> linea;
}
