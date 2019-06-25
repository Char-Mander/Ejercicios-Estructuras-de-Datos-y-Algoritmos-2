//Laura Jiménez Fernández, E29
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Header.h"
#include "Peliculas.h"
using namespace std;



bool resuelveCaso() {
	int nPelis;
	cin >> nPelis;
	if (nPelis == 0) return false;
	
		
		vector<peliculas> peli(nPelis);

		for (peliculas &p : peli)
			cin >> p;
		
		sort(peli.begin(), peli.end());

		for (peliculas const &p : peli)
			cout << p << '\n';

		cout << "---" << '\n';

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