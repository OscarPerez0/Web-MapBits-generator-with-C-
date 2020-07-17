#include "pch.h"
#include "matrizOrtogonalCapa.h"
#include "ListaLinealizada.h"
#include <string>

#include <sstream>
#include <fstream>
using namespace std;


matrizOrtogonalCapa::matrizOrtogonalCapa()
{
	this->columnas = new LisCabecera();
	this->filas = new LisCabecera();
	recorrido = "";
	NodosColores = "";
	cantidadNodos = 0;
}




void matrizOrtogonalCapa::insertarNodoMatriz(int x, int y, std::string color)
{

	NodoMatrizOrto* nuevo = buscarNodo(x, y);
	

	nuevo = new NodoMatrizOrto(x, y, color);


	NodoCabecera *fila = filas->getNumeroCabecera(x);




	insertarFila(nuevo, fila);



	NodoCabecera *columna = columnas->getNumeroCabecera(y);

	insertarColumna(nuevo, columna);


}


void matrizOrtogonalCapa::insertarFila(NodoMatrizOrto *nuevo, NodoCabecera *fila) {



	if (fila == NULL) {

		fila = new NodoCabecera(nuevo->x);

		filas->insertarCabecera(fila);
		fila->data = nuevo;
	}


	else
	{
		if (nuevo->x < fila->data->x)
		{
			nuevo->derecha = fila->data;

			fila->data->izquierda = nuevo;
			fila->data = nuevo;
		}

		else
		{
			NodoMatrizOrto *pivotex = fila->data;


			while (nuevo->x >= pivotex->x) // flag
			{

				if (nuevo->y == pivotex->y) {
					//printf("Nuevo x:%d y:%d  pivote x:%d y:%d\n", nuevo->x, nuevo->y, pivotex->x, pivotex->y);
					return;
				}

				if (pivotex->derecha == NULL)
				{
					pivotex->derecha = nuevo;
					nuevo->izquierda = pivotex;
					return;
				}
				pivotex = pivotex->derecha;
			}



			pivotex->izquierda->derecha = nuevo;

			nuevo->izquierda = (pivotex->izquierda);

			nuevo->derecha = pivotex;

			pivotex->izquierda = nuevo;

		}
	}



}


void matrizOrtogonalCapa::insertarColumna(NodoMatrizOrto *nuevo, NodoCabecera *columna)
{

	if (columna == NULL)
	{

		columna = new NodoCabecera(nuevo->y);

		columnas->insertarCabecera(columna);
		columna->data = (nuevo);


	}

	else
	{
		if (nuevo->y < columna->data->y)
		{
			nuevo->abajo = columna->data;
			columna->data->arriba = nuevo;
			columna->data = nuevo;


		}

		else
		{
			NodoMatrizOrto* pivotey = columna->data;

			while (nuevo->y >= pivotey->y) // quite >=
			{
				if ( nuevo->x == pivotey->x) {
					//printf("Nuevo x:%d y:%d  pivote x:%d y:%d\n", nuevo->x, nuevo->y, pivotey->x, pivotey->y);
					return;
				}
				if (pivotey->abajo == NULL)
				{
					pivotey->abajo = nuevo;
					nuevo->arriba = pivotey;

					return;

				}
				pivotey = pivotey->abajo;
			}
			pivotey->arriba->abajo = nuevo;
			nuevo->arriba = pivotey->arriba;
			nuevo->abajo = pivotey;
			pivotey->arriba = nuevo;
		}
	}
}


NodoMatrizOrto* matrizOrtogonalCapa::buscarNodo(int x, int y) {
	NodoCabecera *efila = filas->getNumeroCabecera(x);



	NodoMatrizOrto *retu = NULL;

	if (efila == NULL) {
		return retu;
	}
	NodoMatrizOrto *pivote = efila->data;
	while (pivote != NULL)
	{
		if (pivote->y == y) {


			return pivote;
		}
		pivote = pivote->abajo;//cambaido por derecha,abajo
	}
	return retu;


}


