#include "nodoElemento.h"

using namespace std;

nodoElemento::nodoElemento (string nombreElemento) {
    this->siguiente = NULL;
    this->elemento = Elemento (nombreElemento);
}

void nodoElemento::setSiguiente (string nombreElementoSiguiente) {
    this->siguiente = new nodoElemento (string nombreElementoSiguiente);
}

Elemento nodoElemento::getElemento () {
    return this->elemento;
}

nodoElemento* nodoElemento::getSiguiente () {
    return this->siguiente;
}

