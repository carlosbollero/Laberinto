#include <iostream>
#include <string>
#ifndef ELEMENTO_H
#define ELEMENTO_H

using namespace std;

class Elemento {
    private:
        string nombre;
        int cantidad;
        Elemento* siguiente;

    public:
        Elemento (string nombre, int cantidadinicial);
        int getCantidad ();
        string getNombre ();
        void setSiguiente (Elemento* elementoSiguiente);
        Elemento* getSiguiente ();
        void sumarCantidad (int nuevoselementos);
};

#endif // ELEMENTO_H
