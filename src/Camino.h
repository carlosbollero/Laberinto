#ifndef CAMINO_H
#define CAMINO_H

#include "tipos.h"
#include "nodo.h"
#include "Posicion.h"
//#include <string>
#include <sstream>
#include <iomanip>

class Camino{
private:
    NodoCamino* primero;
    NodoCamino* ultimo;
    NodoCamino* cursor;
    int* color;
    Posicion* xminimo;
    Posicion* xmaximo;
    Posicion* yminimo;
    Posicion* ymaximo;
    int longitud;

    /*  Pre: Ninguna.
        Post: Elimina el primer nodo del camino. */
    void eliminarPrimero();
    /*  Pre: Posici�n de referencia debe ser no nula.
        Post: Compara las coordenadas de la posici�n contra los m�ximos y m�nimos del camino.
        En caso de resultar mayor o menor, actualiza las posiciones existentes con la nueva. */
    void compararCoordenadas(Posicion* posicionDeReferencia);
public:
    /* Pre: Los par�metros que definen el color deben ser v�lidos.
     * Post: Setea las variables de camino en 0 y carga el color. */
    Camino(int R, int G, int B);
    /* Pre: Ninguna.
       Post: Libera la memoria pedida para cada posici�n del camino y para
     * el color almacenado. */
    ~Camino();
    /* Pre: La orientaci�n debe ser v�lida.
     * Post: Agrega un nodo posicion hacia orientacion deseada. */
    void agregarPosicion(char orientacion);
    /* Pre: Ninguna.
     * Post: Eval�a si el camino esta vacio. */
    bool caminoVacio();
    /*  Pre: Ninguna.
        Post: Devuelve el ancho total en posiciones del camino actual. */
    unsigned int obtenerAnchoTotal();
    /*  Pre: Ninguna.
        Post: Devuelve el ancho total en posiciones del camino actual. */
    unsigned int obtenerLargoTotal();
    /*  Pre: Ninguna.
        Post: Devuelve la coordenada X m�nima del camino actual. */
    int obtenerXMinimo();
    /*  Pre: Ninguna.
        Post: Devuelve la coordenada X m�xima del camino actual. */
    int obtenerXMaximo();
    /*  Pre: Ninguna.
        Post: Devuelve la coordenada Y m�nima del camino actual. */
    int obtenerYMinimo();
    /*  Pre: Ninguna.
        Post: Devuelve la coordenada Y m�xima del camino actual. */
    int obtenerYMaximo();
    /*  Pre: Ninguna.
        Post: Devuelve los colores RGB del camino. */
    int* obtenerColor();
    /*  Pre: Ninguna.
        Post: Retorna la cantidad total de posiciones del camino actual. */
    int obtenerTamanio();
    /*  Pre: Ninguna.
        Post: Inicia el cursor en una direcci�n de memoria nula. */
    void iniciarCursor();
    /*  Pre: El cursor debe estar apuntando a una direcci�n de memoria v�lida.
        Post: Devuelve la posici�n almacenada en el nodo correspondiente. */
    Posicion* obtenerElementoEnCursor();
    /*  Pre: Cursor iniciado.
        Post: Mueve el cursor al nodo siguiente. */
    bool moverCursorAlSiguiente();
    /*  Pre: Ninguna.
        Post: Mueve el cursor al �ltimo nodo del camino. */
    void moverCursorAlUltimo();
    /*  Pre: El elemento debe haberse levantado primero.
        Post: Tira el elemento en la posici�n actual. */
    void tirarElemento(string nombre);
    /*  Pre: Ninguna.
        Post: Levanta un elemento. Devuelve True si hab�a un elemento en la posici�n.
        Caso contrario devuele False. */
    bool levantarElemento();
    /*  Pre: Ninguna.
        Post: Marca una bifurcaci�n en la posici�n actual con su nombre y orientaci�n. */
    void marcarBifurcacion(char orientacion, string nombre);
    /*  Pre: Ninguna.
        Post: Marca una uni�n en la posici�n actual con su nombre. */
    void marcarUnion(string nombre);
    /*  Pre: Orientaci�n v�lida.
        Post: Calcula las nuevas coordenadas en base a la orientaci�n y a las coordenadas de la posici�n anterior. */
    void calcularCoordenadas(char orientacion, int &coordenadaX, int &coordenadaY);
};
#endif
