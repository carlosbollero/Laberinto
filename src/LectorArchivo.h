

#include "tipos.h"


class LectorArchivo{
private:

public:
	/* pre: Debe recibir
	LectorArchivo();
	~LectorArchivo();
	/* pre: el archivo debe estar abierto para lectura.
	 * post: devuelve el texto contenido en la linea actual y deja apuntada la 
	 * siguiente linea.
	 */
	string getLinea(Tarchivo*);
};