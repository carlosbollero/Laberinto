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
     * Post: La orientacion del personaje */
    void girar(char orientacion);
	/* Pre: 
	 * Post:  */
	void avanzar(unsigned int cantidad);
    /* Pre: 
     * Post:  */
    void unir();
	/* Pre: 
	 * Post:  */
    // void retroceder();
    /* Pre: 
     * Post:  */
    void levantarElemento(string elemento);
    /* Pre: 
     * Post:  */
    void tirarElemento();
    /* Pre: 
     * Post:  */
    //   Elemento* buscarElemento(string elemento);
    /* Pre: 
     * Post:  */
    Posicion* getPosicionActual();
    /* Pre: 
     * Post:  */
    // bool validarOrientacion();
    /* Pre: 
     * Post:  */
    void marcarBifurcacion();

};
