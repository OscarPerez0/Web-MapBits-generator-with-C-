#pragma once


#include"LisCabecera1.h"

class NodoABB
{
public:
	int id;
	std::string nombreImagen;
	std::string imagewidth;
	std::string imageheight;

	std::string pixelwidth;
	std::string pixelheight;
	std::string nodosCol;

	LisCabecera1 *imagen;
	NodoABB *izq;
	NodoABB *der;
	NodoABB(int id, std::string nombreImagen, std::string ih, std::string iw, std::string ph, std::string pw, LisCabecera1 *imagen);
	~NodoABB();
};
