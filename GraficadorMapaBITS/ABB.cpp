#include "pch.h"
#include "ABB.h"
#include "ListaCapas.h"
#include <sstream> 
#include <stdlib.h>
#include <string>
#include <vector>

#include <fstream>

ABB::ABB()
{
	
	this->raiz = NULL;

	

}
NodoABB *ABB::crearNodo(NodoABB *nuevo)
{
	NodoABB* nuevo1;
	nuevo1 = new NodoABB(*nuevo);
	
	return nuevo1;
}
void ABB::insertarABB(NodoABB** raiz, NodoABB*nuevo)
{
	if (!(*raiz))
	{
		*raiz = crearNodo(nuevo);
		
	}
	else if (((*raiz)->nombreImagen).compare((nuevo)->nombreImagen) ==0)
	{
		

		std::cout << "no se inserto " << std::endl;
	}
	else if (((nuevo)->nombreImagen).compare( (*raiz)->nombreImagen)<0)
		insertarABB(&((*raiz)->izq), &(*nuevo));
	else
		insertarABB(&((*raiz)->der), &(*nuevo));
}


void ABB::insertar(NodoABB  *nuevo)
{
	insertarABB(&raiz, &(*nuevo));
}

NodoABB* ABB::buscarNodo(NodoABB* raiz, int id)
{
	if (raiz == nullptr)
	{
		std::cout << "No se ha encontrado  dentro del abb" << std::endl;
		return nullptr;
	}

	if (raiz->id == id)
		return raiz;
	else if (id < raiz->id)
		return buscarNodo(raiz->izq, id);
	else
		return buscarNodo(raiz->der, id);
}

NodoABB* ABB::buscar(int clave)
{
	return buscarNodo(raiz, clave);
}

void ABB::recorrerABBPRE()
{


	ListaCapas* preorden = new ListaCapas();
	std::cout << "RECORRIENDO ARBOL PREORDER ABB" << std::endl;
	ayudantePreorden(raiz, preorden);

	std::ofstream archivo;
	archivo.open("PreOrden.dot", std::ios::out);
	archivo << "digraph G{" << std::endl;
	preorden->graficar(archivo, "1");
	archivo << "}" << std::endl;

	system("dot -Tpng PreOrden.dot -o PreOrden.png");
	system("PreOrden.png");
}

void ABB::ayudantePreorden(NodoABB* raiz, ListaCapas * preorden)
{

	if (raiz == nullptr) return;
	
	std::cout << "El id es: " << raiz->id << " El nombre es: " << raiz->nombreImagen << std::endl;

	preorden->insertar(raiz->id, raiz->nombreImagen);
	
	ayudantePreorden(raiz->izq, preorden);
	ayudantePreorden(raiz->der, preorden);



	


}


void ABB::recorrerABBIN()
{

	ListaCapas* preorden = new ListaCapas();
	std::cout << "RECORRIENDO INORDER ABB" << std::endl;
	ayudanteInorden(raiz, preorden);




	std::ofstream archivo;
	archivo.open("InOrder.dot", std::ios::out);
	archivo << "digraph G{" << std::endl;
	preorden->graficar(archivo, "1");
	archivo << "}" << std::endl;

	system("dot -Tpng InOrder.dot -o InOrder.png");
	system("InOrder.png");
}

void ABB::ayudanteInorden(NodoABB* raiz, ListaCapas *preorden)
{

	
	if (raiz == nullptr) return;

	ayudanteInorden(raiz->izq, preorden);
	std::cout << "El id es: " << raiz->id << " El nombre es: " << raiz->nombreImagen << std::endl;
	preorden->insertar(raiz->id, raiz->nombreImagen);
	
	ayudanteInorden(raiz->der, preorden);



}






void ABB::menuAlfabeticoABB()
{

	
	std::cout << "******** IMAGENES EN ARBOL*********" << std::endl;
	ayudanteRE(raiz);




	
}

void ABB::ayudanteRE(NodoABB* raiz)
{


	if (raiz == nullptr) return;

	ayudanteRE(raiz->izq);
	std::cout << "- " << raiz->nombreImagen << std::endl;
	
	ayudanteRE(raiz->der);



}





