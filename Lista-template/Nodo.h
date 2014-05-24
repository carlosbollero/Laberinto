#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo{
    private:
        T dato;
        Nodo<T>* siguiente;

    public:
        Nodo(T dato);
        ~Nodo()
        T obtenerDato();
        Nodo<T>* obtenerSiguiente();
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
Nodo::~Nodo(){

    this->siguiente = 0;

}

#endif // NODO_H
