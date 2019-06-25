#ifndef Header_h
#define Header_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include "bintree_eda.h"

template <class T>
bintree<T> cargarArbol(T const& dato, const std::string &arbol, int &contador) {
	T raiz;
	if (contador > 0) {
		raiz = arbol.at(contador);

		if (raiz == dato)
			return{};
		else {
			contador--;
			bintree<T> izq = cargarArbol(dato, arbol, contador);
			bintree<T> der = cargarArbol(dato, arbol, contador);

			return{ izq, raiz, der };
		}
	}
	else return{};
}


//El problema se va resolviendo de abajo a arriba, de las hojas a la raiz
template <class T>
bool resolver(bintree<T> const& arbol, T const &dato, int &numAdornos) {

	if (arbol.empty())
		numAdornos=0;
	else {
		if (arbol.root() == '*') numAdornos++;
		int numDer=0, numIzq=0;
		bool okizq, okder;
			okizq=resolver(arbol.left(), dato, numIzq);
			okder=resolver(arbol.right(), dato, numDer);
		//	numAdornos = numDer + numIzq;
			if ((numDer > 1 && numIzq > 1 && abs(numIzq - numDer) > 1) || (numDer == 0 && numIzq > 1) || (numIzq == 0 && numDer > 1)) {
				
				return false;

			}
			else {
				numAdornos = numDer + numIzq;
				if (okder && okizq) return true;
				else return false;
			}


			
	}
}


#endif //Header_

#pragma once
