#include "pch.h"
#include "ListaLinealizada.h"



#include <stdlib.h>

#include <fstream>


#include "NodoLinealizado.h"


ListaLinealizada::ListaLinealizada()
{
	this->primero = NULL;
	this->ultimo = NULL;
	this->pos = 0;
	this->recorridoMatriz = "";
	this->cantidadNodos = 0;
}


// error en insertar pueda ser
void ListaLinealizada::insertar(NodoLinealizado* nuevo)
{


	if (primero == NULL) {
		primero = ultimo = nuevo;

	}

	else
	{

		if (nuevo->posicion < primero->posicion)
		{

			nuevo->siguiente = primero;
			nuevo->anterior = ultimo;

			ultimo->siguiente = nuevo;

			primero->anterior = nuevo;
			primero = nuevo;
		}


		else {

			NodoLinealizado* pivote = primero;
			while (nuevo->posicion > pivote->posicion)
			{

				if (pivote == ultimo) {

					ultimo->siguiente = nuevo;

					nuevo->anterior = ultimo;

					nuevo->siguiente = primero;

					primero->anterior = nuevo;
					ultimo = nuevo;

					return;
				}

				pivote = pivote->siguiente;

			}
			pivote->anterior->siguiente = nuevo;

			nuevo->anterior = pivote->anterior;

			nuevo->siguiente = pivote;
			pivote->anterior = nuevo;



		}
	}


}

// posible error

NodoLinealizado* ListaLinealizada::getNumeroCabecera(int posicion)
{
	if (primero == NULL)
	{

		//	std::cout << "primeronull" <<std::endl;
		return NULL;

	}
	NodoLinealizado* pivote = primero;
	do
	{

		if (pivote != NULL)
		{

			if (pivote->posicion == posicion) {
				//		std::cout << "pos Encontrada " << pivote->posicion << std::endl;
				return pivote;
			}
			pivote = pivote->siguiente;
		}
	} while (pivote != NULL && pivote != ultimo->siguiente);


	//std::cout << "no esta en la cabecera " << std::endl;

	return NULL;
}

bool ListaLinealizada::vaciaLC()
{
	if (primero == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void ListaLinealizada::ImprimirConsola()
{
	NodoLinealizado* pivotex = primero;
	do
	{
		if (pivotex != NULL)
		{
			std::cout << "\n Nombre: " << pivotex->posicion << std::endl;
			pivotex = pivotex->siguiente;
		}
	} while (pivotex != NULL && pivotex != primero);

}


void ListaLinealizada::GenerarImagen()
{
	NodoLinealizado* pivotex = primero;
	do
	{
		if (pivotex != NULL)
		{

			
			pivotex = pivotex->siguiente;
		}
	} while (pivotex != NULL && pivotex != primero);

}


void ListaLinealizada::graficar(std::ofstream& archivo, std::string Nombre)
{


	graficarListaC(archivo, Nombre);




}


void ListaLinealizada::graficarListaC(std::ofstream& archivo, std::string Nombre) {
	archivo << "subgraph" << " cluster_" << Nombre << "{" << std::endl;
	archivo << " style=filled; color = skyblue; " << std::endl;
	archivo << "node [shape=box];" << std::endl;
	NodoLinealizado* reco = primero;
	if (vaciaLC()) {
		archivo << "\"VACIA" << "\";" << std::endl;
	}
	do {

		archivo << "capa" << reco->idnodo << "[label =\" #Nodo" << reco->idnodo << " (" << reco->x << "," << reco->y << ") " << reco->color << "\"];" << std::endl;

		if (reco->siguiente && reco->siguiente != primero)
		{
			archivo << "capa" << reco->siguiente->idnodo << "[label =\" #Nodo" << reco->siguiente->idnodo << " (" << reco->siguiente->x << "," << reco->siguiente->y << ") " << reco->siguiente->color << "\"];" << std::endl;

			archivo << "capa" << reco->idnodo << "->capa" << reco->siguiente->idnodo << std::endl;

		}

		else
		{
			//archivo << "\"Carreta: " << reco->info << "\";" << std::endl;
		}
		reco = reco->siguiente;

	} while (reco != primero);
	archivo << "}" << std::endl;
}



void ListaLinealizada::GenerarImagenLinealFilas()
{
	NodoLinealizado* pivotex = primero;
	do
	{
		if (pivotex != NULL)
		{

			//pivotex->Capa.recorrerMatriz();
			//recorridoMatrizFilas.append(pivotex->Capa.recorrido);
			pivotex = pivotex->siguiente;
		}
	} while (pivotex != NULL && pivotex != primero);

}


void ListaLinealizada::GenerarImagenCapa(int idcapa)
{
	NodoLinealizado* pivotex = primero;
	do
	{
		if (pivotex != NULL)
		{
			if (pivotex->posicion == idcapa) {

			//	pivotex->Capa.graficarLogico();
			//	pivotex->Capa.graficarCapaColor();

			}
			pivotex = pivotex->siguiente;

		}
		else { std::cout << "capa no encontrada" << std::endl; }
	} while (pivotex != NULL && pivotex != primero);

}