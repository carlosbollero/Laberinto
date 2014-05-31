#include "Mapa.h"

Mapa::Mapa(Lista<Camino*>* caminosRecorridos, Lista<Lista<Posicion*>*>* listaBifurcaciones,  Lista<Posicion*>* elementos){
	this-> minX = 0;
	this-> minY = 0;
	this-> xMaximo = 0;
    this->ancho = 0;
    this->alto = 0;
    this->grafico = new BMP;
    this->caminos = caminosRecorridos;
    this->bifurcaciones = listaBifurcaciones;
    this->posicionesConElementos = elementos;
}

Mapa::~Mapa(){
    delete this->grafico;
    this->ancho = 0;
    this->alto = 0;
}


void Mapa::calcularDimension(){
    this->caminos->iniciarCursor();
    Camino* camino = this->caminos->getCursor();
    int xmax = camino->obtenerXMaximo();
    int xmin = camino->obtenerXMinimo();
    int ymax = camino->obtenerYMaximo();
    int ymin = camino->obtenerYMinimo();
    do{
        camino = this->caminos->getCursor();        
        if (xmax < camino->obtenerXMaximo()){
            xmax = camino->obtenerXMaximo();
        }        
        if (xmin > camino->obtenerXMinimo()){
            xmin = camino->obtenerXMinimo();
        }        
        if (ymax < camino->obtenerYMaximo()){
            ymax = camino->obtenerYMaximo();
        }        
        if (ymin > camino->obtenerYMinimo()){
            ymin = camino->obtenerYMinimo();
        }
    }while (this->caminos->avanzarCursor());
    
    this-> xMaximo = xmax;

    this->ancho = xmax - xmin;
    this->alto = ymax - ymin;
}

int Mapa::calcularPixelDeInicio(int coordenada){
    int posicionPixel = coordenada;
    switch(coordenada){
        case 0:  posicionPixel = 0;
        break;
        default:    posicionPixel = (posicionPixel*11);
    }
    return posicionPixel;
}

void Mapa::dibujarCelda(int coordenadaX, int coordenadaY, RGBApixel &colorCamino){
    for(int i = calcularPixelDeInicio(coordenadaX); i <= calcularPixelDeInicio(coordenadaX)+9; i++){
        for(int j = calcularPixelDeInicio(coordenadaY); j <= calcularPixelDeInicio(coordenadaY)+9; j++){
            this->grafico->SetPixel(i, j, colorCamino);
        }
    }
}

void Mapa::dibujarBifurcacion(int coordenadaX, int coordenadaY){
    RGBApixel colorBifurcacion;
    colorBifurcacion.Red = 033;
    colorBifurcacion.Green = 033;
    colorBifurcacion.Blue = 033;

    for(int i = calcularPixelDeInicio(coordenadaX); i <= calcularPixelDeInicio(coordenadaX)+10; i++){
        for(int j = calcularPixelDeInicio(coordenadaY); j <= calcularPixelDeInicio(coordenadaY)+10; j++){
            this->grafico->SetPixel(i, j, colorBifurcacion);
        }
    }
}

void Mapa::escribirCamino(Camino* caminoAEscribir){
    int* colores = caminoAEscribir->obtenerColor();

    RGBApixel colorCamino;
    colorCamino.Red = colores[0];
    colorCamino.Green = colores[1];
    colorCamino.Blue = colores[2];

    caminoAEscribir->iniciarCursor();
    Posicion* posicionActual;
    
    while(caminoAEscribir->moverCursorAlSiguiente()){
        posicionActual = caminoAEscribir->obtenerElementoEnCursor();
        dibujarCelda(posicionActual->obtenerCoordX(), posicionActual->obtenerCoordY(), colorCamino);
    }
}

void Mapa::escribirElementosEnMapa(Lista<Posicion*>* posicionesConElementos){
    int tamanioFuente = 8;

    RGBApixel colorFuente;
    colorFuente.Red = 0;
    colorFuente.Green = 0;
    colorFuente.Blue = 0;

    posicionesConElementos->iniciarCursor();
    Posicion* posicionActual;
    do{
        posicionActual = posicionesConElementos->getCursor();
        int coordenadaX = posicionActual->obtenerCoordX();
        int coordenadaY = posicionActual->obtenerCoordY();

        string nombreElemento = "x ";
        nombreElemento += posicionActual->obtenerNombreElemento();

        const char* nombreAEscribir = nombreElemento.c_str();

        PrintString(*(this->grafico), (char*)nombreAEscribir, calcularPixelDeInicio(coordenadaX), calcularPixelDeInicio(coordenadaY), tamanioFuente, colorFuente);

    }while(posicionesConElementos->avanzarCursor());
}

