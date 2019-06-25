// Grupo E29, Laura Jiménez Fernández
// Grupo E63, Pablo de Torre Barrio
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include "Header.h"

//Función que resuelve el problema. Tiene coste lineal O(n), pues simplemente recorre el árbol una vez
bool resuelveCaso() {
	// leer los datos de la entrada
	char n;
	std::cin >> n;
	if (!std::cin) return false;

	int cont = 0;

	if (n == 'P') {
		std::string min = "", vacio = "#";
		bintree<std::string> arbol = siguienteHijo(vacio, min, cont);
		std::cout << min; 
	}
	else {
		
		int min = -1;
		bintree<int> arbol = siguienteHijo(-1, min, cont);
		std::cout << min;
	}

	std::cout << '\n';

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