void ABB::recorrerABBPOST()
{
	ListaCapas* preorden = new ListaCapas();
	std::cout << "RECORRIENDO POSTORDEN ABB" << std::endl;
	ayudantePostorden(raiz, preorden);


	std::ofstream archivo;
	archivo.open("PostOrden.dot", std::ios::out);
	archivo << "digraph G{" << std::endl;
	preorden->graficar(archivo, "1");
	archivo << "}" << std::endl;

	system("dot -Tpng PostOrden.dot -o PostOrden.png");
	system("PostOrden.png");
}

void ABB::ayudantePostorden(NodoABB* raiz, ListaCapas *preorden)
{
	if (raiz == nullptr) return;

	ayudantePostorden(raiz->izq, preorden);
	


	ayudantePostorden(raiz->der, preorden);

	std::cout << "El id es: " << raiz->id << " El nombre es: " << raiz->nombreImagen << std::endl;
	preorden->insertar(raiz->id, raiz->nombreImagen);


	

}










void ABB::graficarNodoArbolCapa(int id, int numero, std::string nombre)
{


	graficarNodoCapa(id, numero, nombre, this->raiz); 

}



void ABB::graficarNodoCapa(int id, int numero, std::string nombre, NodoABB* raiz)
{
	
	
	if (raiz != NULL)
	{
		if (raiz->id == id) 
		{


			cout << "impriimiendo capa " << nombre << ", " << numero << endl;
			raiz->nodosCol = "";

			raiz->imagen->recorridoMatriz = "";
			raiz->imagen->GenerarImagenCapa(numero);


			


			return;
		}

		else if (id < raiz->id)
		{
			graficarNodoCapa(id, numero,  nombre, raiz->izq);
		}

		else if (id > raiz->id)
		{
			graficarNodoCapa(id, numero,  nombre, raiz->der);
		}
	}
}




void ABB::graficarNodoArbolCapaLineal(int id,  std::string nombre)
{


	graficarNodoCapaLineal(id, this->raiz); 

}



void ABB::graficarNodoCapaLineal(int id,  NodoABB* raiz)
{

	matrizOrtogonalCapa* ImagenFinal = new matrizOrtogonalCapa();
	int contadorNodos = 0;
	int vectorCoor[4];
	if (raiz != NULL)
	{
		if (raiz->id == id) 
		{

			raiz->nodosCol = "";

			raiz->imagen->recorridoMatriz = "";
			raiz->imagen->GenerarImagen();


			std::string str = raiz->imagen->recorridoMatriz;
			std::string word;
			std::stringstream stream(str);

			while (getline(stream, word, '\n'))
			{

				std::string strf = word;
				std::string wordf;
				std::stringstream streamf(strf);
				int i = 0;

				while (getline(streamf, wordf, ',')) {
					contadorNodos++;
					vectorCoor[i] = atoi(wordf.c_str());
					i++;

				}
				ImagenFinal->insertarNodoMatriz(vectorCoor[0], vectorCoor[1], wordf);
			}
			
			ImagenFinal->recorrerMatriz();
			ImagenFinal->recorrerColumas();
			
			


			return;
		}

		else if (id < raiz->id)
		{
			graficarNodoCapaLineal(id,  raiz->izq);
		}

		else if (id > raiz->id)
		{
			graficarNodoCapaLineal(id,  raiz->der);
		}
	}
}





void ABB::graficarNodoArbolCapaLinealF(int id, std::string nombre)
{


	graficarNodoCapaLinealF(id, this->raiz);

}



void ABB::graficarNodoCapaLinealF(int id, NodoABB* raiz)
{

	matrizOrtogonalCapa* ImagenFinal = new matrizOrtogonalCapa();
	int contadorNodos = 0;
	int vectorCoor[4];
	if (raiz != NULL)
	{
		if (raiz->id == id) 
		{

			raiz->nodosCol = "";

			raiz->imagen->recorridoMatriz = "";
			raiz->imagen->GenerarImagen();


			std::string str = raiz->imagen->recorridoMatriz;
			std::string word;
			std::stringstream stream(str);

			while (getline(stream, word, '\n'))
			{

				std::string strf = word;
				std::string wordf;
				std::stringstream streamf(strf);
				int i = 0;

				while (getline(streamf, wordf, ',')) {
					contadorNodos++;
					vectorCoor[i] = atoi(wordf.c_str());
					i++;

				}
				ImagenFinal->insertarNodoMatriz(vectorCoor[0], vectorCoor[1], wordf);
			}

			ImagenFinal->recorrerMatriz();
			ImagenFinal->recorrerFilas();




			return;
		}

		else if (id < raiz->id)
		{
			graficarNodoCapaLinealF(id, raiz->izq);
		}

		else if (id > raiz->id)
		{
			graficarNodoCapaLinealF(id, raiz->der);
		}
	}
}






