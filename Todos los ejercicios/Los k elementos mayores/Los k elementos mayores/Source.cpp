//Laura Jiménez Fernández, E29
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Header.h"
using namespace std;



bool resuelveCaso() {
	char tipo;
	long int k;
	cin >> tipo >> k;
	bool end = false;


	if (!cin) return false;
	
	if (tipo == 'P') {
		conjunto<string> co;
		string n;
		cin >> n;
		if (n == "FIN") end = true;
		while (!end) {
			co.anadirElementos(n);
			cin >> n;
			if (n == "FIN") {
				co.ordena();
				end = true;
			}
		}
		co.kMayores(k);
		cout << '\n';
	}
	else {
		conjunto<int> co;
		long int n;
		cin >> n;
		while (!end) {
			co.anadirElementos(n);
			cin >> n;
			if (n == -1) {
				co.ordena();
				end = true;
			}
		}
		co.kMayores(k);
		cout << '\n';
	}

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