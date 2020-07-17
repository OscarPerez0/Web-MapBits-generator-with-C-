#pragma once
#include <iostream>
#include <string>

#include "matrizOrtogonalCapa.h"

class NodoCabecera1
{
public:


	int posicion;
	std::string nombreCapa;
	matrizOrtogonalCapa Capa;
	NodoCabecera1 *siguiente;
	NodoCabecera1 *anterior;
	

	NodoCabecera1(int posicion, std::string nombreCapa, matrizOrtogonalCapa Capa);//cons




	// int getPosicion();

	void setPosicion(int pos);

	NodoCabecera1 getSiguiente();
	void setSiguiente(NodoCabecera1 *siguiente);

	NodoCabecera1 getAnterior();
	void setAnterior(NodoCabecera1 *siguiente);

	

};

