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
	int ntrenes, nconsultas;
	cin >> ntrenes >> nconsultas;
	if (ntrenes == 0) return false;
	vector<horas> trenes(ntrenes);
	for (horas &h : trenes)
		cin >> h;

	for (int i = 0; i < nconsultas; i++) {
		horas consulta;
		try {
			cin >> consulta;
			auto pos = lower_bound(trenes.begin(), trenes.end(), consulta);
			if (pos == trenes.end()) cout << "NO \n";
			else cout << *pos << '\n';
		}
			catch (invalid_argument ia) {
				cout << ia.what();
			}
		
	}
	cout << "--- \n";
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