#include "pch.h"

#include "NodoABB.h"


NodoABB::NodoABB(int id, std::string nombreImagen, std::string ih, std::string iw, std::string ph, std::string pw, LisCabecera1 *imagen)


{
	this->id = id;
	this->nombreImagen = nombreImagen;
	this->imageheight=ih;
	this->imagewidth = iw;
	this->pixelheight = ph;
	this->pixelwidth = pw;

	this->imagen = imagen;

	this->izq = NULL;

	this->der = NULL;
}

NodoABB::~NodoABB()
{
}
