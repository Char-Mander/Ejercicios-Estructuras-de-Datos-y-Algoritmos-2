// Grupo E29,Laura Jiménez Fernández
/* Comentario general sobre la solución, explicando co´mo se resuelve el problema*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <list>
#include "Header.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	// leer los datos de la entrada
	std::cin >> n;
	if (!std::cin)
		return false;

	else {
		libros l;
		std::string frase, comando, palabra, libro;
		int num;
		
		for (int i = 0; i < n; i++) {
			getline(std::cin, frase);
			std::istringstream is(frase);
			is >> comando;
			if (comando == "nuevoLibro") {
				is >> num;
				is >> palabra;
				libro = palabra;
				while (!is.eof()) {
					is >> palabra;
					libro += ' ' + palabra;
				}
				l.nuevoLibro(num, libro);
			}
			else if (comando == "comprar") {
				is >> palabra;
				libro = palabra;
				while (!is.eof()) {
					is >> palabra;
					libro += ' ' + palabra;
				}
				l.comprar(libro);
			}
			else if (comando == "estaLibro") {
				is >> palabra;
				libro = palabra;
				while (!is.eof()) {
					is >> palabra;
					libro += ' ' + palabra;
				}
				if (l.estaLibro(libro)) std::cout << "El libro " << libro << " esta en el sistema";
				else std::cout << "No existe el libro " << libro << " en el sistema";
				std::cout << '\n';
			}
			else if (comando == "elimLibro") {
				is >> palabra;
				libro = palabra;
				while (!is.eof()) {
					is >> palabra;
					libro += ' ' + palabra;
				}
				l.elimLibro(libro);
			}
			else if (comando == "numEjemplares") {
				is >> palabra;
				libro = palabra;
				while (!is.eof()) {
					is >> palabra;
					libro += ' ' + palabra;
				}
				int ej = l.numEjemplares(libro);
				std::cout << "Existen " << ej << " ejemplares del libro " << libro << '\n';
			}
			else if (comando == "top10") {
				std::vector<std::string> top = l.top10();
				for (int i = 0; i < top.size(); i++) {
					std::cout << top[i] << '\n';
				}
			}
		}


	}

	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}