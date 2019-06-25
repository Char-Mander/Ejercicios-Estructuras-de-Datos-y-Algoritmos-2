// Grupo E63, Pablo de Torre Barrio
/*Comentario funcionamiento*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Header.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta

bool resuelveCaso() {
	// leer los datos de la entrada
	int numH, numP;
	std::cin >> numH >> numP;
	if (numH == 0 && numP == 0)
		return false;
	
	std::vector<hora> v(numH);
	for (hora & h : v)
		std::cin >> h;

	for (int i = 0; i < numP; ++i) {
		hora consulta;
		try {
			cin >> consulta;
			auto pos = lower_bound(v.begin(), v.end(), consulta);
			if (pos == v.end())
				std::cout << "NO\n";
			else
				std::cout << *pos << '\n';
		}
		catch (invalid_argument ia) {
			std::cout << ia.what();
		}
	}
	std::cout << "---\n";

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