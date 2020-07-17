#include "pch.h"
#include "NodoCabecera1.h"



NodoCabecera1::NodoCabecera1(int posicion, std::string nombreCapa, matrizOrtogonalCapa Capa)
{
	this->nombreCapa = nombreCapa;
	this->Capa = Capa;
	this->posicion = posicion;
	this->siguiente = NULL;
	this->anterior = NULL;
	
}





/*int NodoCabecera::getPosicion() {
///	return posicion;
}*/

void NodoCabecera1::setPosicion(int pos) {

	this->posicion = pos;
}

NodoCabecera1 NodoCabecera1::getSiguiente() {

	return *siguiente;
}

void NodoCabecera1::setSiguiente(NodoCabecera1 *sig) {

	siguiente = sig;
}


NodoCabecera1 NodoCabecera1::getAnterior() {

	return *anterior;
}

void NodoCabecera1::setAnterior(NodoCabecera1 *siguiente) {

	anterior = siguiente;
}
