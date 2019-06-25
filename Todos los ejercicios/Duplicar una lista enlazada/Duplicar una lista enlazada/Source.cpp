//Laura Jiménez Fernández, E29
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
#include "queue_eda.h"
#include "Lista.h"
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) return false;

	lista<int> l;
	while (n != 0) {
		l.push(n);
		cin >> n;
	}

	l.invertir();
	l.mostrar();

	return true;
}



int main() {


#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


	while (resuelveCaso())
		;

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
