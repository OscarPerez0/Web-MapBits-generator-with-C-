#pragma once

#include "NodoMatrizOrto.h"
class NodoCabecera
{
public:


	int posicion;
	NodoCabecera *siguiente;
	NodoCabecera *anterior;
	NodoMatrizOrto *data;

	NodoCabecera(int posicion);//cons




	// int getPosicion();

	void setPosicion(int pos);

	NodoCabecera getSiguiente();
	void setSiguiente(NodoCabecera *siguiente);

	NodoCabecera getAnterior();
	void setAnterior(NodoCabecera *siguiente);

	NodoMatrizOrto getInfo();
	void setInfo(NodoMatrizOrto *info);

};


