/******************************************************************************
 *                                                                            *
 *                      Definición clase LectorArchivo                        *
 *                                                                            *
 ******************************************************************************/

#ifndef LECTORARCHIVO_H
#define LECTORARCHIVO_H

#include "tipos.h"


class LectorArchivo{
private:
	string ruta, linea, palabra;
	Tarchivo* archivo;

	/* Pre:
	 * Post: Devuelve TRUE al detectar un comentario en el texto, en caso
	 * contrario, FALSE. */
	bool esComentario();

public:
	/* Pre: El nombre y la ubicación del archivo se suponen válidos.
	 * Post: Asigna a "ruta" la ubicación del archivo de texto. Abre el archivo
	 * para su posterior lectura. */
	LectorArchivo(string ruta);
	/* Pre:
	 * Post: Cierra el archivo de texto y elimina su referencia a memoria. */
	~LectorArchivo();
	/* Post: Devuelve la la ubicación del archivo de texto. */
	string getRuta();
	/* Pre: El archivo debe estar abierto para lectura.
	 * Post: Devuelve el texto contenido en la linea actual hasta un espacio en
	 * blanco y deja apuntada la siguiente linea. */
	string getPalabra();
	/* Pre: El archivo debe estar abierto para lectura.
	 * Post: Devuelve el texto contenido en la linea actual y deja apuntada la
	 * siguiente linea. */
	string getLinea();
	/* Pre:
	 * Post: Devuelve si se llegó al final del archivo. */
	bool finArchivo();

};

#endif // LECTORARCHIVO_H
