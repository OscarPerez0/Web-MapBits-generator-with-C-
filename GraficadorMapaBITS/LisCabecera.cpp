#include "pch.h"
#include "LisCabecera.h"

#include "Nodocabecera.h"


LisCabecera::LisCabecera()
{
	this->primero = NULL;
	this->ultimo = NULL;
	this->pos = 0;
}


// error en insertar pueda ser
void LisCabecera::insertarCabecera(NodoCabecera *nuevo)
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

			NodoCabecera *pivote = primero;
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

NodoCabecera* LisCabecera::getNumeroCabecera(int posicion)
{
	if (primero == NULL)
	{

		//	std::cout << "primeronull" <<std::endl;
		return NULL;

	}
	NodoCabecera *pivote = primero;
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



