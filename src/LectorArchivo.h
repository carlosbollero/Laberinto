/******************************************************************************
 *                                                                            *
 *                      Definición clase LectorArchivo                        *
 *                                                                            *
 ******************************************************************************/

#include "tipos.h"


class LectorArchivo{
private:
	string ruta, linea, palabra;
	Tarchivo* archivo;

public:
	/* Pre: El nombre y la ubicación del archivo se suponen válidos.
	 * Post: Asigna a "ruta" la ubicación del archivo de texto. Abre el archivo
	 * para su posterior lectura.
	 */
	LectorArchivo(string ruta);

	/* Pre: 
	 * Post: Se cierra el archivo de texto y se elimina su referencia a memoria
	 */
	~LectorArchivo();

	/* Post: Devuelve la la ubicación del archivo de texto.
	 */
	string getRuta();

	string getPalabra();

	/* Pre: el archivo debe estar abierto para lectura.
	 * Post: devuelve el texto contenido en la linea actual y deja apuntada la 
	 * 		siguiente linea.
	 */
	string getLinea();

	/* Pre:
	 * Post: Devuelve si se llegó al final del archivo.
	 */
	bool finArchivo();
};
