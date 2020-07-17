#pragma once
#include <iostream>
#include <string>
#include "matrizOrtogonalCapa.h"

using namespace std;


class ListaCapas {
private:
	class Nodo {
	public:
		int idn;
		string nombren;
		
		
		Nodo *siguiente;
		Nodo *anterior;

	};

	Nodo *raiz;
public:
	ListaCapas();
	~ListaCapas();
	string getRaiz();
	void graficar(std::ofstream &archivo, string Nombre);
	void graficarDoble(std::ofstream &archivo, string Nombre);

	void insertar(int posicion, string idnodo);
	bool vaciaLC();
	string ImprimirConsola();
	void ImprimirConsolaCompras();
	void graficarListaC(std::ofstream &archivo, string Nombre);
	void graficarListaCDoble(std::ofstream &archivo, string Nombre);
	int cuenta();

};
