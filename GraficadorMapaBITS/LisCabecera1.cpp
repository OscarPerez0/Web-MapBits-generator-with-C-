#include "pch.h"
#include "LisCabecera1.h"

#include <string>


#include "Nodocabecera1.h"


LisCabecera1::LisCabecera1()
{
	this->primero = NULL;
	this->ultimo = NULL;
	this->pos = 0;
	this->recorridoMatriz = "";
	this->cantidadNodos = 0;
}


// error en insertar pueda ser
void LisCabecera1::insertarCabecera(NodoCabecera1 *nuevo)
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

			NodoCabecera1 *pivote = primero;
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

NodoCabecera1* LisCabecera1::getNumeroCabecera(int posicion)
{
	if (primero == NULL)
	{


		return NULL;

	}
	NodoCabecera1 *pivote = primero;
	do
	{

		if (pivote != NULL)
		{

			if (pivote->posicion == posicion) {
				
				return pivote;
			}
			pivote = pivote->siguiente;
		}
	} while (pivote != NULL && pivote != ultimo->siguiente);


	

	return NULL;
}

bool LisCabecera1::vaciaLC()
{
	if (primero == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void LisCabecera1::ImprimirConsola()
{
	NodoCabecera1 *pivotex = primero;
	do
	{
		if (pivotex != NULL)
		{
			std::cout << "\n --: " << pivotex->posicion << std::endl;
				pivotex = pivotex->siguiente;
		}
	} while (pivotex != NULL && pivotex != primero);
	
}


void LisCabecera1::GenerarImagen()
{
	NodoCabecera1 *pivotex = primero;
	do
	{
		if (pivotex != NULL)
		{
			
			pivotex->Capa.recorrerMatriz();
			recorridoMatriz.append(pivotex->Capa.recorrido);
			pivotex = pivotex->siguiente;
		}
	} while (pivotex != NULL && pivotex != primero);

}



void LisCabecera1::GenerarImagenLinealFilas()
{
	NodoCabecera1* pivotex = primero;
	do
	{
		if (pivotex != NULL)
		{

			pivotex->Capa.recorrerMatriz();
			recorridoMatrizFilas.append(pivotex->Capa.recorrido);
			pivotex = pivotex->siguiente;
		}
	} while (pivotex != NULL && pivotex != primero);

}


void LisCabecera1::GenerarImagenCapa(int idcapa)
{
	NodoCabecera1* pivotex = primero;
	do
	{
		if (pivotex != NULL)
		{
		if (pivotex->posicion == idcapa) {

			pivotex->Capa.graficarLogico();
			pivotex->Capa.graficarCapaColor();
			
		}
		pivotex = pivotex->siguiente;
			
		}
		else { std::cout << "capa no encontrada" << std::endl; }
	} while (pivotex != NULL && pivotex != primero);

}




void LisCabecera1::GenerarImagenCapaLF(int idcapa)
{
	

	NodoCabecera1* pivotex = primero;
	do
	{
		if (pivotex != NULL)
		{
			if (pivotex->posicion == idcapa) {

				pivotex->Capa.recorrerFilas();
				

			}
			pivotex = pivotex->siguiente;

		}
		else { std::cout << "capa no encontrada" << std::endl; }
	} while (pivotex != NULL && pivotex != primero);

}



void LisCabecera1::GenerarImagenCapaLC(int idcapa)
{
	NodoCabecera1* pivotex = primero;
	do
	{
		if (pivotex != NULL)
		{
			if (pivotex->posicion == idcapa) {

				pivotex->Capa.recorrerColumas();
				

			}
			pivotex = pivotex->siguiente;

		}
		else { std::cout << "capa no encontrada" << std::endl; }
	} while (pivotex != NULL && pivotex != primero);

}