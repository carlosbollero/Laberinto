#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template <class T>
class Lista{

    private:

        Nodo<T>* primero;
        Nodo<T>* cursor;
        int cantidad;

    public:

        Lista<T>();

        ~Lista<T>();

         void agregarElemento(T dato);

         //void eliminarElemento(string nombreElemento);

         bool estaVacia();

         int obtenerCantidad();

         void iniciarCursor();

         T obtenerElementoEnCursor();

         bool moverCursorAlSiguiente();

};

template <class T>
Lista<T>::Lista(){

    this->primero = 0;
    this->cantidad= 0;
    this->cursor = 0;

}

template <class T>
Lista<T>::~Lista(){

    if (!estaVacia()){

        this->iniciarCursor();
        this->moverCursorAlSiguiente();
        Nodo<T>* nodoAEliminar = this->cursor;
        while(this->moverCursorAlSiguiente()){
            delete nodoAEliminar;
            nodoAEliminar = this->cursor;

        }
        delete nodoAEliminar;

    }

    this->primero = 0;
    this->cantidad = 0;
    this->cursor = 0;

}

template <class T>
void Lista<T>::agregarElemento(T dato){

    Nodo<T>* nuevoNodo = new Nodo<T>(dato);

    if (this->estaVacia()){

        this->primero = nuevoNodo;
        this->cantidad++;
    }
    else{

        this->iniciarCursor();
        bool existeElemento = false;
        Nodo<T>* nodoAnterior;

        while(this->moverCursorAlSiguiente() && (!existeElemento)){
            existeElemento = (this->obtenerElementoEnCursor() == dato);
            nodoAnterior = this->cursor;
        }

        if (!existeElemento){

            nodoAnterior->asignarSiguiente(nuevoNodo);
            this->cantidad++;


        }
        else{

            delete nuevoNodo;

        }


    }

}

template <class T>
bool Lista<T>::estaVacia(){

    return (this->primero == 0);

}

template <class T>
int Lista<T>::obtenerCantidad(){

    return this->cantidad;

}

template <class T>
void Lista<T>::iniciarCursor(){

    this->cursor = 0;

}

template <class T>
bool Lista<T>::moverCursorAlSiguiente(){

    if (this->cursor == 0){

        this->cursor = this->primero;

    }
    else{

        this->cursor = this->cursor->obtenerSiguiente();

    }

    //this->cursor = this->cursor->obtenerSiguiente();
    return (this->cursor != 0);

}

template <class T>
T Lista<T>::obtenerElementoEnCursor(){

    return this->cursor->obtenerDato();

}

#endif // LISTA_H
