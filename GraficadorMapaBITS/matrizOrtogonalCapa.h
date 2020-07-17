#pragma once
#include "NodoMatrizOrto.h"
#include "LisCabecera.h"
#include "NodoMatrizOrto.h"
class matrizOrtogonalCapa
{
public:
	LisCabecera *columnas;
	LisCabecera *filas;
	std::string recorrido;
	std::string NodosColores;
	int cantidadNodos;
	

	void insertarNodoMatriz(int x, int y, std::string color);
	void  insertarFila(NodoMatrizOrto *nuevo, NodoCabecera *fila);
	void insertarColumna(NodoMatrizOrto *nuevo, NodoCabecera *columna);
	NodoMatrizOrto* buscarNodo(int x, int y);
	void recorrerMatriz();

	void recorrerColumas();
	void recorrerFilas();
	void graficarLogico();
	void graficarLogicoImagen();
	void graficarCapaColor();
	void graficarHTML(std::string nombre, int filas, int col);
	void graficarSCSS(std::string nombre);
	void nodosSCSS(std::string nombre);
	void graficarCapaColorImagen();

	int maxFilas();
	int maxColumnas();



	matrizOrtogonalCapa();
	~matrizOrtogonalCapa();
};