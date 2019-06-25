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
#include <set>
#include "bintree_eda.h"


bool primo(int n) {
	for (int i = 2; i <= n / 2; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

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
void resolver(bintree<T> const& arbol, int & multiplo, int prof, int & minProf, int altura) {

	if (!arbol.empty() && !primo(arbol.root())) {

		if (arbol.root() % 7 == 0) {
			minProf = prof;
			multiplo = arbol.root();
		}
		else {
			int m_iz, m_dr, p_iz, p_dr;
			resolver(arbol.left(), m_iz, prof + 1, p_iz, altura);
			resolver(arbol.right(), m_dr, prof + 1, p_dr, altura);

			if (p_iz <= p_dr) {
				multiplo = m_iz;
				minProf = p_iz;
			}
			else {
				multiplo = m_dr;
				minProf = p_dr;
			}
		}
	}
	else {
		multiplo = 0;
		minProf = altura;
	}
}
#endif //Header_h

