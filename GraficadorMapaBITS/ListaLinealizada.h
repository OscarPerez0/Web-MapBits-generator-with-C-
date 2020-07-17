#pragma once
#include "NodoLinealizado.h"

class ListaLinealizada
{
public:

	NodoLinealizado* primero;
	NodoLinealizado* ultimo;
	std::string recorridoMatriz;
	std::string recorridoMatrizFilas;
	int cantidadNodos;

	int pos;
	bool vaciaLC();
	ListaLinealizada();
	void ImprimirConsola();
	void GenerarImagen();

	void GenerarImagenLinealFilas();
	void GenerarImagenCapa(int idcapa);


	void graficar(std::ofstream& archivo, std::string Nombre);
	void GenerarImagenLinealCol();
	void GenerarImagenCapaLinealCol(int idcapa);
	void graficarListaC(std::ofstream& archivo, std::string Nombre);
	void ImprimirConsolaCompras();
	void insertar(NodoLinealizado* nuevo);
	NodoLinealizado* getNumeroCabecera(int x);
};