void matrizOrtogonalCapa::recorrerMatriz() {


	NodoCabecera *pivote = filas->primero;


	do
	{
		if (pivote != NULL)
		{
			NodoMatrizOrto *actual = pivote->data;
			while (actual != NULL)
			{


				//aqui pasa todo
				recorrido.append(std::to_string(actual->x) + "," + std::to_string(actual->y) + "," + actual->color + "\n");
				actual = actual->derecha;
			}
			pivote = pivote->siguiente;
		}
	} while (pivote != NULL && pivote != filas->primero);


}




void matrizOrtogonalCapa::recorrerColumas() {


	NodoCabecera* pivote = filas->primero;
	ListaLinealizada* filasrecorrido = new ListaLinealizada();

	do
	{
		if (pivote != NULL)
		{
			NodoMatrizOrto* actual = pivote->data;
			while (actual != NULL)
			{

				string xf = std::to_string(actual->x);
				string yf = std::to_string(actual->y);
				string colorf = actual->color;
				int numC = actual->x *maxColumnas()  +actual->y;
				NodoLinealizado *lin = new NodoLinealizado(numC, std::to_string(numC), xf, yf, colorf);
				filasrecorrido->insertar(lin);
				actual = actual->derecha;
			}
			pivote = pivote->siguiente;
		}
	} while (pivote != NULL && pivote != filas->primero);


	std::ofstream archivo;
	archivo.open("linealizadoColumas.dot", std::ios::out);
	archivo << "digraph G{" << std::endl;
	filasrecorrido->graficar(archivo, "1");
	archivo << "}" << std::endl;

	system("dot -Tpng linealizadoColumas.dot -o linealizadoColumas.png");
	system("linealizadoColumas.png");


}

void matrizOrtogonalCapa::recorrerFilas() {


	NodoCabecera* pivote = filas->primero;
	ListaLinealizada* filasrecorrido = new ListaLinealizada();

	do
	{
		if (pivote != NULL)
		{
			NodoMatrizOrto* actual = pivote->data;
			while (actual != NULL)
			{

				string xf = std::to_string(actual->x);
				string yf = std::to_string(actual->y);
				string colorf = actual->color;
				int numC = actual->y * maxColumnas() + actual->x;
				NodoLinealizado* lin = new NodoLinealizado(numC, std::to_string(numC), xf, yf, colorf);
				filasrecorrido->insertar(lin);
				actual = actual->derecha;
			}
			pivote = pivote->siguiente;
		}
	} while (pivote != NULL && pivote != filas->primero);


	std::ofstream archivo;
	archivo.open("linealizadoFilas.dot", std::ios::out);
	archivo << "digraph G{" << std::endl;
	filasrecorrido->graficar(archivo, "1");
	archivo << "}" << std::endl;

	system("dot -Tpng linealizadoFilas.dot -o linealizadoFilas.png");
	system("linealizadoFilas.png");


}

int matrizOrtogonalCapa::maxColumnas() {
	int cuenta = 0;


	cuenta = columnas->ultimo->posicion;


	return cuenta;

}


int matrizOrtogonalCapa::maxFilas() {
	int cuenta = 0;

	
			cuenta = filas->ultimo->posicion;
			

	return cuenta;

}

