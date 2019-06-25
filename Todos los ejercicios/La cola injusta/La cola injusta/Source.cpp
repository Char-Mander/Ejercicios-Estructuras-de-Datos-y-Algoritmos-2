//Laura Jiménez Fernández, E29
//Pablo de Torre Barrio, E63
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "queue.h"
#include "Lista.h"
using namespace std;

void resuelveCaso() {
	lista<int> cola;
	int n, tam_cola = 0;
	cin >> n;
	
	while (n != -1) {
		tam_cola++;
		cola.push(n);
		cin >> n;
	}

	queue<int>amigos;
	int pringado; 
	cin >> pringado;

	cin >> n;
	int tam_amigos = 0;
	while (n != -1) {
		amigos.push(n);
		tam_amigos++;
		cin >> n;
	}
	int cont = tam_amigos;

	cola.mostrar();

	int aux, elemrec= 0;
	if (!amigos.empty() > 0 && pringado<=tam_cola) {
		while (!amigos.empty()) { 
			aux = cola.front();
			if (cont != tam_amigos) { //si ya se ha cogido algún elemento de amigos
				cola.push(amigos.front());
				amigos.pop();
				cont--;
			}
			else if (aux != pringado) { //si el primer elemento de la cola no es el pringado
				aux = cola.front();
				cola.pop();
				cola.push(aux);
				elemrec++;
			}
			else  { //si el primer elemento de la cola es el pringado
				cola.pop();
				cola.push(aux);
				cola.push(amigos.front());
				amigos.pop();
				cont--;
				elemrec++;
			}

			
		}

		for (int k = 0; k < (tam_cola - elemrec); k++) { //mete los elementos restantes
			aux = cola.front();
			cola.pop();
			cola.push(aux);
		}

	}
	

	
	
	cola.mostrar();

}



int main() {


#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) resuelveCaso();

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
