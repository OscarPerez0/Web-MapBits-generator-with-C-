#include "pch.h"
#include "NodoLinealizado.h"
#include <string>



NodoLinealizado::NodoLinealizado(int posicion, std::string idcapa, std::string x, std::string y, std::string color)
{

	
	this->posicion = posicion;
	this->idnodo = idcapa;
	this->x = x;
	this->y = y;
	this->color = color;
	this->siguiente = NULL;
	this->anterior = NULL;

}





/*int NodoCabecera::getPosicion() {
///	return posicion;
}*/

void NodoLinealizado::setPosicion(int pos) {

	this->posicion = pos;
}

NodoLinealizado NodoLinealizado::getSiguiente() {

	return *siguiente;
}

void NodoLinealizado::setSiguiente(NodoLinealizado* sig) {

	siguiente = sig;
}


NodoLinealizado NodoLinealizado::getAnterior() {

	return *anterior;
}

void NodoLinealizado::setAnterior(NodoLinealizado* siguiente) {

	anterior = siguiente;
}
