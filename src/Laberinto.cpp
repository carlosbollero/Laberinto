#include "Laberinto.h"

Laberinto::Laberinto(){
	this-> mensajeBienvenida();
	cout << endl;
	string ruta;
	cout << "Ingrese la ruta del archivo de texto" << endl;
	cin >> ruta;
	this-> lector = new LectorArchivo(ruta);
	this-> mochila = new Mochila;
	this-> personaje = new Personaje(this->mochila);

	this-> posicionesConBifurcacion = 0;
	this-> caminoActual = 0;

	this-> caminos = new Lista<Camino*>;
	this-> bifurcaciones = new Lista<Lista<Posicion*>*>;
	this-> posicionesConElemento = new Lista<Posicion*>;

	this-> mapa = new Mapa(caminos, bifurcaciones, posicionesConElemento);

	this-> unidadesRecorridas = 0;
	this-> cantidadGiros = 0;
	this-> cantidadBifurcaciones = 0;
}

Laberinto::~Laberinto(){
	delete this-> personaje;
	delete this-> mochila;
	delete this-> mapa;
	delete this-> lector;
	delete this-> caminoActual;
	delete this-> caminos;
	delete this-> bifurcaciones;
	delete this-> posicionesConElemento;
}

void Laberinto::operar(){
    string operacion;
	while (!this-> lector-> finArchivo()){
		operacion = this-> lector-> getPalabra();
		if (operacion == "PP"){
			this-> operacionPartida(operacion);

		}else if (operacion[0] == 'G'){
			this-> operacionGirar(operacion);

		}else if (operacion == "A"){
			this-> operacionAvanzar(operacion);

		}else if (operacion == "R"){
			this-> operacionRetroceder(operacion);

		}else if (operacion == "L"){
			this-> operacionLevantar(operacion);

		}else if (operacion == "T"){
			this-> operacionTirar(operacion);

		}else if (operacion[0] == 'B'){
			this-> operacionBifurcar(operacion);

		}else if (operacion == "U"){
			this-> operacionUnir(operacion);
			this-> personaje-> avanzar(1);
			this-> unidadesRecorridas += 1;

		//}else if (operacion == "PLL"){
			//cout << "fin camino";
		}
	}

}

void Laberinto::operacionPartida(string operacion){
	unsigned int color[3];
	for (unsigned int i = 0; i < 3; i++){
		color[i] = atoi(this-> lector-> getPalabra().c_str());
	}

	this-> caminoActual = new Camino(color[0],color[1],color[2]);
	this-> personaje-> iniciarNuevoCamino(this-> caminoActual);
	this-> caminos-> agregarElemento(this-> caminoActual);
	this->posicionesConBifurcacion = new Lista<Posicion*>;
}

void Laberinto::operacionGirar(string operacion){
	this-> personaje-> girar(operacion[1]);
	this-> cantidadGiros ++;
}

void Laberinto::operacionAvanzar(string operacion){
	unsigned int cantidad = atoi(this-> lector-> getPalabra().c_str());
	this-> personaje-> avanzar(cantidad);
	this-> unidadesRecorridas += cantidad;
}

void Laberinto::operacionRetroceder(string operacion){
	switch (this-> personaje-> getOrientacion()){
		case 'N':
			this-> personaje-> girar('S');
			break;
		case 'S':
			this-> personaje-> girar('N');
			break;
		case 'E':
			this-> personaje-> girar('O');
			break;
		case 'O':
			this-> personaje-> girar('E');
			break;
	}
	this-> cantidadGiros++;
	unsigned int cantidad = atoi(this-> lector-> getPalabra().c_str());

	this->personaje-> avanzar(cantidad);
	this-> unidadesRecorridas += cantidad;
}

void Laberinto::operacionLevantar(string operacion){
	if (this-> caminoActual-> levantarElemento()){
		this-> posicionesConElemento-> eliminarElemento(this-> caminoActual-> obtenerElementoEnCursor());
	}
	this-> personaje-> levantarElemento(this-> lector-> getPalabra());
}

void Laberinto::operacionTirar(string operacion){
	string elemento = this-> lector-> getPalabra();
	this-> caminoActual-> tirarElemento(elemento);
	this-> posicionesConElemento-> agregarElemento(this-> caminoActual-> obtenerElementoEnCursor());
	this-> personaje-> tirarElemento(elemento);
}

void Laberinto::operacionBifurcar(string operacion){
	this-> caminoActual-> marcarBifurcacion(operacion[1], this-> lector-> getPalabra());
	this-> caminoActual-> moverCursorAlUltimo();
	this-> posicionesConBifurcacion-> agregarElemento(this-> caminoActual-> obtenerElementoEnCursor());
	this-> bifurcaciones->agregarElemento(this-> posicionesConBifurcacion);// agregado

	this-> cantidadBifurcaciones ++;
}

void Laberinto::operacionUnir(string operacion){
	this-> caminoActual-> marcarUnion(this-> lector-> getPalabra());
	this-> reordenarCoordenadas();
}

