#ifndef MOCHILA_H
#define MOCHILA_H

#include "tipos.h"
#include "elemento.h"
#include "NodoElemento.h"

using namespace std;

class Mochila{
private:
    NodoElemento* primero;
    NodoElemento* cursor;
    int cantidad;

public:
    /* Pre:
     * Post: Deja creada una mochila vacía. */
    Mochila();
    /* Pre:
     * Post: Elimina todos los elementos de la mochila. */
    ~Mochila();
    /* Pre: El string debe no ser vacío.
     * Post: Agrega el elemento a la lista de elementos */
    void agregarElemento(string nombreElemento);
    /* Pre: El elemento debe estar contenido en la mochila.
     * Post: Si el elemento está contenido más de una vez, disminuye su 
     * cantidad. Si hay un solo elemento con ese nombre, entonces lo elimina de
     * la mochila. */
    void eliminarElemento(string nombreElemento);
    /* Pre:
     * Post: Devuelve si la mochila tiene algún contenido o no. */
    bool estaVacia();
    /* Pre: 
     * Post: Devuelve la cantidad de elementos que tiene la mochila. */
    int obtenerCantidad();
    /* Pre:
     * Post: Apunta el cursor a NULL. */
    void iniciarCursor();
    /* Pre:
     * Post: Devuelve el elemento que contiene el cursor. */
    Elemento* obtenerElementoEnCursor();
    /* Pre:
     * Post: En caso de poder, mueve el cursor al siguiente elemento y devuelve
     * TRUE. En caso negativo devuelve FALSE. */
    bool moverCursorAlSiguiente();
};

#endif // MOCHILA_H
