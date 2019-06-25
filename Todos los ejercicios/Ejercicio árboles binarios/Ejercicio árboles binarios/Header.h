#ifndef Header_h
#define Header_h 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include "bintree_eda.h"

template <class T>
bintree<T>cargarArbol(T const &dato) {
	T raiz;
	cin >> raiz;
	if (raiz == dato) return{};
	else {

		bintree<T> izq = cargarArbol(dato);
		bintree<T> der = cargarArbol(dato);

		return{ izq, raiz, der };
	}

}

template <class T>
bool resolver(const bintree<T> &arbol, int &numTramos, int &caudal) {
	if (arbol.root().empty) return false;
	else {
		int c = 1;
		int ci, cd;
		resolver(arbol.left(), numTramos, ci);
		resolver(arbol.right(), numTramos, cd);

		if (!arbol.left().empty() && !arbol.right().empty()) c = (ci + cd) + arbol.root(); //se suma ya que la raíz o es 0, o negativa
		else if (!arbol.left().empty()) c = ci + arbol.root();
		else if (!arbol.right().empty()) c = ci + arbol.root();

		if (c >= 3) numTramos++;

		if (c < 0) c = 0;

	}

}
#endif // Header_h