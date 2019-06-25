//Laura Jiménez Fernández, E29 y Pablo de Torre Barrio, E63
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Stack.h"
using namespace std;




bool resuelveCaso() { 
	string frase;
	getline(cin, frase);
	if (frase.length() == 0) return false;
	
	stack<char> pila;
	bool ok = true;

	int i = 0;
	char parentesis;
	while (ok && i < frase.length()) {
		
		switch (frase.at(i)) {
		case '(':  pila.push(frase.at(i)); break;
		case '[':  pila.push(frase.at(i)); break;
		case '{':  pila.push(frase.at(i)); break;
		case ')': if (!pila.empty()) {
						if (pila.top() != '(') ok = false;
					pila.pop();
				  }
				  else ok = false; break;
		case ']': if (!pila.empty()) {
						if (pila.top() != '[') ok = false;
					pila.pop();
				  }
				  else ok = false; break;

		case '}': if (!pila.empty()) {
						if (pila.top() != '{') ok = false;
					pila.pop();
				  }
				  else ok = false; break;

		}
		i++;
	}



	if (ok) cout << "YES";
	else cout << "NO";
	cout << '\n';


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