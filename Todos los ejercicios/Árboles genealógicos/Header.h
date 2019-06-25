// Grupo E29, Laura Jiménez Fernández
// Grupo E63, Pablo de Torre Barrio
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
bintree<T> cargarArbol(T const& dato, int altura, int & altMax) {
	T raiz;
	std::cin >> raiz;

	if (raiz == dato)
		return{};
	else {
		bintree<T> izq = cargarArbol(dato, altura + 1, altMax);
		bintree<T> der = cargarArbol(dato, altura + 1, altMax);
		if (izq.empty() && der.empty()) {
			if (altura >= altMax)
				altMax = altura + 1;
		}
		return{ izq, raiz, der };
	}
}


//El problema se va resolviendo de abajo a arriba, de las hojas a la raiz
template <class T>
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

	}
}
#endif //Header_h

