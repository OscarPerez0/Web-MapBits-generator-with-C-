#include "pch.h"
#include "ListaCapas.h"




#include <stdlib.h>

#include <fstream>


ListaCapas::ListaCapas()
{
	raiz = NULL;
}

ListaCapas::~ListaCapas()
{
	if (raiz != NULL) {
		Nodo *nod = raiz->siguiente;
		Nodo *tmp;
		while (nod != raiz)
		{
			tmp = nod;
			nod = nod->siguiente;
			delete tmp;
		}
		delete raiz;
	}
}



void ListaCapas::insertar(int posicion, string idcapa)
{
	Nodo *nodoLC = new Nodo();
	nodoLC->nombren = idcapa;
	nodoLC->idn = posicion;

	nodoLC->idn = posicion;


	if (raiz == NULL)
	{
		nodoLC->siguiente = nodoLC;
		nodoLC->anterior = nodoLC;
		raiz = nodoLC;
	}
	else
	{
		Nodo *nodoUltimo = raiz->anterior;
		nodoLC->siguiente = raiz;
		nodoLC->anterior = nodoUltimo;
		raiz->anterior = nodoLC;
		nodoUltimo->siguiente = nodoLC;
	}
}

bool ListaCapas::vaciaLC()
{
	if (raiz == NULL) {
		return true;
	}
	else {
		return false;
	}
}

string ListaCapas::ImprimirConsola()
{
	string listaCapas = "";
	if (!vaciaLC())
	{
		Nodo *nodoLC = raiz;
		do {

			listaCapas.append(nodoLC->nombren + ",");
			nodoLC = nodoLC->siguiente;

		} while (nodoLC != raiz);


	}
	return listaCapas;
}

void ListaCapas::ImprimirConsolaCompras()
{
	if (!vaciaLC())
	{
		Nodo *nodoLC = raiz;
		do {

			cout << " imagen: " << nodoLC->nombren << endl;
			nodoLC = nodoLC->siguiente;

		} while (nodoLC != raiz);


	}
}



void ListaCapas::graficar(std::ofstream &archivo, string Nombre)
{


	graficarListaC(archivo, Nombre);




}

void ListaCapas::graficarListaC(std::ofstream &archivo, string Nombre) {
	archivo << "subgraph" << " cluster_" <<"1" << "{" << std::endl;
	archivo << " style=filled; color = skyblue; " << endl;
	archivo << "node [shape=box];" << std::endl;
	Nodo *reco = raiz;
	if (vaciaLC()) {
		archivo << "\"VACIA" <<  "\";" << std::endl;
	}
	do {

		archivo << "capa" << reco->idn << "[label = " << reco->nombren << "];" << endl;

		if (reco->siguiente && reco->siguiente != raiz)
		{
			archivo << "capa" <<  reco->siguiente->idn << "[label =" << reco->siguiente->nombren  << "];" << endl;

			archivo << "capa" << reco->idn<< "->capa" << reco->siguiente->idn << endl;

		}

		else
		{
			//archivo << "\"Carreta: " << reco->info << "\";" << std::endl;
		}
		reco = reco->siguiente;

	} while (reco != raiz);
	archivo << "}" << std::endl;

	

	
}




void ListaCapas::graficarDoble(std::ofstream &archivo, string Nombre)
{

	graficarListaCDoble(archivo, Nombre);




}

void ListaCapas::graficarListaCDoble(std::ofstream &archivo, string Nombre) {
	archivo << "subgraph" << " cluster_" << "1" << "{" << std::endl;
	archivo << " style=filled; color = palegreen1; " << endl;
	archivo << "label = \"Lista Cajas #" << Nombre << "\"" << endl;
	archivo << "node [shape=box];" << std::endl;
	Nodo *reco = raiz;
	do {
		if (reco != NULL) {
			archivo << "Nodo" << reco->nombren << "[label =\" Caja " << " idcapa" << reco->nombren << " Carreta " << "\"];" << endl;
			if (reco->siguiente)
			{
				archivo << "Nodo" << reco->siguiente->nombren << "[label =\" Caja " << " idcapa" << reco->siguiente->nombren << " Carreta " << " Estado " << "\"]" << std::endl;

				archivo << "Nodo" << reco->nombren << "->Nodo" << endl;
			}
			if (reco->anterior)
			{
				archivo << "Nodo" << reco->nombren << "->Nodo" << reco->anterior->nombren << endl;

			}
			else
			{
				//archivo << "\"Carreta: " << reco->info << "\";" << std::endl;
			}
			reco = reco->siguiente;
		}
	} while (reco != raiz);


	archivo << "}" << std::endl;
}

string ListaCapas::getRaiz() {
	Nodo *nodoLC = new Nodo();
	nodoLC = raiz;

	return nodoLC->nombren;
}

int ListaCapas::cuenta()
{
	int cant = 0;
	if (!vaciaLC())
	{
		Nodo *nodoLC = raiz;
		do {
			cant++;
			nodoLC = nodoLC->siguiente;
		} while (nodoLC != raiz);
	}
	return cant;
}



