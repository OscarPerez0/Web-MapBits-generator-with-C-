#pragma once
#include "NodoCabecera1.h"

#include <string>
class LisCabecera1
{
public:

	NodoCabecera1 *primero;
	NodoCabecera1 *ultimo;
	std::string recorridoMatriz;
	std::string recorridoMatrizFilas;
	int cantidadNodos;
	
	int pos;
	bool vaciaLC();
	LisCabecera1();
	void ImprimirConsola();
	void GenerarImagen();
	void GenerarImagenCapaLC(int numero);

	void GenerarImagenCapaLF(int numero);

	void GenerarImagenLinealFilas();
	void GenerarImagenCapa(int idcapa);



	
	void insertarCabecera(NodoCabecera1 *nuevo);
	NodoCabecera1* getNumeroCabecera(int x);
};
