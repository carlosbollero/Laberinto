#include "NodoElemento.h"

NodoElemento::NodoElemento(string nombreElemento){
    this->elemento = new Elemento(nombreElemento);
    this->siguiente = 0;
}

NodoElemento::~NodoElemento(){
    delete this->elemento;
}

Elemento* NodoElemento::obtenerElemento(){
    return this->elemento;
}

void NodoElemento::asignarSiguiente(NodoElemento* nodoSiguiente){
    this->siguiente = nodoSiguiente;
}

NodoElemento* NodoElemento::obtenerSiguiente(){
    return this->siguiente;
}
