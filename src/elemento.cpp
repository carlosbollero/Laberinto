#include "elemento.h"

using namespace std;


Elemento::Elemento (string nombre){
    this->nombre = nombre;
    this->cantidad = 1;
}

int Elemento::getCantidad() {
    return this->cantidad;
}

string Elemento::getNombre() {
    return this->nombre;
}

void Elemento::sumarCantidad(int nuevoselementos) {
    this->cantidad += nuevoselementos;
}
