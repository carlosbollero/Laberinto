#ifndef LISTA_H_
#define LISTA_H_

#include "NodoTemplate.h"



template <class T>
class Lista{
private:
	Nodo<T>* primero;
	Nodo<T>* ultimo;
	Nodo<T>* cursor;

	unsigned int tamanio;

public:
	Lista(){
		this-> primero = 0;
		this-> ultimo = 0;
		this-> cursor = 0;
		this-> tamanio = 0;
	};
	/* Pre:
	 * Post:  */
	~Lista(){
		while (!this-> estaVacia()){
			this-> eliminarPrimerElemento();
		}
		this-> primero = 0;
		this-> ultimo = 0;
		this-> cursor = 0;
		this-> tamanio = 0;
	};
	/* Pre:
	 * Post:  */
	void agregarElemento(T elemento){
		Nodo<T>* nuevoElemento = new Nodo<T>(elemento);
		if (estaVacia()){
			this-> primero = nuevoElemento;
			this-> ultimo = nuevoElemento;
			
		}else{
			this-> ultimo-> asignarSiguiente(nuevoElemento);
			this-> ultimo = nuevoElemento;
			
		}
		this-> tamanio++;
	};
	/* Pre:
	 * Post:  */
	void eliminarPrimerElemento(){
		Nodo<T>* nodoPorBorrar = this-> primero;
		this-> primero = this-> primero-> obtenerSiguiente();
		this-> tamanio--;
		delete nodoPorBorrar;
	};

	void eliminarElemento(T elemento){
		this-> iniciarCursor();
		if (elemento == this-> getCursor()){
			this-> eliminarPrimerElemento();
		}else{
			Nodo<T>* nodoAnterior = this-> primero;
			while (this-> avanzarCursor()){
				if (elemento == this-> getCursor()){
					Nodo<T>* nodoPorEliminar = this-> cursor;
					nodoAnterior-> asignarSiguiente(this-> cursor-> obtenerSiguiente());
					if (!this-> avanzarCursor()){
						this-> iniciarCursor();
					}
					delete nodoPorEliminar;

				}

				nodoAnterior = this-> cursor;
			}
		}
		this-> tamanio--;
	};

	T getDato(){
		return this-> cursor-> getdato();
	};
	/* Pre:
	 * Post:  */
	bool estaVacia(){
		return (this-> tamanio == 0);
	};
	/* Pre:
	 * Post:  */
	void iniciarCursor(){
		this-> cursor = this-> primero;
	};
	/* Pre:
	 * Post:  */
	T getCursor(){
		return this-> cursor-> obtenerDato();
	};
	/* Pre:
	 * Post:  */
	bool avanzarCursor(){
		if (this-> cursor != 0){
			this-> cursor = this-> cursor-> obtenerSiguiente();
		}
		return (this-> cursor != 0);
	};

};



#endif /* LISTA_H_ */