///por acapaaaaaaaaaaaaaaaaaaaaaaaa




void ABB::graficarNodoArbolCapaLinealC(int id, int numero, std::string nombre)
{


	graficarNodoCapaLinealC(id, numero, nombre,  this->raiz); 

}



void ABB::graficarNodoCapaLinealC(int id, int numero, std::string nombre, NodoABB* raiz)
{
	if (raiz != NULL)
	{
		if (raiz->id == id) 
		{


			cout << "impriimiendo capa " << nombre << ", " << numero << endl;
			raiz->nodosCol = "";

			raiz->imagen->recorridoMatriz = "";
			raiz->imagen->GenerarImagenCapaLC(numero);





			return;
		}

		else if (id < raiz->id)
		{
			graficarNodoCapaLinealC(id, numero, nombre, raiz->izq);
		}

		else if (id > raiz->id)
		{
			graficarNodoCapaLinealC(id, numero, nombre, raiz->der);
		}
	}
}





void ABB::graficarNodoArbolCapaLinealFC(int id, int numero, std::string nombre)
{


	graficarNodoCapaLinealFC(id,numero, nombre, this->raiz); 

}



void ABB::graficarNodoCapaLinealFC(int id, int numero, std::string nombre, NodoABB* raiz)
{

	matrizOrtogonalCapa* ImagenFinal = new matrizOrtogonalCapa();
	int contadorNodos = 0;
	int vectorCoor[4];
	if (raiz != NULL)
	{
		if (raiz->id == id) 
		{

			raiz->nodosCol = "";

			raiz->imagen->recorridoMatriz = "";
			raiz->imagen->GenerarImagenCapaLF(numero);

			




			return;
		}

		else if (id < raiz->id)
		{
			graficarNodoCapaLinealFC(id, numero, nombre, raiz->izq);
		}

		else if (id > raiz->id)
		{
			graficarNodoCapaLinealFC(id, numero, nombre, raiz->der);
		}
	}
}




void ABB::graficarNodoArbol(int id, std::string nombre)
{


	graficarNodo(id,nombre,  this->raiz); 

}



void ABB::graficarNodo(int id, std::string nombre, NodoABB* raiz)
{
	matrizOrtogonalCapa* ImagenFinal = new matrizOrtogonalCapa();
	int contadorNodos = 0;
	int vectorCoor[3];
	if (raiz != NULL)
	{
		if (raiz->id == id) 
		{

			raiz->nodosCol = "";
		
			raiz->imagen->recorridoMatriz = "";
			raiz->imagen->GenerarImagen();


			std::string str = raiz->imagen->recorridoMatriz;
			std::string word;
			std::stringstream stream(str);

			while (getline(stream, word, '\n'))
			{

				std::string strf = word;
				std::string wordf;
				std::stringstream streamf(strf);
				int i = 0;

				while (getline(streamf, wordf, ',')) {
					contadorNodos++;
					vectorCoor[i] = atoi(wordf.c_str());
					i++;

				}
				ImagenFinal->insertarNodoMatriz(vectorCoor[0], vectorCoor[1], wordf);
			}
			ImagenFinal->graficarCapaColor();
			ImagenFinal->graficarLogico();
			int fil = (stoi(raiz->imagewidth) / stoi(raiz->pixelwidth))+1 ;
			int col = (stoi(raiz->imageheight) / stoi(raiz->pixelheight))+1;
			ImagenFinal->graficarHTML(nombre, fil,col) ;
			ImagenFinal->nodosSCSS("");
			std::cout << "max filas" << ImagenFinal->maxFilas() << std::endl;
			std::cout << "max columnas" << ImagenFinal->maxColumnas() << std::endl;
			raiz->nodosCol = ImagenFinal->NodosColores;


			return;
		}

		else if (id < raiz->id)
		{
			graficarNodo(id, nombre,  raiz->izq);
		}

		else if (id > raiz->id)
		{
			graficarNodo(id, nombre, raiz->der);
		}
	}
}

