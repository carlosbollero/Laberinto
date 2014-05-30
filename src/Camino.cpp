#include <iostream>
#include "Camino.h"

using namespace std;

Camino::Camino(int R, int G, int B){
    this->cursor = 0;
    this->color = new int[3];
    this->color[0] = R;
    this->color[1] = G;
    this->color[2] = B;
    this->primero = 0;
    this->ultimo = 0;
    this->xminimo = 0;
    this->xmaximo = 0;
    this->yminimo = 0;
    this->ymaximo = 0;
    this->longitud = 0;
    this->identificador = "";
}

Camino::~Camino (){
    while (!this->caminoVacio()){
        eliminarPrimero();
    }
    this->primero = 0;
    this->ultimo = 0;
    delete []color;
}

void Camino::compararCoordenadas(Posicion* posicionDeReferencia){

    if (posicionDeReferencia->obtenerCoordX() < xminimo->obtenerCoordX()){
            this->xminimo = posicionDeReferencia;

    }

    if(posicionDeReferencia->obtenerCoordX() > xmaximo->obtenerCoordX()){
            this->xmaximo = posicionDeReferencia;

    }

    if(posicionDeReferencia->obtenerCoordY() < yminimo->obtenerCoordY()){
            this->yminimo = posicionDeReferencia;

    }

    if(posicionDeReferencia->obtenerCoordY() > ymaximo->obtenerCoordY()){
        this->ymaximo = posicionDeReferencia;

    }

}

void Camino::calcularCoordenadas(char orientacion, int &coordenadaX, int &coordenadaY){
    switch(orientacion){
        case 'N':
                    coordenadaY++;
                    break;
        case 'S':
                    coordenadaY--;
                    break;
        case 'E':
                    coordenadaX++;
                    break;
        case 'O':
                    coordenadaX--;
                    break;
    }
}

void Camino::agregarPosicion(char orientacion){

    int x = 0, y = 0;

    NodoCamino* nuevoNodo = new NodoCamino(x, y, this->identificador);

    if (this->caminoVacio()){

        this->primero = nuevoNodo;
        this->ultimo = nuevoNodo;
        this->xminimo = nuevoNodo->getDato();
        this->xmaximo = nuevoNodo->getDato();
        this->yminimo = nuevoNodo->getDato();
        this->ymaximo = nuevoNodo->getDato();

    }
    else{
            this-> iniciarCursor();
            this-> moverCursorAlUltimo();
            x = obtenerElementoEnCursor()->obtenerCoordX();
            y = obtenerElementoEnCursor()->obtenerCoordY();

            this->calcularCoordenadas(orientacion, x, y);

            nuevoNodo->getDato()->modificarCoordX(x);
            nuevoNodo->getDato()->modificarCoordY(y);

            this-> compararCoordenadas(nuevoNodo->getDato());

            this-> cursor->setSiguiente(nuevoNodo);
            nuevoNodo->setAnterior(cursor);
            this->ultimo = nuevoNodo;
    }

    this->longitud++;
}

bool Camino::caminoVacio(){
    return (primero == 0);
}

unsigned int Camino::obtenerAnchoTotal(){
    int mayor = this-> obtenerXMaximo();
    int menor = this-> obtenerXMinimo();
    int resultado = mayor-menor;
    if (resultado < 0){
        resultado = resultado*(-1);
    }
    if (resultado == 0){
        resultado++;
    }
    if (mayor <= 0 || menor <= 0){
        resultado++;
    }
    return resultado;
}

unsigned int Camino::obtenerLargoTotal(){

    int mayor = obtenerYMaximo();
    int menor = obtenerYMinimo();
    int resultado = mayor-menor;
    if (resultado < 0){
        resultado = resultado*(-1);
    }
    if (resultado == 0){
        resultado++;
    }
    if (mayor <= 0 || menor <= 0){
        resultado++;
    }
    return resultado;
}

int Camino::obtenerXMaximo(){
    return this->xmaximo->obtenerCoordX();
}

int Camino::obtenerXMinimo(){
    return this->xminimo->obtenerCoordX();
}

int Camino::obtenerYMaximo(){
    return this->ymaximo->obtenerCoordY();
}

int Camino::obtenerYMinimo(){
    return this->yminimo->obtenerCoordY();
}

int* Camino::obtenerColor(){
    return this->color;
}

int Camino::obtenerTamanio(){
    return longitud;
}

void Camino::iniciarCursor(){

    this->cursor = 0;

}

void Camino::tirarElemento(string nombre){

    this-> iniciarCursor();
    this-> moverCursorAlUltimo();

    this-> obtenerElementoEnCursor()->agregarElemento(nombre);

}

bool Camino::levantarElemento(){

    this-> iniciarCursor();
    this-> moverCursorAlUltimo();
    return obtenerElementoEnCursor()->obtenerElemento();

}

void Camino::setIdentificador(){
    ostringstream convertir;
    for(int i = 0; i < 3; i++){
        convertir << this->color[i];
        this->identificador += convertir.str();
    }
}

bool Camino::moverCursorAlSiguiente(){
    if (this->cursor == 0){
        this->cursor = this->primero;
    }
    else{
        this->cursor = this->cursor->getSiguiente();
    }
    return (this->cursor != 0);
}

void Camino::eliminarPrimero(){
    NodoCamino* nodoAEliminar = this->primero;
    this->primero = this->primero->getSiguiente();
    delete nodoAEliminar;
    this->longitud--;
}

Posicion* Camino::obtenerElementoEnCursor(){
    return this->cursor->getDato();
}

void Camino::moverCursorAlUltimo(){
    this->cursor = this->ultimo;
}

void Camino::marcarBifurcacion(char orientacion, string nombre){
    this-> iniciarCursor();
    this-> moverCursorAlUltimo();
    this-> obtenerElementoEnCursor()-> agregarBifurcacion(nombre, orientacion);
}

void Camino::marcarUnion(char orientacion, string nombre){
    this-> iniciarCursor();
    this-> moverCursorAlUltimo();
    this-> obtenerElementoEnCursor()-> agregarUnion(nombre);
}