void matrizOrtogonalCapa::graficarLogico()
{

	std::ofstream archivo;
	archivo.open("Matriz.dot", std::ios::out);
	if (archivo.fail())
	{

	}
	else
	{
		archivo << "digraph Logico{\n" << std::endl;
		archivo << "node[shape=box];\n" << std::endl;
		archivo << "edge[style=bold, dir=both];\n" << std::endl;
		archivo << "nodo0[label=\"Capa#\" pos=\"0,0!\"];" << std::endl;

		
		//cabeceras
		NodoCabecera *pivotex = filas->primero;
		do
		{
			if (pivotex != NULL)
			{
				archivo << "\nx" << pivotex->posicion;
				archivo << "[label=\"x=" << pivotex->posicion << "\"" << " pos = \"" << ((pivotex->posicion + 1)*+120) << (",0!\"];") << endl;
				pivotex = pivotex->siguiente;
			}
		} while (pivotex != NULL && pivotex != filas->primero);


		NodoCabecera *pivoteC = columnas->primero;

		do
		{
			if (pivoteC != NULL)
			{
				archivo << "\ny" << pivoteC->posicion << "[label=\"y=" << pivoteC->posicion << "\"" << " pos = \"0," << ((pivoteC->posicion + 1)*-120) << "!\"];" << endl;
				pivoteC = pivoteC->siguiente;
			}
		} while (pivoteC != NULL && pivoteC != columnas->primero);


		//nodos restantes
		NodoCabecera *pivoteNR = filas->primero;
		
		do
		{
			if (pivoteNR != NULL)
			{
				NodoMatrizOrto *auxiliarNR = pivoteNR->data;
				while (auxiliarNR != NULL)
				{
					
					archivo << "\nnodo" << auxiliarNR->x << "_" << auxiliarNR->y << "[label=\"" << auxiliarNR->color << "\"" << " pos = \"" << ((auxiliarNR->x + 1)*+120) << "," << ((auxiliarNR->y + 1)*-120) << "!\"];" << endl;
					auxiliarNR = auxiliarNR->derecha;
				}
				pivoteNR = pivoteNR->siguiente;
			}
		} while (pivoteNR != NULL && pivoteNR != filas->primero);



		//enlace cabecera


		if (filas->primero != NULL && columnas->primero != NULL)
		{
			archivo << "\nnodo0->x" << filas->primero->posicion << ";nodo0->y" << columnas->primero->posicion << ";" << endl;
		}




		//enlace filas

		NodoCabecera *pivoteEF = filas->primero;
		do
		{
			if (pivoteEF != NULL && pivoteEF->siguiente != NULL)
			{
				archivo << "\nx" << pivoteEF->posicion << "-> x" << pivoteEF->siguiente->posicion << ";" << endl;
				pivoteEF = pivoteEF->siguiente;
			}
		} while (pivoteEF != NULL && pivoteEF != filas->primero);



		//enlace columnas

		NodoCabecera *pivoteEC = columnas->primero;
		do
		{
			if (pivoteEC != NULL && pivoteEC->siguiente != NULL)
			{
				archivo << "\ny" << pivoteEC->posicion << "->y" << pivoteEC->siguiente->posicion << ";" << endl;
				pivoteEC = pivoteEC->siguiente;
			}
		} while (pivoteEC != NULL && pivoteEC != columnas->primero);


		//ColD

		NodoCabecera *pivoteCD = columnas->primero;
		do
		{
			if (pivoteCD != NULL)
			{
				NodoMatrizOrto *auxiliarCD = pivoteCD->data;
				archivo << "\ny" << pivoteCD->posicion << "->nodo" << auxiliarCD->x << "_" << auxiliarCD->y << ";" << endl;
				pivoteCD = pivoteCD->siguiente;
			}
		} while (pivoteCD != NULL && pivoteCD != columnas->primero);


		//FilD


		NodoCabecera *pivoteFD = filas->primero;
		do
		{
			if (pivoteFD != NULL)
			{
				NodoMatrizOrto * auxiliarFD = pivoteFD->data;
				archivo << "\nx" << pivoteFD->posicion << "->nodo" << auxiliarFD->x << "_" << auxiliarFD->y << ";" << endl;
				pivoteFD = pivoteFD->siguiente;
			}
		} while (pivoteFD != NULL && pivoteFD != filas->primero);

		//ENLACE FILAS RESTANTES

		NodoCabecera *pivoteFR = filas->primero;
		do
		{
			if (pivoteFR != NULL)
			{
				NodoMatrizOrto *auxiliarFR = pivoteFR->data;
				while (auxiliarFR->derecha != NULL)
				{
					archivo << "\nnodo" << auxiliarFR->x << "_" << auxiliarFR->y << "->nodo" << auxiliarFR->x << "_" << auxiliarFR->derecha->y << ";" << endl;
					auxiliarFR = auxiliarFR->derecha;
				}
				pivoteFR = pivoteFR->siguiente;
			}
		} while (pivoteFR != NULL && pivoteFR != filas->primero);


		//Enlace Col Restantes

		NodoCabecera *pivoteCR = columnas->primero;
		do
		{
			if (pivoteCR != NULL)
			{
				NodoMatrizOrto *auxiliarCR = pivoteCR->data;
				while (auxiliarCR->abajo != NULL)
				{
					archivo << "\nnodo" << auxiliarCR->x << "_" << auxiliarCR->y << "->nodo" << auxiliarCR->abajo->x << "_" << auxiliarCR->y << ";" << endl;
					auxiliarCR = auxiliarCR->abajo;
				}
				pivoteCR = pivoteCR->siguiente;
			}
		} while (pivoteCR != NULL && pivoteCR != columnas->primero);


		//FINAL



	}//finelse
	archivo << "}" << endl;

	archivo.close();
	//neato sample.dot - n - Tpng - o sample.png
	system("neato Matriz.dot -n  -Tpng -o Matriz.png");




}

