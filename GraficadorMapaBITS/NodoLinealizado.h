#pragma once
#include <iostream>


#include "matrizOrtogonalCapa.h"
class NodoLinealizado
{
public:


	
	int posicion;
	std::string idnodo;

	std::string x;
	std::string y;
	std::string color;
	
	NodoLinealizado* siguiente;
	NodoLinealizado* anterior;


	NodoLinealizado(int posicion, std::string idcapa, std::string x, std::string y, std::string color);//cons




	// int getPosicion();

	void setPosicion(int pos);

	NodoLinealizado getSiguiente();
	void setSiguiente(NodoLinealizado* siguiente);

	NodoLinealizado getAnterior();
	void setAnterior(NodoLinealizado* siguiente);



};