void ABB::graficarnodocss(int id)
{


	graficarSCSS(id, this->raiz); 

}
void ABB::graficarSCSS(int id, NodoABB* raiz) {
	if (raiz != NULL)
	{
		if (raiz->id == id) 
		{
			std::ofstream archivo;
			archivo.open(raiz->nombreImagen + ".scss", std::ios::out);
			if (archivo.fail())
			{

			}
			else
			{
				archivo << "body { background: #333333;" << std::endl;
				archivo << "height: 100vh;" << std::endl;
				archivo << " display: flex;  " << std::endl;
				archivo << "justify-content: center;" << std::endl;
				archivo << "align-items: center;}" << std::endl;

				archivo << ".canvas {" << std::endl;
				archivo << " width:"<<raiz->imagewidth<<"px;" << std::endl;
				archivo << " height:" << raiz->imageheight << "px;}" << std::endl;

				archivo << ".pixel {" << std::endl;
				archivo << " width:" << raiz->pixelwidth << "px;" << std::endl;
				archivo << " height:" << raiz->pixelheight << "px;" << std::endl;
				archivo << "  float: left; }" << std::endl;

				archivo << raiz->nodosCol << std::endl;

			}
			return;
		}

		else if (id < raiz->id)
		{
			graficarSCSS(id, raiz->izq);
		}

		else if (id > raiz->id)
		{
			graficarSCSS (id, raiz->der);
		}
	}
	 
}

void ABB::graficarABB()
{
	std::ofstream fs("abb.dot");
	fs << generarDot(raiz);
	fs.close();
	system("dot -Tpng abb.dot -o abb.png");
}



std::string ABB::generarDot(NodoABB* raiz)
{
	if (raiz == nullptr) return nullptr;
	std::ostringstream buffer;
	buffer << "digraph G{" << std::endl;
	buffer << "graph[overlap=true, fontsize=1];" << std::endl;
	buffer << "node[shape=ellipse, fontname=Helvetica,fixedsize=false];" << std::endl;
	buffer << toDot(raiz);
	buffer << "}";
	return buffer.str();
}

std::string ABB::toDot(NodoABB* raiz)
{
	std::ostringstream buffer;
	if (raiz->izq != nullptr)
	{

		buffer << "nodo" << raiz->id << "[label=\"Id:" << raiz->id << "\\nNombre:" << raiz->nombreImagen << "\\nImage Width: "<< raiz->imagewidth
			<< "\ Image Height: " << raiz->imageheight <<  "\\nPixel Width: " << raiz->pixelwidth << "\ Pixel Height: " << raiz->pixelheight<<"\" ];\n";

		buffer << "nodo" << raiz->izq->id<< "[label=\"Id:" << raiz->izq->id << "\\nNombre:" << raiz->izq->nombreImagen  << "\\nImage Width: " << raiz->izq->imagewidth
			<< "\ Image Height: " << raiz->izq->imageheight << "\\nPixel Width: " << raiz->izq->pixelwidth << "\ Pixel Height: " << raiz->izq->pixelheight << "\" ];\n";


		buffer << "nodo" << raiz->id << "->" << "nodo" << raiz->izq->id <<" [label=\"Iz\" color=\"dodgerblue\" ]"<< std::endl;

		buffer << toDot(raiz->izq);
	}
	if (raiz->der != nullptr)
	{
		buffer << "nodo" << raiz->id << "[label=\"Id:" << raiz->id << "\\nNombre:" << raiz->nombreImagen << "\\nImage Width: " << raiz->imagewidth
			<< "\ Image Height: " << raiz->imageheight << "\\nPixel Width: " << raiz->pixelwidth << "\ Pixel Height: " << raiz->pixelheight << "\" ];\n";

		buffer << "nodo" << raiz->der->id << "[label=\"Id:" << raiz->der->id << "\\nNombre:" << raiz->der->nombreImagen<< "\\nImage Width: " << raiz->der->imagewidth
			<< "\ Image Height: " << raiz->der->imageheight << "\\nPixel Width: " << raiz->der->pixelwidth << "\ Pixel Height: " << raiz->der->pixelheight << "\" ];\n";;

		buffer << "nodo" << raiz->id << "->" << "nodo" << raiz->der->id << " [label=\"De\" color=\"red\" ]" << std::endl;

		buffer << toDot(raiz->der);
	}

	return buffer.str();
}








