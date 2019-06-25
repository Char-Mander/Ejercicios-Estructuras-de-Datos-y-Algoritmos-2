//Laura Jiménez Fernández, E29
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Complejo.h"
using namespace std;

//La funciun que resuelve el caso es recursiva, y comprueba primero si el mudulo de co es mayor que dos.
//de serlo, devolvería false, por lo que se escribiría "NO". 
//Si no, se comprueba la iteraciun por la que va. De ser la ultima, devolvería true, escribiendo "SI".
//Si no, llama a resolver con una iteracion mas, y co=(co*co)+ac
bool resolver(conjunto<float>const &co, conjunto<float> const &ac,int iteraciones, int cont) {
	if (co.mod() > 2) return false;
	else if (iteraciones==cont) return true;
	else return resolver(((co*co) + ac), ac, iteraciones, cont+1);
}

void resuelveCaso() {
	conjunto<float> co;
	conjunto<float> ac;
	int iteraciones;

	cin >> ac >> iteraciones;


	if (resolver(co, ac, iteraciones, 0)) cout << "SI";
	else cout << "NO";

	cout << '\n';

}



int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) { resuelveCaso(); }
	

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}