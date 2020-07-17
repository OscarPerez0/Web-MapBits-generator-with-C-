#include "pch.h"
#include "NodoCabecera.h"





NodoCabecera::NodoCabecera(int posicion)
{

	this->posicion = posicion;
	this->siguiente = NULL;
	this->anterior = NULL;
	this->data = NULL;
}


NodoMatrizOrto NodoCabecera::getInfo() {
	return *data;
}

void NodoCabecera::setInfo(NodoMatrizOrto *info) {

	this->data = info;

}
/*int NodoCabecera::getPosicion() {
///	return posicion;
}*/

void NodoCabecera::setPosicion(int pos) {

	this->posicion = pos;
}

NodoCabecera NodoCabecera::getSiguiente() {

	return *siguiente;
}

void NodoCabecera::setSiguiente(NodoCabecera *sig) {

	siguiente = sig;
}


NodoCabecera NodoCabecera::getAnterior() {

	return *anterior;
}

void NodoCabecera::setAnterior(NodoCabecera *siguiente) {

	anterior = siguiente;
}