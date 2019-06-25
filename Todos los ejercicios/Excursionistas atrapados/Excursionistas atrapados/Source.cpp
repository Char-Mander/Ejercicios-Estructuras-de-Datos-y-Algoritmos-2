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
//#include "Header.h"
#include "Header1.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta


void resuelveCaso() {
	// leer los datos de la entrada
	/*int numCaminos = 0, maxPringaos = 0, numPringaos = 0;
	bintree<int> arbol = siguienteHijo(-1, numCaminos, maxPringaos, numPringaos);
	std::cout << numCaminos << " " << maxPringaos << '\n';*/

	int numCaminos = 0, maxPringaos = 0;
	bintree<int> arbol = cargarArbol(-1);
	resolver(arbol, maxPringaos, numCaminos);
	std::cout << numCaminos << " " << maxPringaos << '\n';

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