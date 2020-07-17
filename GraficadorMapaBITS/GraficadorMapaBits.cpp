// GraficadorEDD2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "NodoABB.h"
#include "matrizOrtogonalCapa.h"
#include "NodoCabecera1.h"
#include "LisCabecera1.h"
#include "ABB.h"



#include <string.h>







#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>




#include <algorithm>
#include <iterator>


using namespace std;

string color = "00000";
int x = 0;
int y = 0;
string archivoInicial;
string nombreImage;
int imageSizeName;

void menu1()
{
	cout << "\n\t\t ========= MENU ==========\n\n" << endl;
	cout << " 1. Insert Image            " << endl;
	cout << " 2. Select Image            " << endl;
	cout << " 3. Apply filters            " << endl;

	cout << " 4. Manual editing            " << endl;
	cout << " 5. Export Image          " << endl;
	cout << " 6. Reports           " << endl;

	cout << " 8. SALIR                            " << endl;

	cout << "\n Insert option:" << endl;
}

void menu6() {

	cout << "\n\t\t ========= MENU REPORTES ==========\n\n" << endl;
	cout << "     " << endl;

	cout << " 1. IMPORTED IMAGES REPORT         " << endl;
	cout << " 2. IMAGE LAYER REPORT         " << endl;
	cout << " 3. LINEAR MATRIX REPORT           " << endl;

	cout << " 4. TRAVERSAL REPORT            " << endl;
	cout << " 5. FILTERS REPORT          " << endl;
	

	cout << " 8. SALIR                            " << endl;

	cout << "\n Insert option:" << endl;


}



int convertirToASCII(string letter)
{
	int idName = 0;
	for (int i = 0; i<letter.length(); i++)
	{
		char x = letter.at(i);
		idName+= int(x);
	}
	return idName;
}



class RGB
{
public:
	int R;
	int G;
	int B;

	RGB(int r, int g, int b)
	{
		R = r;
		G = g;
		B = b;
	}

	bool Equals(RGB rgb)
	{
		return (R == rgb.R) && (G == rgb.G) && (B == rgb.B);
	}
};

static string DecimalToHexadecimal(int dec) {
	if (dec < 1) return "00";
	else if (dec > 255) return "FF";

	int hex = dec;
	string hexStr = "";

	while (dec > 0)
	{
		hex = dec % 16;

		if (hex < 10)
			hexStr = hexStr.insert(0, string(1, (hex + 48)));
		else
			hexStr = hexStr.insert(0, string(1, (hex + 55)));

		dec /= 16;
	}

	return hexStr;
}




string RGBToHexadecimal(RGB rgb) {
	string rs = DecimalToHexadecimal(rgb.R);
	string gs = DecimalToHexadecimal(rgb.G);
	string bs = DecimalToHexadecimal(rgb.B);

	return '#' + rs + gs + bs;
}


string convertirRGB(string letter)
{
	int vectorColor[3];
	string hexa = "";

	string line = letter;
	istringstream templine(line);
	string data;
	int i = 0;
	while (getline(templine, data, '-'))
	{
		vectorColor[i] = atoi(data.c_str());
		i++;
	}

	int rs = vectorColor[0];
	int gs = vectorColor[1];
	int bs = vectorColor[2];


	RGB datass = RGB(rs, gs, bs);
	string values = RGBToHexadecimal(datass);






	return values;
}


