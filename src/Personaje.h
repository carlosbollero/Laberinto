/******************************************************************************
 *                                                                            *
 *                        Definición clase Personaje                          *
 *                                                                            *
 ******************************************************************************/

#include "tipos.h"
#include "Posicion.h"
#include "Mochila.h"
#include "Camino.h"

class Personaje{
private:
	Mochila* mochila;
    char orientacion;  //Indica hacia donde esta mirando (N,S,E,O)
    Posicion* posicionActual;
    Camino* camino;

public:
    /* Pre: 
     * Post:  */
	Personaje();
	/* Pre: 
	 * Post:  */
	~Personaje();
    /* Pre: 
     * Post: La orientacion del personaje queda modificada a la nueva orientación */
    void girar(char orientacion);
	/* Pre: 
	 * Post: Se crea una posicion nueva y se actualiza posicionActual a la nueva
     * posición, tantas veces como cantidad lo indique. */
	void avanzar(unsigned int cantidad);
    /* Pre: Hace la unión de dos bifurcaciones dentro del mismo camino. 
     * La posicionAUnir debe ser una posición por la que ya se haya pasado y 
     * debe estar marcada como tal.
     * Post: Se avanza a la posición unida. */
    void unir(Posicion* posicionAUnir);
    /* Pre: 
     * Post: Queda creado un nuevo elemento con el nombre del argumento y se 
     * agrega a la mochila. */
    void levantarElemento(string elemento);
    /* Pre: La mochila debe contener al elemento.
     * Post: Se elimina el elemento de la mochila y se lo agrega a la posicion
     * actual. */
    void tirarElemento();
    /* Pre: 
     * Post:  */
    //   Elemento* buscarElemento(string elemento);
    /* Pre: 
     * Post: Devuelve un puntero a donde se encuentra el personaje. */
    Posicion* getPosicionActual();
    /* Pre: 
     * Post: Marca en la posicion actual, una bifurcacion y su sentido. */
    void marcarBifurcacion();

};
