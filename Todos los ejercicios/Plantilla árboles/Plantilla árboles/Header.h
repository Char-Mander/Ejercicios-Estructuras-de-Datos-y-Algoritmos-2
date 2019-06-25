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


//El problema se va resolviendo de abajo a arriba, de las hojas a la raiz
template <class T>
void resolver(bintree<T> const& arbol, int &caudal, int &numTramos) {

	if (arbol.empty())
		caudal = 0;
	else {

		caudal = 1;
		int cauder, cauizq;
		resolver(arbol.left(), cauizq, numTramos);
		resolver(arbol.right(), cauder, numTramos);

		/*Si tiene tanto hijo izquierdo como hijo derecho, el caudal será la suma de los caudales de sus hijos
		menos el tamaño del embalse.
		Si solo tiene hijo izquierdo, el caudal será solo la suma del caudal del hijo izquierdo menos el tamaño del embalse.
		Si solo tiene hijo derecho, el caudal será solo la suma del caudal del hijo derecho menos el tamaño del embalse.
		Si no tiene hijos, el caudal será 1. */
		if (!arbol.left().empty() && !arbol.right().empty())
			caudal = (cauder + cauizq) - arbol.root();
		else if (!arbol.left().empty()) caudal = cauizq - arbol.root();
		else if (!arbol.right().empty()) caudal = cauder - arbol.root();


		//Si el caudal es mayor o igual que 3, se añade otro tramo navegable.
		if (caudal >= 3) numTramos++;

		if (caudal < 0) caudal = 0;
	}

	//El problema se va resolviendo de abajo a arriba, de las hojas a la raiz
	/*template <class T>
	bool resolver(bintree<T> const& arbol) {

		if (arbol.empty())
			return true;
		else {

			bool iz = resolver(arbol.left());
			bool der = resolver(arbol.right());
			if (!arbol.left().empty() && !arbol.right().empty())
				return ((arbol.root() - arbol.left().root() >= 18) && (arbol.root() - arbol.left().root() >= 18) && (arbol.left().root() - arbol.right().root() >= 2) && iz && der);
			else if (!arbol.left().empty())
				return ((arbol.root() - arbol.left().root() >= 18) && iz);
			else if (!arbol.right().empty())
				return false;
			else return true;

		}*/
}


#endif //Header_h
#pragma once


