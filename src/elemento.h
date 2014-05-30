#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "tipos.h"

using namespace std;

class Elemento {
    private:
        string nombre;
        int cantidad;

    public:
    	/* Constructor de la clase Elemento, recibe la palabra y la cantidad inicial */
        Elemento (string nombre);
        /* Post: Devuelve la cantidad total del mismo elemento que hay */
        int getCantidad ();
        /* Post: Devuelve el nombre del elemento */
        string getNombre ();
        /* Post: La nueva cantidad del elemento es la anterior mas los nuevos agregados */
        void sumarCantidad (int nuevoselementos);

};

#endif // ELEMENTO_H
