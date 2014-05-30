#ifndef NODOELEMENTO_H
#define NODOELEMENTO_H

#include "elemento.h"


class NodoElemento
{
    private:
        NodoElemento* siguiente;
        Elemento* elemento;


    public:
        NodoElemento(string nombreElemento);
        ~NodoElemento();

        Elemento* obtenerElemento();
        void asignarSiguiente(NodoElemento* nodoSiguiente);
        NodoElemento* obtenerSiguiente();

};

#endif // NODOELEMENTO_H
