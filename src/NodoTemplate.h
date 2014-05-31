#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo{
private:
    T dato;
    Nodo<T>* siguiente;

public:
    /* Pre:
     * Post: Se crea un nodo con definiendo dato. */
    Nodo(T dato);
    /* Pre:
     * Post:  */        
    ~Nodo();
    /* Pre:
     * Post: Devuelve lo almacenado en dato. */
    T obtenerDato();
    /* Pre:
     * Post: Devuelve el siguiente nodo apuntado, o NULL. */
    Nodo<T>* obtenerSiguiente();
    /* Pre: nodoSiguiente debe haber sido creado previamente.
     * Post: Define el valor de siguiente asignandole el nodo recibido. */
    void asignarSiguiente(Nodo<T>* nodoSiguiente);

};

template <class T>
Nodo<T>::Nodo(T dato){

    this->dato = dato;
    this->siguiente = 0;

}

template <class T>
T Nodo<T>::obtenerDato(){

    return this->dato;

}

template <class T>
Nodo<T>* Nodo<T>::obtenerSiguiente(){

    return this->siguiente;

}

template <class T>
void Nodo<T>::asignarSiguiente(Nodo<T>* nodoSiguiente){

    this->siguiente = nodoSiguiente;

}

template <class T>
Nodo<T>::~Nodo(){

    this-> siguiente = 0;

}

#endif // NODO_H
