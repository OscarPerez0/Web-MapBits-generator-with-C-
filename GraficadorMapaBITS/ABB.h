#pragma once
#include "NodoABB.h"
#include "NodoABB.h"
#include "ListaCapas.h"
#include <fstream>
#include <iostream>

class ABB
{
public:

	
	
private:
	NodoABB *raiz;
	void insertarABB(NodoABB** raiz,  NodoABB* nuevo);

	void ayudanteRE(NodoABB* raiz);

	void ayudantePreorden(NodoABB* raiz, ListaCapas *preorden);
	void ayudanteInorden(NodoABB* raiz, ListaCapas* preorden);
	void ayudantePostorden(NodoABB* raiz, ListaCapas* preorden);
	

	NodoABB* crearNodo(NodoABB* nuevo);
	NodoABB* buscarNodo(NodoABB* raiz, int id);
	
	std::string generarDot(NodoABB* raiz);
	std::string toDot(NodoABB* raiz);

	
	
	

public:
	ABB(); 
	void insertar(NodoABB* nuevo);
	void menuAlfabeticoABB();
	void recorrerABBPRE();
	void recorrerABBIN();
	void recorrerABBPOST();
	void graficarNodoArbol(int id, std::string nombre);
	void graficarnodocss(int id);
	void graficarNodo(int id, std::string nombre, NodoABB* raiz);
	void graficarSCSS(int id, NodoABB* raiz);
	void graficarABB();
	


	void graficarNodoArbolCapa(int id,int numero,  std::string nombre);

	void graficarNodoCapa(int id, int numero, std::string nombre, NodoABB* raiz);
	

	void graficarNodoArbolCapaLineal(int id,  std::string nombre);
	void graficarNodoCapaLineal(int id,   NodoABB* raiz);

	void graficarNodoArbolCapaLinealF(int id, std::string nombre);
	void graficarNodoCapaLinealF(int id, NodoABB* raiz);



	void graficarNodoArbolCapaLinealC(int id, int numero, std::string nombre);
	void graficarNodoCapaLinealC(int id, int numero, std::string nombre, NodoABB* raiz);

	void graficarNodoArbolCapaLinealFC(int id, int numero, std::string nombre);
	void graficarNodoCapaLinealFC(int id, int numero, std::string nombre,  NodoABB* raiz);
	NodoABB* buscar(int clave);

};
