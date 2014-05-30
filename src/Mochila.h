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

        Mochila();

        ~Mochila();

         void agregarElemento(string nombreElemento);

         void eliminarElemento(string nombreElemento);

         bool estaVacia();

         int obtenerCantidad();

         //Elemento* buscarElemento(string nombreElemento);

         void iniciarCursor();

         Elemento* obtenerElementoEnCursor();

         bool moverCursorAlSiguiente();

};

#endif // MOCHILA_H
