//Laura Jiménez Fernández, E29
#include <iostream>
#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Header.h"


bool resuelveCaso() {
	polinomio v;
	try {
		std::cin >> v;
	}
	catch (std::invalid_argument) { return false; }
	
	int n, num;
	std::cin >> n;
	while (n > 0) {
		std::cin >> num;
		std::cout << v.calcula(num) << " ";
		n--;
	}

	std::cout << '\n';

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