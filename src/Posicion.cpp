#include <iostream>
#include <string>
#include "Posicion.h"
using namespace std;


Posicion::Posicion(int coordX,int coordY){
    this->coordX=coordX;
    this->coordY=coordY;
    //this->identificador=identificador;
    this->bifurcacion="";
    this->unionPosicion="";
    this->orientacionBifurcacion=0;
    this->elemento=0;
}

Posicion::~Posicion(){
    bool hayElemento=(this->elemento!=0);
    if(hayElemento){
        delete this->elemento;
    }
}

int Posicion::obtenerCoordX(){
    return this->coordX;
}

int Posicion::obtenerCoordY(){
    return this->coordY;
}

void Posicion::modificarCoordX(int coordX){
    this->coordX=coordX;
}

void Posicion::modificarCoordY(int coordY){
    this->coordY=coordY;
}

string Posicion::obtenerBifurcacion(){
    return this->bifurcacion;
}

void Posicion::agregarBifurcacion(string bifurcacion,char orientacion){
    this->bifurcacion=bifurcacion;
    this->orientacionBifurcacion=orientacion;
}

string Posicion::obtenerUnion(){
    return this->unionPosicion;
}

void Posicion::agregarUnion(string unionPosicion){
    this->unionPosicion=unionPosicion;
}

void Posicion::agregarElemento(string nombreElemento){
    if(this->elemento != 0){
        delete this->elemento;
    }
    Elemento* nuevoElemento = new Elemento(nombreElemento);
    this->elemento = nuevoElemento;
}

bool Posicion::obtenerElemento(){
    bool hayElemento=(this->elemento!=0);
    if(hayElemento){
        delete this->elemento;
    }
    return hayElemento;
}

string Posicion::obtenerIdentificador(){
    return this->identificador;
}

string Posicion::obtenerNombreElemento(){
	if (this-> elemento != 0){
		return this-> elemento-> getNombre();
	}else{
		return "vacio";
	}
}

char Posicion::obtenerOrientacionBifurcacion(){
    return this-> orientacionBifurcacion;
}

bool Posicion::tieneBifurcacion(){
    return (this-> bifurcacion != "");
}

bool Posicion::tieneUnion(){
    return (this-> unionPosicion != "");
}