void matrizOrtogonalCapa::graficarLogicoImagen()
{

	std::ofstream archivo;
	archivo.open("ImagenCapas.dot", std::ios::out);
	if (archivo.fail())
	{

	}
	else
	{
		archivo << "digraph Logico{\n" << std::endl;
		archivo << "node[shape=box];\n" << std::endl;
		archivo << "edge[style=bold, dir=both];\n" << std::endl;
		archivo << "nodo0[label=\"Capa#\" pos=\"0,0!\"];" << std::endl;

	
		//cabeceras
		NodoCabecera *pivotex = filas->primero;
		do
		{
			if (pivotex != NULL)
			{
				archivo << "\nx" << pivotex->posicion;
				archivo << "[label=\"x=" << pivotex->posicion << "\"" << " pos = \"" << ((pivotex->posicion + 1)*+120) << (",0!\"];") << endl;
				pivotex = pivotex->siguiente;
			}
		} while (pivotex != NULL && pivotex != filas->primero);


		NodoCabecera *pivoteC = columnas->primero;

		do
		{
			if (pivoteC != NULL)
			{
				archivo << "\ny" << pivoteC->posicion << "[label=\"y=" << pivoteC->posicion << "\"" << " pos = \"0," << ((pivoteC->posicion + 1)*-120) << "!\"];" << endl;
				pivoteC = pivoteC->siguiente;
			}
		} while (pivoteC != NULL && pivoteC != columnas->primero);


		//nodos restantes
		NodoCabecera *pivoteNR = filas->primero;
		
		do
		{
			if (pivoteNR != NULL)
			{
				NodoMatrizOrto *auxiliarNR = pivoteNR->data;
				while (auxiliarNR != NULL)
				{
					
					archivo << "\nnodo" << auxiliarNR->x << "_" << auxiliarNR->y << "[label=\"" << auxiliarNR->color << "\"" << " pos = \"" << ((auxiliarNR->x + 1)*+120) << "," << ((auxiliarNR->y + 1)*-120) << "!\"];" << endl;
					auxiliarNR = auxiliarNR->derecha;
				}
				pivoteNR = pivoteNR->siguiente;
			}
		} while (pivoteNR != NULL && pivoteNR != filas->primero);



		//enlace cabecera


		if (filas->primero != NULL && columnas->primero != NULL)
		{
			archivo << "\nnodo0->x" << filas->primero->posicion << ";nodo0->y" << columnas->primero->posicion << ";" << endl;
		}




		//enlace filas

		NodoCabecera *pivoteEF = filas->primero;
		do
		{
			if (pivoteEF != NULL && pivoteEF->siguiente != NULL)
			{
				archivo << "\nx" << pivoteEF->posicion << "-> x" << pivoteEF->siguiente->posicion << ";" << endl;
				pivoteEF = pivoteEF->siguiente;
			}
		} while (pivoteEF != NULL && pivoteEF != filas->primero);



		//enlace columnas

		NodoCabecera *pivoteEC = columnas->primero;
		do
		{
			if (pivoteEC != NULL && pivoteEC->siguiente != NULL)
			{
				archivo << "\ny" << pivoteEC->posicion << "->y" << pivoteEC->siguiente->posicion << ";" << endl;
				pivoteEC = pivoteEC->siguiente;
			}
		} while (pivoteEC != NULL && pivoteEC != columnas->primero);


		//ColD

		NodoCabecera *pivoteCD = columnas->primero;
		do
		{
			if (pivoteCD != NULL)
			{
				NodoMatrizOrto *auxiliarCD = pivoteCD->data;
				archivo << "\ny" << pivoteCD->posicion << "->nodo" << auxiliarCD->x << "_" << auxiliarCD->y << ";" << endl;
				pivoteCD = pivoteCD->siguiente;
			}
		} while (pivoteCD != NULL && pivoteCD != columnas->primero);


		//FilD


		NodoCabecera *pivoteFD = filas->primero;
		do
		{
			if (pivoteFD != NULL)
			{
				NodoMatrizOrto * auxiliarFD = pivoteFD->data;
				archivo << "\nx" << pivoteFD->posicion << "->nodo" << auxiliarFD->x << "_" << auxiliarFD->y << ";" << endl;
				pivoteFD = pivoteFD->siguiente;
			}
		} while (pivoteFD != NULL && pivoteFD != filas->primero);

		//ENLACE FILAS RESTANTES

		NodoCabecera *pivoteFR = filas->primero;
		do
		{
			if (pivoteFR != NULL)
			{
				NodoMatrizOrto *auxiliarFR = pivoteFR->data;
				while (auxiliarFR->derecha != NULL)
				{
					archivo << "\nnodo" << auxiliarFR->x << "_" << auxiliarFR->y << "->nodo" << auxiliarFR->x << "_" << auxiliarFR->derecha->y << ";" << endl;
					auxiliarFR = auxiliarFR->derecha;
				}
				pivoteFR = pivoteFR->siguiente;
			}
		} while (pivoteFR != NULL && pivoteFR != filas->primero);


		//Enlace Col Restantes

		NodoCabecera *pivoteCR = columnas->primero;
		do
		{
			if (pivoteCR != NULL)
			{
				NodoMatrizOrto *auxiliarCR = pivoteCR->data;
				while (auxiliarCR->abajo != NULL)
				{
					archivo << "\nnodo" << auxiliarCR->x << "_" << auxiliarCR->y << "->nodo" << auxiliarCR->abajo->x << "_" << auxiliarCR->y << ";" << endl;
					auxiliarCR = auxiliarCR->abajo;
				}
				pivoteCR = pivoteCR->siguiente;
			}
		} while (pivoteCR != NULL && pivoteCR != columnas->primero);


		//FINAL



	}
	archivo << "}" << endl;

	archivo.close();
	//neato sample.dot - n - Tpng - o sample.png
	system("neato ImagenCapas.dot -n  -Tpng -o ImagenCapas.png");




}