int main()
{


	system("color 03");
	int op = 0;
	
	//ListaCapas *capas;
	
	
	ABB *ArbolImagenes = new ABB();
	string imagenSeleccionada = "";
	do
	{
		menu1();  cin >> op;

		switch (op)
		{
		case 1:
		{
			string iwidth = "";
			string iheight = "";
			string pwidth = "";
			string pheight = "";
			int contadorx = 0;
			int contadory = 0;
			string nombreIMG = "";
			int idIMG = 0;
			LisCabecera1* capasOrdenadas = new LisCabecera1();


			cout << "Inserte Nombre Imagen:  " << endl;
			cin >> nombreImage;
			imageSizeName = convertirToASCII(nombreImage);
			cout << "Inserte Nombre Archivo Inicial:  " << endl;
			cin >> archivoInicial;
			std::string lineU;

			ifstream myfileU(nombreImage+"/"+archivoInicial);
		
			if (myfileU.is_open())
			{
				while (getline(myfileU, lineU))
				{

				

					std::string sU = lineU;
					std::string delimiterU = ",";
					std::string layer = sU.substr(0, sU.find(delimiterU));

					std::string fileNa = sU.substr(2);
					

					//cout << "\n layer: "<< layer<< " file.....: "<<fileNa<< endl;

					if (layer =="0") {
						//cout << "\n leyendo Config" << endl;
						

						std::string linec;



						ifstream myfilec(nombreImage + "/"+fileNa);

						if (myfilec.is_open())
						{
							while (getline(myfilec, linec))
							{

								std::string sc = linec;
								std::string delimiterc= ",";
								std::string config = sc.substr(0, sc.find(delimiterc));

								std::string value= sc.substr(5, sc.find(delimiterc));



								

								std::stringstream ss(linec);
								std::string item;
								char delimeter = ',';
								std::vector<std::string> splittedStrings;
								while (getline(ss, item, delimeter))
								{
									splittedStrings.push_back(item);
								}


								//cout << "leido:  " << splittedStrings[0]<<" valor: "<< splittedStrings[1]<< endl;

								if (splittedStrings[0] =="image_width") {
									iwidth = splittedStrings[1];
									cout << "leido:" << "image_width" << ",valor:" << iwidth << "." << endl;
								}
								else if (splittedStrings[0] == "image_height") {
									iheight = splittedStrings[1];
									cout << "leido:" << "image_height" << ",valor:" << iheight << "." << endl;

								}

								else if (splittedStrings[0] == "pixel_width") {
									pwidth = splittedStrings[1];
									cout << "leido:" << "pixel_width" << ",valor:" << pwidth << "." << endl;
								}

								else if (splittedStrings[0] == "pixel_height") {
									pheight = splittedStrings[1];
									cout << "leido:" << "pixel_height" << ",valor:" << pheight << "." << endl;
								}


								
							}
						}

						


						myfilec.close();
					
					}

					else if (layer == "Layer") {
					}
					else{
						cout << "\n leyendo capa: "<< layer<< endl;

						matrizOrtogonalCapa* Capa = new matrizOrtogonalCapa();
							//readfile
						fstream file;
						file.open(nombreImage + "/"+fileNa);
						string line;
							while (getline(file, line, '\n'))
							{
								contadory++;
								contadorx=0;
								istringstream templine(line); 
								string data;
								while (getline(templine, data, ',')) 
								{
									contadorx++;

									string color = data.c_str();
									//cout << "\n Pos Y: " << contadory << " PosX: " << contadorx<< " Valor: "<<color<< endl;
									if(color !="x"){
										color = convertirRGB(color);
										//	cout << "\n      Pos Y: " << contadory << " PosX: " << contadorx<< " Nuevo Valor: "<<color<< endl;
										Capa->insertarNodoMatriz(contadorx, contadory, color);
									}
									
								}
							}
						file.close();
						NodoCabecera1 *nuevoN = new NodoCabecera1(std::stoi(layer),fileNa, *Capa);
						cout << "Capa Insertada..." << endl;
						capasOrdenadas->insertarCabecera(nuevoN);
						
					
					 contadorx = 0;
						 contadory = 0;
						
					}

				}
			}
			myfileU.close();
			iheight = std::to_string(stoi(iheight) * stoi(pheight));

			iwidth = std::to_string(stoi(iwidth) * stoi(pwidth));
			cout << "imagen Height..." <<iheight<< endl;

			cout << "imagen Width..." <<iwidth<< endl;


			NodoABB *imagen = new NodoABB(imageSizeName, nombreImage, iheight, iwidth, pheight, pwidth,capasOrdenadas);

			ArbolImagenes->insertar(&(*imagen)) ;

			capasOrdenadas->ImprimirConsola();
			//imagen = new NodoABB("nombreImagen", iwidth, iheight, pwidth, pheight, capas);

			//cout << "Inserte Nombre Imagen A Graficar:  " << endl;
			//cin >> nombreIMG;

			
			/*cout << "Inserte Nombre Imagen A Graficar:  " << endl;
			cin >> nombreIMG;

			idIMG = convertirToASCII(nombreIMG);
			ArbolImagenes->graficarNodoArbol(idIMG, nombreImage);
			ArbolImagenes->graficarnodocss(idIMG);*/
		}

			
			


		break;


		case 2:

		{

			cout << "_________Imagenes cargadas___________ " << endl;
			ArbolImagenes->menuAlfabeticoABB();
			cout << "_______________________________________ " << endl;
			cout << "Ingrese Nombre Imagen a utilizar  " << endl;
			cin >> imagenSeleccionada;


		}
		break;


		case 3:
		{

			cout << "\n\n FIILTROS  \n\n";
		}
			break;


		case 4:

		{
			cout << "\n\n EDICION MANUAL\n\n";
		}
			break;


		case 5:
		{
			string entrada = "no";
			int idimagenS = 0;
			string imactual = "";

			imactual = imagenSeleccionada;
			cout << "\n\n EXPORT IMAGE\n\n";

			cout << "La imagen a exportar es:"<< imactual <<" .Ingrese Y para continuar o N para cancelar."<<endl;
			cin >> entrada;
			if (entrada == "y" || entrada == "Y") {
			
				idimagenS = convertirToASCII(imactual);
				ArbolImagenes->graficarNodoArbol(idimagenS, imactual);
				ArbolImagenes->graficarnodocss(idimagenS);
				system("matriz.png");
				system("capa.png");
			}


		}

			break;

		case 6:
		{

			int op6 = 0;
			
			do
			{
				menu6();  cin >> op6;

				switch (op6)
				{
				case 1:
				
				{

					cout << "\n\n Arbo binario en pantalla...\n\n";
					ArbolImagenes->graficarABB();
					system("abb.png");

				}
				break;


				case 2:

				{

					string imagenS="";
					string capaS = "";
					int idimagenS;
					cout << "__________IMAGE LAYER REPORT_______________ " << endl;
					ArbolImagenes->menuAlfabeticoABB();
					cout << "_______________________________________ " << endl;
					cout << "Ingrese Nombre Imagen a graficar  " << endl;
					cin >> imagenS;

					cout << "Ingrese Nombre Capa a graficar, o si desea toda la imagen ingrese  FULL " << endl;
					cin >> capaS;

					//metodo grafica por capa o toda la imagen

					if (capaS == "full") {
						idimagenS = convertirToASCII(imagenS);
						ArbolImagenes->graficarNodoArbol(idimagenS, imagenS);
						system("matriz.png");
						system("capa.png");

					}

					else {
					
						idimagenS = convertirToASCII(imagenS);
						ArbolImagenes->graficarNodoArbolCapa(idimagenS,stoi(capaS),imagenS);
						system("matriz.png");
						system("capa.png");
					
					}

				}
				break;


				case 3:
				{
					string imagenS = "";
					string capaS = "";
					string forma = "";
					int idimagenS;
					cout << "__________LINEAR MATRIX REPORT_______________ " << endl;
					ArbolImagenes->menuAlfabeticoABB();
					cout << "_______________________________________ " << endl;
					cout << "Ingrese Nombre Imagen a graficar  " << endl;
					cin >> imagenS;

					cout << "Ingrese Numero Capa a graficar, o si desea toda la imagen ingrese  FULL " << endl;
					cin >> capaS;
					cout << "Forma de Linealizacino, Columnas o Filas " << endl;
					cin >> forma;

					if(capaS == "full") {
						if (forma == "columnas") {
							idimagenS = convertirToASCII(imagenS);
							ArbolImagenes->graficarNodoArbolCapaLineal(idimagenS, imagenS);
						}
						else if (forma == "filas") {
							idimagenS = convertirToASCII(imagenS);
							ArbolImagenes->graficarNodoArbolCapaLinealF(idimagenS, imagenS);
						}

					}

					else {

						if (forma == "columnas") {
							idimagenS = convertirToASCII(imagenS);
							ArbolImagenes->graficarNodoArbolCapaLinealC(idimagenS,stoi(capaS), imagenS);
						}
						else if (forma == "filas") {
							idimagenS = convertirToASCII(imagenS);
							ArbolImagenes->graficarNodoArbolCapaLinealFC(idimagenS, stoi(capaS), imagenS);
						}

					}


				}
					break;


				case 4:

				{
					int orden;
					cout << "__________TRAVERSAL REPORT_______________ " << endl;
					cout << "1. InOrder Transversal " << endl;
					cout << "2. PostOrden Transversal  " << endl;
					cout << "3. Preoder Transversal " << endl;
					cout << "_______________________________________ " << endl;
					cout << "Ingrese Orden a graficar " << endl;
					cin >> orden;


					if (orden == 1) {

						ArbolImagenes->recorrerABBIN();
					}
					else if (orden == 2) {
						ArbolImagenes->recorrerABBPOST();
					}
					else if (orden == 3) {
						ArbolImagenes->recorrerABBPRE();
					}

				}
					

					

					break;


				case 5:

				{}
					break;

				case 6:

				{}

					break;

				case 7:
				{}

					break;

				}

				
				system("pause");  system("cls");

			} while (op6 != 8);


			

			
		
		}


			break;

	
		}

		cout << endl << endl;
		system("pause");  system("cls");

	} while (op != 8);


	system("pause");

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
