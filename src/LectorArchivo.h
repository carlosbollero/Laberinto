/******************************************************************************
 *                                                                            *
 *                      Definición clase LectorArchivo                        *
 *                                                                            *
 ******************************************************************************/

#include "tipos.h"


class LectorArchivo{
private:
	string ruta, nombre, linea;
	Tarchivo* ptrArchivo;

public:
	/* pre: El nombre y la ubicación del archivo se suponen válidos.
	 * post: Deja inicializado "linea" con la primer linea del archivo, 
	 * 		"nombre" con el nombre del archivo y "ruta" con la ubicación del 
	 * 		archivo.
	 *		Apunta "ptrArchivo" al archivo de texto.
	 */
	LectorArchivo();
	/* Destructor.
	 */
	~LectorArchivo();
	
	/* post: Devuelve la la ubicación del archivo de texto.
	 */
	string getRuta();

	string getNombre();
	/* pre: el archivo debe estar abierto para lectura.
	 * post: devuelve el texto contenido en la linea actual y deja apuntada la 
	 * 		siguiente linea.
	 */
	string getLinea(Tarchivo* archivo);


	void
};