void Laberinto::reordenarCoordenadas(){
	string nombreBuscado = this-> caminoActual-> obtenerElementoEnCursor()-> obtenerUnion();
	int coordenadaX = this-> caminoActual-> obtenerElementoEnCursor()-> obtenerCoordX();
	int coordenadaY = this-> caminoActual-> obtenerElementoEnCursor()-> obtenerCoordY();
	this-> bifurcaciones-> iniciarCursor();

	bool encontrado = false;
	do{
		this-> bifurcaciones-> getCursor()->iniciarCursor();
		do{
			if (this-> bifurcaciones-> getCursor()-> getCursor()-> obtenerBifurcacion() == nombreBuscado){
				encontrado = (this-> bifurcaciones-> getCursor()-> getCursor()-> obtenerBifurcacion() == nombreBuscado);
				int coordenadaXEsperada, coordenadaYEsperada;
				switch (this-> bifurcaciones-> getCursor()-> getCursor()->obtenerOrientacionBifurcacion()){
					case 'N':
						coordenadaYEsperada = this-> bifurcaciones->getCursor()->getCursor()->obtenerCoordY() + 1;
						coordenadaXEsperada = this-> bifurcaciones->getCursor()->getCursor()->obtenerCoordX();
						break;
					case 'S':
						coordenadaYEsperada = this-> bifurcaciones->getCursor()->getCursor()->obtenerCoordY() - 1;
						coordenadaXEsperada = this-> bifurcaciones->getCursor()->getCursor()->obtenerCoordX();
						break;
					case 'E':
						coordenadaXEsperada = this-> bifurcaciones->getCursor()->getCursor()->obtenerCoordX() + 1;
						coordenadaYEsperada = this-> bifurcaciones->getCursor()->getCursor()->obtenerCoordY();
						break;
					case 'O':
						coordenadaXEsperada = this-> bifurcaciones->getCursor()->getCursor()->obtenerCoordX() - 1;
						coordenadaYEsperada = this-> bifurcaciones->getCursor()->getCursor()->obtenerCoordY();
						break;
				}
				int diferenciaX = (coordenadaXEsperada - coordenadaX);
				int diferenciaY = (coordenadaYEsperada - coordenadaY);						
				this-> caminoActual-> iniciarCursor();
				while (this-> caminoActual-> moverCursorAlSiguiente()){
					this-> caminoActual-> obtenerElementoEnCursor()-> modificarCoordX((this-> caminoActual->obtenerElementoEnCursor()->obtenerCoordX() + diferenciaX));
					this-> caminoActual-> obtenerElementoEnCursor()-> modificarCoordY((this-> caminoActual->obtenerElementoEnCursor()->obtenerCoordY() + diferenciaY));		
				}
			}
		}while(this-> bifurcaciones->getCursor()->avanzarCursor() && !encontrado);
	}while (this->bifurcaciones-> avanzarCursor() && !encontrado);

	this-> caminoActual-> moverCursorAlUltimo();
}

void Laberinto::imprimirMapa(){
	this-> mapa-> escribirMapa();
}

void Laberinto::generarInforme(){
	cout << endl;
	cout << "     =================== INFORME DEL LABERINTO ===================" << endl;
	cout << endl;
	//-------------INFORME DE PERSONAJE-------------
	cout << "Personaje:" << endl;
	cout << "    ";
	cout << "Unidades recorridas  >>>  " << this-> unidadesRecorridas << endl;
	cout << "    ";
	cout << "Giros realizados  >>>  " << this-> cantidadGiros << endl;
	cout << "    ";
	cout << "Bifurcaciones marcadas  >>>  " << cantidadBifurcaciones << endl;
	cout << endl;

	//--------------INFORME DE MOCHILA--------------
	cout << "Mochila:" << endl;
	this-> mochila-> iniciarCursor();
	while (this-> mochila->moverCursorAlSiguiente()){
		cout << "    ";
		cout << this-> mochila-> obtenerElementoEnCursor()-> getNombre() << "   ";
		cout << this-> mochila-> obtenerElementoEnCursor()-> getCantidad() << endl;
	}
	cout << endl;
}

void Laberinto::mensajeBienvenida(){
	for (unsigned int i = 1; i < 24; i++){
		cout << endl;
	}
	cout << "     ####################################################################" << endl;
	cout << "     #                                                                  #" << endl;
	cout << "     #               ALGORITMOS Y PROGRAMACION II - Calvo               #" << endl;
	cout << "     #                                                                  #" << endl;
	cout << "     ####################################################################" << endl;
	for (unsigned int i = 1; i < 5; i++){
		cout << endl;
	}
	cout << "TP: Laberinto" << endl;
	cout << endl;
	cout << "ALUMNOS:" << endl;
	cout << "    Angel, Ignacio" << endl << "    Botalla, Tomas" << endl;
	cout << "    Bollero, Carlos" << endl;
	cout << "    Mena, Mohamed David" << endl << "    Olivera, Rodrigo" << endl;
	for (unsigned int i = 1; i < 4; i++){
		cout << endl;
	}
	cout << "     ************************* (Presione ENTER) *************************" << endl;
	cin.get();
	for (unsigned int i = 1; i < 24; i++){
		cout << endl;
	}
	
}
