

#ifndef MAPA_H
#define MAPA_H

#include "EasyBMP/EasyBMP_Font.h"
#include "EasyBMP/EasyBMP.h"
#include "Camino.h"
#include "ListaTemplate.h"

class Mapa
{
    private:
        int ancho;
        int alto;
        BMP* grafico;
        Lista<Camino*>* caminos;
        Lista<Lista<Posicion*>*>* bifurcaciones;
        Lista<Posicion*>* posicionesConElementos;
        int minX;
        int minY;
        int xMaximo;

        /*  Pre: La lista de caminos no debe estar vac�a.
            Post: Calcula el ancho y el alto del mapa. */
        void calcularDimension();
        /*  Pre: La lista de elementos no debe estar vac�a.
            Post: Escribe sobre el mapa los nombres de los elementos tirados por el personaje. */
        void escribirElementosEnMapa(Lista<Posicion*>* posicionesConElementos);
        /*  Pre: Ninguna.
            Post: Calcula el pixel correspondiente en el BMP a la coordenada ingresada. */
        int calcularPixelDeInicio(int coordenada);
        /*  Pre: Ninguna.
            Post: Dibuja en el BMP una celda (posici�n) del camino de acuerdo a sus coordenadas. */
        void dibujarCelda(int coordenadaX, int coordenadaY, RGBApixel &colorCamino);
        /*  Pre: Ninguna.
            Post: Dibuja en el BMP una bifurcaci�n. */
        void dibujarBifurcacion(int coordenadaX, int coordenadaY);
        /*  Pre: Camino no debe estar vac�o (sin posiciones).
            Post: Dibuja en el BMP el camino especificado. */
        void escribirCamino(Camino* caminoAEscribir);
        /*  Pre: Ninguna.
            Post: Busca las coordenadas m�ximas y m�nimas absolutas. */
        void buscarCoordenadasLimites ();
        /*  Pre: Ninguna.
            Post: Modifica ("corre") las coordenadas de los caminos en base a los valores ingresados. */
        void modificarCoordenadas (int minX,int minY);
        /*  Pre: Ninguna.
            Post: Busca aquellos caminos que no tienen bifurcaciones ni uniones. */
        void buscarCaminosNoBifurcados();
        /*  Pre: Ninguna.
            Post: Modifica las coordenadas del camino en cuesti�n apart�ndolo de los caminos bifurcados. */
        void moverCaminoEnX(Camino* camino);
    public:
         /*  Pre: Las listas recibidas no deben estar vac�as.
            Post: Inicializa el mapa con la informaci�n recibida. */
        Mapa(Lista<Camino*>* caminosRecorridos, Lista<Lista<Posicion*>*>* listaBifurcaciones, Lista<Posicion*>* elementos);
         /*  Pre: Ninguna.
            Post: Libera los recursos (memoria) utilizados. */
        ~Mapa();
        /*  Pre: Ninguna.
            Post: Dibuja el BMP de acuerdo a la informaci�n ingresada. */
        void escribirMapa();
};


#endif // MAPA_H
