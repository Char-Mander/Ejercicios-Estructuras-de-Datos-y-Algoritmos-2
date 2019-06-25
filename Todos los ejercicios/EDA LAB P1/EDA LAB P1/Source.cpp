#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include "Horas.h"

typedef struct {
int h;
int min;
int seg;
}tHora;


void pasarHoras(std::vector<tHora> &trenes) {

}

bool resuelveCaso() {
	int numCasos, tratar;
	std::cin >> numCasos >> tratar;

	if (numCasos == 0 && tratar == 0) return false;
	else {
		std::vector<tHora>trenes(numCasos);

		for (int i = 0; i < numCasos) {
			pasarHoras(trenes);
		}


		return true;
	}




}

int main() {

	while (resuelveCaso())
		;

	return 0;
}