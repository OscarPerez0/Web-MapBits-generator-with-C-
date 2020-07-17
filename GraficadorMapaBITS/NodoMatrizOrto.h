#pragma once
#include <iostream>
#include <string>

class NodoMatrizOrto
{
public:

	std::string color;
	int x;
	int y;

	NodoMatrizOrto *derecha;
	NodoMatrizOrto *izquierda;
	NodoMatrizOrto *arriba;
	NodoMatrizOrto *abajo;
	//PUNTEROS 3D


	NodoMatrizOrto(int x, int y, std::string color);
	std::string   getColor();
	std::string  setColor(std::string dato);




};
