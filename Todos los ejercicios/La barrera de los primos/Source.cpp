// Grupo E29, Laura Jiménez Fernández
// Grupo E63, Pablo de Torre Barrio
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <set>
#include "Header.h"


void resuelveCaso() {
	// leer los datos de la entrada
	int altura = 0;
	bintree<int> arbol = cargarArbol(-1, 0, altura);
	int multiplo = 0, profundidad = altura + 1;
	resolver(arbol, multiplo, 1, profundidad, profundidad);

	if (multiplo != 0)
		std::cout << multiplo << ' ' << profundidad << '\n';
	else
		std::cout << "NO HAY\n";
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