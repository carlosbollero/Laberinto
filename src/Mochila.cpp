#include "Mochila.h"

Mochila::Mochila(){
    this->primero = 0;
    this->cursor = 0;
    this->cantidad = 0;
}

Mochila::~Mochila(){
    if (!estaVacia()){
        this->iniciarCursor();
        this->moverCursorAlSiguiente();
        NodoElemento* nodoAEliminar = this->cursor;
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

void Mochila::eliminarElemento(string nombreElemento){
    this->iniciarCursor();
    this->moverCursorAlSiguiente();
    if (this->obtenerElementoEnCursor()->getNombre() == nombreElemento){
        this->obtenerElementoEnCursor()->sumarCantidad(-1);
        if (this->obtenerElementoEnCursor()->getCantidad() == 0){
            this->primero = this->primero->obtenerSiguiente();
            delete this->cursor;
            this->cantidad--;
        }
    }else{
        NodoElemento* nodoAnterior = this->cursor;
        while((this->moverCursorAlSiguiente()) && (this->obtenerElementoEnCursor()->getNombre() != nombreElemento)){
            nodoAnterior = this->cursor;
        }
        this->obtenerElementoEnCursor()->sumarCantidad(-1);
        if (this->obtenerElementoEnCursor()->getCantidad() == 0){
            nodoAnterior->asignarSiguiente(this->cursor->obtenerSiguiente());
            delete cursor;
            this->cantidad--;
        }
    }
}

void Mochila::agregarElemento(string nombreElemento){
    NodoElemento* nuevoNodo = new NodoElemento(nombreElemento);
    if (this->estaVacia()){
        this->primero = nuevoNodo;        this->cantidad++;
    }
    else{
        this->iniciarCursor();
        bool existeElemento = false;
        NodoElemento* nodoAnterior;
        while(this->moverCursorAlSiguiente() && (!existeElemento)){
            existeElemento = (this->obtenerElementoEnCursor()->getNombre() == nombreElemento);
            nodoAnterior = this->cursor;
        }
        if (existeElemento){
            nodoAnterior->obtenerElemento()->sumarCantidad(1);
            delete nuevoNodo;
        }
        else{
            nodoAnterior->asignarSiguiente(nuevoNodo);
            this->cantidad++;
        }
    }
}

void Mochila::iniciarCursor(){
    this-> cursor = 0;
}

bool Mochila::moverCursorAlSiguiente(){
    if (this->cursor == 0){
        this->cursor = this->primero;
    }
    else{
        this->cursor = this->cursor->obtenerSiguiente();
    }
    return (this->cursor != 0);
}

Elemento* Mochila::obtenerElementoEnCursor(){
    return this->cursor->obtenerElemento();
}

int Mochila::obtenerCantidad(){
    return this->cantidad;
}

bool Mochila::estaVacia(){
    return (this->primero == 0);
}