void Mapa::escribirMapa(){
    this->calcularDimension();
    this->buscarCaminosNoBifurcados();
    this->buscarCoordenadasLimites();
    this->grafico->SetSize((this->ancho)*14, (this->alto)*14);
    caminos->iniciarCursor();
    Camino* caminoActual;
    do {
        caminoActual = caminos->getCursor();
        escribirCamino(caminoActual);
    }while(caminos->avanzarCursor());
    escribirElementosEnMapa(this->posicionesConElementos);
    this->grafico->WriteToFile("Mapa.bmp");
}

void Mapa::buscarCoordenadasLimites () {
    this->caminos->iniciarCursor();
    int xMin;
    int yMin;
    Camino* caminoActual = this->caminos->getCursor();
    xMin = caminoActual->obtenerXMinimo ();
    yMin = caminoActual->obtenerYMinimo ();
    do{
        caminoActual = this->caminos->getCursor();
        if (caminoActual->obtenerXMinimo () < xMin) {
            xMin = caminoActual->obtenerXMinimo ();
        }

        if (caminoActual->obtenerYMinimo () < yMin) {
            yMin = caminoActual->obtenerYMinimo ();
        }

    }while (this->caminos->avanzarCursor());

    this->minX = xMin;
    this->minY = yMin;
    modificarCoordenadas(this->minX,this->minY);
}

void Mapa::modificarCoordenadas (int minX,int minY){
    if((minX<0) || (minY<0)){
        minX=minX * (-1);
        minY=minY * (-1);
        
    }
    Camino* camino;
    Posicion* posicionActual;  
    this-> caminos-> iniciarCursor();
    do{
        camino = this->caminos->getCursor();
        camino->iniciarCursor();
        while(camino->moverCursorAlSiguiente()){
            posicionActual = camino->obtenerElementoEnCursor();
            posicionActual->modificarCoordX(posicionActual->obtenerCoordX() + minX);
            posicionActual->modificarCoordY(posicionActual->obtenerCoordY() + minY);
        }

    }while(caminos->avanzarCursor());
    this-> caminos-> iniciarCursor();
    do{
        camino = this-> caminos-> getCursor();
        camino-> iniciarCursor();
        while (camino-> moverCursorAlSiguiente()){
            posicionActual = camino-> obtenerElementoEnCursor();   
            posicionActual->modificarCoordY(this-> alto - posicionActual->obtenerCoordY());
        }
    }while (this-> caminos-> avanzarCursor());
}

void Mapa::buscarCaminosNoBifurcados(){
    this-> caminos-> iniciarCursor();
    Camino* caminoActual;
    do{
        caminoActual = this-> caminos-> getCursor();
        bool hayBifurcacionOUnion = false;
        caminoActual-> iniciarCursor();
        while (caminoActual-> moverCursorAlSiguiente() && !hayBifurcacionOUnion){
            if (caminoActual-> obtenerElementoEnCursor()-> tieneBifurcacion() || caminoActual-> obtenerElementoEnCursor()-> tieneUnion() ){
                hayBifurcacionOUnion = true;
            }
        }
        if (!hayBifurcacionOUnion){
            this-> moverCaminoEnX(caminoActual);
        }
    }while (this-> caminos-> avanzarCursor());
    this->calcularDimension();
}

void Mapa::moverCaminoEnX(Camino* camino){
    camino-> iniciarCursor();
    camino-> moverCursorAlSiguiente();
    int diferencia = xMaximo - camino-> obtenerXMinimo();
    camino-> iniciarCursor();
    while (camino-> moverCursorAlSiguiente()){
        camino-> obtenerElementoEnCursor()-> modificarCoordX(camino-> obtenerElementoEnCursor()->obtenerCoordX() + (diferencia + 2));
    }

}