//Grupo E29, Laura Jiménez Fernández y E63, Pablo de Torre Barrio
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <string>
#include <exception>
#include "hashmap_eda.h"
#include "Header.h"

/* Describir lo que hace la función */


/* Coste de la función */


bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin) return false;
	std::cin.ignore(1);
	libros lib;
	for(int i = 0; i < n; i++) {
		try {
			std::string linea, palabra, libro, comando;
			int ejemplares;
			getline(std::cin, linea);
			std::istringstream is(linea);
			is >> comando;
			if (comando == "nuevoLibro") {
				is >> ejemplares;
				is >> palabra;
				libro = palabra;
				while (!is.eof()) {
					is >> palabra;
					libro += ' ' + palabra;
				}

				lib.addLibro(ejemplares, libro);
			}
			else if (comando == "comprar") {
				is >> palabra;
				libro = palabra;
				while (!is.eof()) {
					is >> palabra;
					libro += ' ' + palabra;
				}
				lib.comprar(libro);
			}
			else if (comando == "estaLibro") {
				is >> palabra;
				libro = palabra;
				while (!is.eof()) {
					is >> palabra;
					libro += ' ' + palabra;
				}
				if (lib.estaLibro(libro))
					std::cout << "El libro " << libro << " esta en el sistema\n";
				else
					std::cout << "No existe el libro " << libro << " en el sistema\n";
				std::cout << "---\n";
			}
			else if (comando == "elimLibro") {
				is >> palabra;
				libro = palabra;
				while (!is.eof()) {
					is >> palabra;
					libro += ' ' + palabra;
				}
				lib.elimLibro(libro);
			}
			else if (comando == "numEjemplares") {
				is >> palabra;
				libro = palabra;
				while (!is.eof()) {
					is >> palabra;
					libro += ' ' + palabra;
				}
				int n = lib.numEjemplares(libro);
				std::cout << "Existen " << n << " ejemplares del libro " << libro << '\n';
				std::cout << "---\n";
			}
			else if (comando == "top10") {
				std::vector<std::string> top = lib.top10();
				int n;
				if (top.size() > 10)
					n = 10;
				else
					n = top.size();
				for (int i = 0; i < n; i ++) {
					std::cout << top[i] << '\n';
				}
				std::cout << "---\n";
			}
		}
		catch (std::domain_error e) {
			std::cout << e.what();
			std::cout << "---\n";
		}
		catch (std::invalid_argument e) {
			std::cout << e.what();
			std::cout << "---\n";
		}
		catch (std::out_of_range e) {
			std::cout << e.what();
			std::cout << "---\n";
		}
	}
	
	std::cout << "------" << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso())
		;

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}