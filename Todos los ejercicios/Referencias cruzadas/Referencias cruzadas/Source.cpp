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
#include "treemap_eda.h"
#include "Header.h"

/* Describir lo que hace la función */


/* Coste de la función */

void a_minusculas(std::string & s) {
	for (char & c : s)
		if ('A' <= c &&c <= 'Z') c = 'a' + (c - 'A');
}


bool resuelveCaso() {

	int numFrases;
	std::cin >> numFrases;

	if (numFrases == 0) return false;
	std::cin.ignore(1);
	palabras p;
	std::string frase;
	std::string auxP = "";

	for (int i = 0; i < numFrases; i++) {
		getline(std::cin, frase);
		std::istringstream isa(frase);
		while (!isa.eof()) {
			isa >> auxP;
			if (auxP != "" && auxP.length()>2) {
				a_minusculas(auxP);
				p.anadirPalabras(auxP, i+1);
			}
		}
		auxP = "";
	}

	p.mostrar();
	std::cout << "----" << '\n';
	return true;
}

int main(){
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