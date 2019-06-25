//Grupo E29, Laura Jiménez Fernández y E63, Pablo de Torre Barrio
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "hashmap_eda.h"
#include "Header.h"

/* Describir lo que hace la función */


/* Coste de la función */


bool resuelveCaso() {

	std::string linea;
	std::cin >> linea;

	if (!std::cin)
		return false;

	deportes dep;
	std::string depAct;
	while (linea != "_FIN_") {
		if (dep.esDeporte(linea)) {
			dep.anadirDeporte(linea);
			depAct = linea;
		}
		else if (!dep.alumnoRepetido(depAct, linea))
			dep.anadirAlumno(depAct, linea);
		std::cin >> linea;
	}

	dep.mostrar();
	std::cout << "***\n";
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}