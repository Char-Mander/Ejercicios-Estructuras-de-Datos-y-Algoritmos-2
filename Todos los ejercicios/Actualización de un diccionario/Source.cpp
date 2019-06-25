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
#include "hashmap_eda.h"
#include "Header.h"

/* Describir lo que hace la función */


/* Coste de la función */


void resuelveCaso() {

	std::vector<std::string> anadir, quitar, modificar;
	diccionario s;
	std::string antiguo, nuevo;

	getline(std::cin, antiguo);
	getline(std::cin, nuevo);
	std::istringstream isa(antiguo);
	std::istringstream isn(nuevo);
	std::string auxclaveA = "", auxvalorA = "";
	std::string auxclaveN = "", auxvalorN = ""; 
	
	while (!isa.eof()) {
		isa >> auxclaveA;
		isa >> auxvalorA;
		if (auxclaveA != "" && auxvalorA != "")
			s.cargarAntiguo(auxclaveA, auxvalorA);
	}

	while (!isn.eof()) {
		isn >> auxclaveN;
		isn >> auxvalorN;
		if (auxclaveN != "" && auxvalorN != "")
			s.cargarNuevo(auxclaveN, auxvalorN);
	}

	s.compararNuevoConViejo(anadir, modificar);
	s.compararViejoConNuevo(quitar);

	std::sort(anadir.begin(), anadir.end());
	std::sort(quitar.begin(), quitar.end());
	std::sort(modificar.begin(), modificar.end());

	if (anadir.size() != 0) {
		std::cout << "+";
		for (int i = 0; i < anadir.size(); i++)
			std::cout << " " << anadir[i];

		std::cout << '\n';
	}

	if (quitar.size() != 0) {
		std::cout << "-";

		for (int i = 0; i < quitar.size(); i++)
			std::cout << " " << quitar[i];

		std::cout << '\n';

	}

	if (modificar.size()!=0){
		std::cout << "*";

		for (int i = 0; i < modificar.size(); i++)
			std::cout << " " << modificar[i];

		std::cout << '\n';
	}

	if (anadir.size() == 0 && quitar.size() == 0 && modificar.size() == 0) std::cout << "Sin cambios" << '\n';

	std::cout << "----" << '\n';
	



}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	std::cin.ignore(1);
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}