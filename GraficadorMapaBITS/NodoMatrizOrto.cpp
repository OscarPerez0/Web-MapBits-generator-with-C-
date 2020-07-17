#include "pch.h"
#include "NodoMatrizOrto.h"


NodoMatrizOrto::NodoMatrizOrto(int x, int y, std::string color)
{
	this->x = x;

	this->y = y;


	this->color = color;


	this->derecha = NULL;
	this->izquierda = NULL;

	this->arriba = NULL;

	this->abajo = NULL;
}


std::string NodoMatrizOrto::getColor() {
	return color;
}

std::string NodoMatrizOrto::setColor(std::string dato) {
	this->color = dato;
	return dato;
}
