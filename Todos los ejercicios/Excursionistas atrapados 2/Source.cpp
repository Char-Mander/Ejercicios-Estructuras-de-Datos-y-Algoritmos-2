// Grupo E29, Laura Jim�nez Fern�ndez
// Grupo E63, Pablo de Torre Barrio
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Header.h"


void resuelveCaso() {
	// leer los datos de la entrada

	bintree<int> arbol = cargarArbol(-1);
	int numPringaos = 0, equipos = 0;
	resolver(arbol, numPringaos, equipos);

	std::cout << equipos << ' ' << numPringaos << '\n';
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}