#include <iostream>
#include <string>
#include "elemento.h"

using namespace std;

/* Constructor de la clase Elemento, recibe la palabra y la cantidad inicial */
Elemento::Elemento (string nombre, int cantidadinicial) {
    this->nombre = nombre;
    this->cantidad = cantidadinicial;
    this->siguiente = NULL;
}

/* Post: Devuelve la cantidad total del mismo elemento que hay */
int Elemento::getCantidad() {
    return this->cantidad;
}

/* Post: Devuelve el nombre del elemento */
string Elemento::getNombre() {
    return this->nombre;
}

/* Asigna el siguiente elemento
Pre: elementosiguiente debe ser un elemento valido
Post: el siguiente del elemento apunta a elementosiguiente*/
void Elemento::setSiguiente(Elemento* elementosiguiente){
    this->siguiente = elementosiguiente;
}

/* Post: Devuelve el siguiente del elemento, o NULL si todavia no ha sido asignado */
Elemento* Elemento::getSiguiente() {
    return this->siguiente;
}

/* Post: La nueva cantidad del elemento es la anterior mas los nuevos agregados */
void Elemento::sumarCantidad(int nuevoselementos) {
    this->cantidad += nuevoselementos;
}

