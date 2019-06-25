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

//Función que resuelve el problema. Tiene coste lineal O(n), pues simplemente recorre el árbol una vez, y 
//en el caso de que fueran hojas, las almacena en un vector (y se mostrarán al final)
void resuelveCaso() {
	// leer los datos de la entrada
	std::vector<int>v;
	bintree<int> arbol = siguienteHijo(-1, v);

	for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";

	std::cout << '\n';

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
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}