void matrizOrtogonalCapa::graficarCapaColor() {

	std::ofstream archivo;
	archivo.open("Capa.dot", std::ios::out);
	if (archivo.fail())
	{

	}
	else
	{
		archivo << "digraph Mapa{\n" << endl;
		archivo << "node[shape=box, width=0.4, heigth=0.4, fillcolor=\"white\"" << endl;
		archivo << "color=\"white\" style=\"filled\"];\n" << endl;
		archivo << "edge[style = bold];\n" << endl;
		archivo << "nodo0[label=\"MAPA\" pos=\"0,0!\"];" << endl;


		NodoCabecera *pivote = filas->primero;
		do
		{
			if (pivote != NULL)
			{
				NodoMatrizOrto *auxiliar = pivote->data;
				int aux = ((auxiliar->x) + 1)*+40;
				while (auxiliar != NULL)
				{
					archivo << "\n" << auxiliar->x << "." << auxiliar->y << "[fillcolor=\"" << auxiliar->color << "\"" << " pos = \"" << aux << "," << ((auxiliar->y + 1)*-40) << "!\"];";
					auxiliar = auxiliar->derecha;
				}
				pivote = pivote->siguiente;
			}
		} while (pivote != NULL && pivote != filas->primero);

		archivo << "}" << endl;
		archivo.close();
		//neato sample.dot - n - Tpng - o sample.png
		system("neato Capa.dot -n  -Tpng -o Capa.png");
	}

}


