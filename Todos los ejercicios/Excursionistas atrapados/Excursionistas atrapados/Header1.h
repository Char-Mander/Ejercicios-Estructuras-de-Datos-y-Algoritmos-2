#ifndef Header1_h
#define Header1_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include "bintree_eda.h"

template <class T>
bintree<T> cargarArbol(T const& dato) {
	T raiz;
	std::cin >> raiz;

	if (raiz == dato)
		return{};
	else {
		bintree<T> izq = cargarArbol(dato);

		bintree<T> der = cargarArbol(dato);
		return{ izq, raiz, der };
	}
}

void resolver(bintree<int> const & arbol, int &maxPringaos, int &numCaminos) {

	if(arbol.empty()){
		maxPringaos = numCaminos = 0;
	}
	else {
		maxPringaos = arbol.root();
		int max_izq, max_der, eq_izq, eq_der;
		resolver(arbol.left(), max_izq, eq_izq);
		resolver(arbol.right(), max_der, eq_der);
		if (max_izq > max_der)
			maxPringaos += max_izq;
		else
			maxPringaos += max_der;
		if (arbol.root() > 0 && eq_izq == 0 && eq_der == 0)
			numCaminos= 1;
	}





}

#endif //Header1_h
#pragma once

