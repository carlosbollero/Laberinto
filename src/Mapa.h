

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
        //AGREGADO
        int xMaximo;


        void calcularDimension();
        void escribirElementosEnMapa(Lista<Posicion*>* posicionesConElementos);
        int calcularPixelDeInicio(int coordenada);
        void dibujarCelda(int coordenadaX, int coordenadaY, RGBApixel &colorCamino);
        
        void dibujarBifurcacion(int coordenadaX, int coordenadaY);//----------AGRAGADO

        void unirCaminos(Posicion* bifurcacion, Camino* caminoAUnir);//----------FALTA
        void escribirCamino(Camino* caminoAEscribir);
        void buscarCoordenadasLimites ();
        void modificarCoordenadas (int minX,int minY);

        //------------------------------------AGREGADOS
        void buscarCaminosNoBifurcados();
        void moverCaminoEnX(Camino* camino);
        //------------------------------------FIN

    public:
        Mapa(Lista<Camino*>* caminosRecorridos, Lista<Lista<Posicion*>*>* listaBifurcaciones, Lista<Posicion*>* elementos);
        ~Mapa();
        void escribirMapa();

};


#endif // MAPA_H