void matrizOrtogonalCapa::graficarHTML(std::string nombre, int filas, int col) {
	int maxC = filas;
	int maxF = col;
	int to = maxC * maxF;
	std::ofstream archivo;
	archivo.open(nombre+".html", std::ios::out);
	if (archivo.fail())
	{

	}
	else
	{
		archivo << "<!DOCTYPE html>" << endl;
		archivo << "<html>" << endl;
		archivo << "<head>" << endl;
		archivo << "<link rel=\"stylesheet\" href=\""+nombre+".scss\"> </head>" << endl;
		archivo << "<body>" << endl;
		archivo << "<div class=\"canvas\">" << endl;


		for(int i=0; i<=to;i++){
			archivo << " <div class = \"pixel\"></div>" << endl;
		}
					
				

		archivo << "</div> </body>  </html>" << endl;
		archivo.close();
		//neato sample.dot - n - Tpng - o sample.png
		//system("neato Capa.dot -n  -Tpng -o Capa.png");
	}

}


void matrizOrtogonalCapa::nodosSCSS(std::string nombre) {

	std::string archivo;
	int contadorN = 0;
	int mapeo;
	int maxC = maxFilas();
	NodosColores = "";

	NodoCabecera* pivote = filas->primero;
	do
	{
		if (pivote != NULL)
		{
			NodoMatrizOrto* auxiliar = pivote->data;



			while (auxiliar != NULL)
			{
				mapeo = auxiliar->y * maxC + auxiliar->x;
				archivo.append(".pixel:nth-child(" + to_string(mapeo) + ")\{background\: " + auxiliar->color + "; } \n");
				auxiliar = auxiliar->derecha;
			}
			pivote = pivote->siguiente;
		}
	} while (pivote != NULL && pivote != filas->primero);


	//neato sample.dot - n - Tpng - o sample.png
	//system("neato Capa.dot -n  -Tpng -o Capa.png");
	NodosColores = archivo;
}


void matrizOrtogonalCapa::graficarCapaColorImagen() {

	std::ofstream archivo;
	archivo.open("Imagen.dot", std::ios::out);
	if (archivo.fail())
	{

	}
	else
	{
		archivo << "digraph Mapa{\n" << endl;
		archivo << "node[shape=box, width=0.4, heigth=0.4, fillcolor=\"white\"" << endl;
		archivo << "color=\"white\" style=\"filled\"];\n" << endl;
		archivo << "edge[style = bold];\n" << endl;
		archivo << "nodo0[label=\"MAPA\" pos=\"0,0!\"];" << endl;


		NodoCabecera *pivote = filas->primero;
		do
		{
			if (pivote != NULL)
			{
				NodoMatrizOrto *auxiliar = pivote->data;
				int aux = ((auxiliar->x) + 1)*+40;
				while (auxiliar != NULL)
				{
					archivo << "\n" << auxiliar->x << "." << auxiliar->y << "[fillcolor=\"" << auxiliar->color << "\"" << " pos = \"" << aux << "," << ((auxiliar->y + 1)*-40) << "!\"];";
					auxiliar = auxiliar->derecha;
				}
				pivote = pivote->siguiente;
			}
		} while (pivote != NULL && pivote != filas->primero);

		archivo << "}" << endl;
		archivo.close();
		//neato sample.dot - n - Tpng - o sample.png
		system("neato Imagen.dot -n  -Tpng -o Imagen.png");
	}

}


matrizOrtogonalCapa::~matrizOrtogonalCapa()
{
}

