#ifndef NODOELEMENTO_H
#define NODOELEMENTO_H
#include "elemento.h"

using namespace std;

class nodoElemento {

    public:
        /* Post: Devuelve una instancia de nodoElem*ento cuyo siguiente es nulo y se crea el elemento que contiene, con el nombre recibido por parametro y su cantidad inicial seteada en 1 */
        nodoElemento(string nombreElemento);

        /* Post: Crea un nuevo nodoElemento y lo coloca como siguiente del nodoElemento deseado */
        void setSiguiente (string nombreElemento);

        /* Post: Devuelve el elemento asociado al nodo */
        Elemento getElemento ();

        /* Post: Devuelve el siguiente nodo del nodo deseado o NULL si no se ha seteado un siguiente
        nodoElemento* getSiguiente ();

    private:
        nodoElemento* siguiente;
        Elemento elemento;
};

#endif // NODOELEMENTO_H
