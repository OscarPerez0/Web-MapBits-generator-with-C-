#pragma once
#include "NodoCabecera.h"
class LisCabecera
{
public:

	NodoCabecera *primero;
	NodoCabecera *ultimo;
	int pos;

	LisCabecera();

	void insertarCabecera(NodoCabecera *nuevo);
	NodoCabecera* getNumeroCabecera(int x);
};
