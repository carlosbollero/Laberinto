#ifndef LABERINTO_H_
#define LABERINTO_H_

#include "tipos.h"
#include "ListaTemplate.h"
#include "Personaje.h"
#include "Camino.h"
#include "Mapa.h"
#include "LectorArchivo.h"




class Laberinto {
private:
	Personaje* personaje;
	LectorArchivo* lector;
	Camino* caminoActual;
	Mochila* mochila;
	Mapa* mapa;

	// INFORME
	unsigned int unidadesRecorridas;
	unsigned int cantidadGiros;
	unsigned int cantidadBifurcaciones;

    Lista<Camino*>* caminos;
    Lista<Posicion*>* posicionesConBifurcacion;
    Lista<Lista<Posicion*>*>* bifurcaciones;
    Lista<Posicion*>* posicionesConElemento;

    // MÉTODOS PRIVADOS

	/* Pre: 
	 * Post: Imprime un mensaje de bienvenida en pantalla. */
	void mensajeBienvenida();
	/* Pre: 
	 * Post: En base a la coordenada de la union, revisa si coincide con alguna
	 * bifurcación en la lista de bifurcaciones. En caso afirmativo, toma la 
	 * coordenada de la bifurcación, pronostica qué coordenada le debería 
	 * corresponder a la unión y calcula la diferencia entre las coordenadas de
	 * la unión y la esperada. Con esa diferencia recorre todo el camino 
	 * sumandosela a cada posición hasta la unión; quedando así ambos caminos
	 * con el mismo sistema de coordenadas. */
	void reordenarCoordenadas();
	/* Pre: El parámetro recibido debe ser una opcíon válida.
	 * Post: Da inicio a un nuevo camino con el color determinado em el archivo
	 * de texto. Lo agrega a la lista de caminos. */
	void operacionPartida(string operacion);
	/* Pre: El parámetro recibido debe ser una opcíon válida.
	 * Post: Gira al personaje en la direcciión establecida */
	void operacionGirar(string operacion);
	/* Pre: El parámetro recibido debe ser una opcíon válida.
	 * Post: Hace avanzar al personaje, creando posiciones en cada paso. */
	void operacionAvanzar(string operacion);
	/* Pre: El parámetro recibido debe ser una opcíon válida.
	 * Post: Gira al personaje 180 grado y avanza en la nueva dirección. */
	void operacionRetroceder(string operacion);
	/* Pre: El parámetro recibido debe ser una opcíon válida.
	 * Post: Si el elemento estaba tirado, lo retira de la posición. Lo agrega
	 * a la mochila. */
	void operacionLevantar(string operacion);
	/* Pre: El parámetro recibido debe ser una opcíon válida.
	 * Post: Quita el elemento de la mochila y lo agrega a la posición en la 
	 * que se encuentra el personaje. */
	void operacionTirar(string operacion);
	/* Pre: El parámetro recibido debe ser una opcíon válida.
	 * Post: Deja una marca en la posicion, con el nombre y la dirección de la
	 * bifurcacion. Agrega la posición a la lista de bifurcaciones. */
	void operacionBifurcar(string operacion);
	/* Pre: El parámetro recibido debe ser una opcíon válida.
	 * Post: Deja una marca en la posición con el nombre de la unión y llama a
	 * la reestructuración de todo el camino. */
	void operacionUnir(string operacion);
	//void operacionLlegada();

public:
	/* Pre: 
	 * Post: Se crean los objetos lector, mochila, personaje, mapa y las listas.
	 * Se debe tener en cuenta que la ruta ingresada debe ser correcta para que
	 * lector reconozca al archivo de texto. Se inicializan las variable para
	 * el informe. */
	Laberinto();
	/* Pre: 
	 * Post: Se eliminan de memoria lo pedido en el constructor de la clase. */
	~Laberinto();
	/* Pre: Los objetos de la clase deben estar creados e inicializados.
	 * Post: Se realizan las operaciones indicadas en el archivo de texto 
	 * siendo leidas mediante lector. Las operaciones se realizan mientras
	 * queden operaciones por leer. */
	void operar();
	/* Pre: Se debe haber terminado de crear todos los caminos.
	 * Post: Se llama a los métodos de la clase Mapa para la impresion del mapa
	 * del laberinto ya creado. */
	void imprimirMapa();
	/* Pre: Se debe haber terminado de crear todos los caminos.
	 * Post: Imprime por pantalla los datos del laberinto */
	void generarInforme();
};


#endif /* LABERINTO_H_ */
