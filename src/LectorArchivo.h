

#include "tipos.h"


class LectorArchivo{
private:
	string ruta, nombre, linea;
public:
	/* pre: El nombre y la ubicación del archivo se suponen válidos.
	 * post: Deja inicializado "linea" con la primer linea del archivo, 
	 * 		"nombre" con el nombre del archivo y "ruta" con la ubicación del 
	 * 		archivo.
	 */
	LectorArchivo();
	~LectorArchivo();
	/* pre: el archivo debe estar abierto para lectura.
	 * post: devuelve el texto contenido en la linea actual y deja apuntada la 
	 * 		siguiente linea.
	 */
	string getLinea(Tarchivo*);
};