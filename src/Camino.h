#ifndef CAMINO_H
#define CAMINO_H

#include "tipos.h"
#include "nodo.h"
#include "Posicion.h"
#include <string>
#include <sstream>
#include <iomanip>

class Camino{

private:
    NodoCamino* primero;
    NodoCamino* ultimo;
    NodoCamino* cursor;
    int* color;
    string identificador;
    Posicion* xminimo;
    Posicion* xmaximo;
    Posicion* yminimo;
    Posicion* ymaximo;
    int longitud;

    void eliminarPrimero();
    void compararCoordenadas(Posicion* posicionDeReferencia);

public:
    /* Pre: Los parámetros que definen el color deben ser válidos.
     * Post: Setea las variables de camino en 0. */
    Camino(int R, int G, int B); 
    /* Post: Libera la memoria pedida para cada posición del camino y para
     * el color almacenado. */
    ~Camino(); 
    /* Post: Agrega un nodo posicion hacia orientacion deseada. */
    void agregarPosicion(char orientacion); 
    /* Post: Evalúa si el camino esta vacio. */
    bool caminoVacio(); 

    unsigned int obtenerAnchoTotal();

    unsigned int obtenerLargoTotal();

    int obtenerXMinimo();

    int obtenerXMaximo();

    int obtenerYMinimo();

    int obtenerYMaximo();

    int* obtenerColor();

    int obtenerTamanio();

    void iniciarCursor();

    Posicion* obtenerElementoEnCursor();

    bool moverCursorAlSiguiente();

    void moverCursorAlUltimo();

    void tirarElemento(string nombre);

    bool levantarElemento();

    void setIdentificador();

    void marcarBifurcacion(char orientacion, string nombre);

    void marcarUnion(char orientacion, string nombre);

    void calcularCoordenadas(char orientacion, int &coordenadaX, int &coordenadaY);

};
#endif
