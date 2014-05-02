#include <iostream>
#include "Mochila.h"

using namespace std;

void verMochila(Mochila* nuevaMochila){

    cout << "Los elementos de la mochila son: " << nuevaMochila->obtenerCantidad() <<  endl;
    cout << "Nombre     |       Cantidad" << endl;

    int i = 1;

    while (i <= nuevaMochila->obtenerCantidad()){

        cout << nuevaMochila->obtenerElemento(i)->getNombre() << "      " << nuevaMochila->obtenerElemento(i)->getCantidad() << endl;

        i++;
    }


}

int main(){

    string nombre, salida;
    //char salida;
    cout << "Prueba Mochila." << endl;

    Mochila* nuevaMochila = new Mochila;

    do{
        cout << "Ingrese elementos a la Mochila: " << endl;
        cout << "Ingrese 'S' para terminar." << endl;
        getline(cin, nombre);

        if (nombre != "S"){
            nuevaMochila->agregarElemento(nombre);
            cout << '\n';
            verMochila(nuevaMochila);
            cout << '\n';
        }

    cout << "------------------------------------" << endl;
    }while(nombre != "S");

    do{
        cout << "Busque elementos de la Mochila: " << endl;
        cout << "Ingrese 'S' para terminar." << endl;
        getline(cin, nombre);

        if (nombre != "S"){

            Elemento* elementoMochila = nuevaMochila->buscarElemento(nombre);
            cout << '\n';
            cout << "Datos elemento: " << endl;
            cout << '\n';
            cout << "Nombre: " << elementoMochila->getNombre() << " " << "Cantidad: " << elementoMochila->getCantidad() << endl;
            cout << '\n';
        }

    cout << "------------------------------------" << endl;
    }while(nombre != "S");


    do{
        cout << "Elimine elementos de la Mochila: " << endl;
        cout << "Ingrese 'S' para terminar." << endl;
        getline(cin, nombre);

        if (nombre != "S"){
           nuevaMochila->eliminarElemento(nombre);
            cout << '\n';
            verMochila(nuevaMochila);
            cout << '\n';
        }

    cout << "------------------------------------" << endl;
    }while(nombre != "S");

    delete nuevaMochila;

    return 0;
}
