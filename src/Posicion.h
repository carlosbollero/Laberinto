#ifndef POSICION_H
#define POSICION_H

#include <iostream>
#include <string>
#include "elemento.h"

using namespace std;

class Posicion{
public:
    /* Pre: Las coordenadas x e y deben ser 0 para la primer posicion de un 
     * camino o correlativas a la posición anterior en caso de una posición
     * diferente.
     * Post: Queda creada la posición con las coordenadas indicadas. */
    Posicion(int coordX,int coordY);
    /*Pre: No tiene
      Post: Devuelve las coordenadas de la posicion */
    int obtenerCoordX();
    int obtenerCoordY();
    /* Pre:
     * Post: Modifica la coordena a de la posicion*/
    void modificarCoordX(int coordX);
    void modificarCoordY(int coordY);
    /* Pre: No tiene
     * Post: Devuelve el nombre de la bifurcacion en la posicion actual, o una cadena vacia si no tiene bifurcacion*/
    string obtenerBifurcacion();
    /* Pre: Recibe el nombre de una bifurcacion valida, y la orientacion de la bifurcacion
     * Post: Agrega la bifurcacion y su orientacion a la posicion actual*/
    void agregarBifurcacion(string bifurcacion,char orientacion);
    /* Pre: No tiene
     * Post: Devuelve el nombre de la union en la posicion actual, o una cadena vacia si no tiene union*/
    string obtenerUnion();
    /* Pre: Recibe el nombre de la union
     * Post: Agrega la union a la posicion actual*/
    void agregarUnion(string unionPosicion);
    /* Pre: No puede haber un elemento ya tirado, si lo hubiera, lo pisa
     * Post: Deja el elemento en la posicion*/
    void agregarElemento(string nombreElemento);
    /* Pre: No tiene
     * Post: Devuelve true si habia un elemento o false si no, el elemento deja de estar en la posicion*/
    bool obtenerElemento();
    /* Pre: No tiene
     * Post: Devuelve el identificador del camino al que pertenece la posicion*/
    string obtenerIdentificador();
    /* Pre:
     * Post: Devuelve el nombre del elemento tirado en la posición actual. */
    string obtenerNombreElemento();
    /* Pre: Se debe estar apuntado en una posicón válida.
     * Post: Devuelve hacia donde está orientada la bifurcación marcada en la
     * posición actual */
    char obtenerOrientacionBifurcacion();
    /* Pre: Se debe estar apuntado en una posicón válida.
     * Post: Devuelve si en posición actual tiene o no una bifurcación. */
    bool tieneBifurcacion();
    /* Pre: Se debe estar apuntado en una posicón válida.
     * Post: Devuelve si en posición actual tiene o no una unión. */
    bool tieneUnion();
    /* Pre:
     * Post: Elimina de memoria los elementos que hayan sido tirados en la 
     * posición. */
    ~Posicion();

private:
    int coordX;
    int coordY;
    string bifurcacion;
    string unionPosicion;
    string identificador;
    char orientacionBifurcacion;
    Elemento* elemento;
};

#endif
