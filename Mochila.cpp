#include "Mochila.h"

Mochila::Mochila()
{
    this->primero = 0;
    this->cantidad = 0;

}

Mochila::~Mochila(){

    if (!estaVacia()){

        Elemento* elementoSiguiente;
        Elemento* elementoAEliminar = this->primero;
        while (elementoAEliminar->getSiguiente() != 0){

            elementoSiguiente = elementoAEliminar->getSiguiente();
            delete elementoAEliminar;
            elementoAEliminar = elementoSiguiente;

        }
        delete elementoAEliminar;

    }

    this->primero = 0;
    this->cantidad = 0;

}

void Mochila::eliminarElemento(string nombreElemento){

    Elemento* elementoActual = this->primero;
    Elemento* elementoAnterior;

    if (elementoActual->getNombre() == nombreElemento){
        elementoActual->sumarCantidad(-1);

        if (elementoActual->getCantidad() == 0){

            this->primero = primero->getSiguiente();
            delete elementoActual;
            elementoActual = 0;
            this->cantidad--;


        }

    }
    else{

        while(elementoActual->getNombre() != nombreElemento && (elementoActual->getSiguiente() != 0)){

                elementoAnterior = elementoActual;
                elementoActual = elementoActual->getSiguiente();

        }

            elementoActual->sumarCantidad(-1);

            if (elementoActual->getCantidad() == 0){

                elementoAnterior->setSiguiente(elementoActual->getSiguiente());
                this->cantidad--;
                delete elementoActual;
                elementoActual = 0;
            }
    }
}

Elemento* Mochila::buscarElemento(string nombreElemento){

    bool encontro = false;
    Elemento* elementoActual = this->primero;


    while((elementoActual->getNombre() != nombreElemento) && (elementoActual->getSiguiente() != 0)){

            elementoActual = elementoActual->getSiguiente();

    }

    encontro = (elementoActual->getNombre() == nombreElemento);

    if (!encontro){

        elementoActual = 0;

    }

    return elementoActual;

}

void Mochila::agregarElemento(string nombreElemento){

    Elemento* nuevoElemento = new Elemento(nombreElemento);

    if (this->estaVacia()){

        this->primero = nuevoElemento;
        this->cantidad++;
    }
    else{

        Elemento* elementoActual = this->primero;

        while((elementoActual->getNombre() != nombreElemento) && (elementoActual->getSiguiente() != 0)){

            elementoActual = elementoActual->getSiguiente();

        }

        if (elementoActual->getNombre() == nombreElemento){

            elementoActual->sumarCantidad(1);
            delete nuevoElemento;

        }
        else{

            elementoActual->setSiguiente(nuevoElemento);
            this->cantidad++;
        }

    }
}

Elemento* Mochila::obtenerElemento(int posicion){

    Elemento* elementoActual = this->primero;

    if (posicion <= this->obtenerCantidad()){

        int i = 1;
        while(i < posicion){

            elementoActual = elementoActual->getSiguiente();
            i++;

        }


    }

    return elementoActual;

}

int Mochila::obtenerCantidad(){

    return this->cantidad;

}

bool Mochila::estaVacia(){

    return (this->primero == 0);

}
