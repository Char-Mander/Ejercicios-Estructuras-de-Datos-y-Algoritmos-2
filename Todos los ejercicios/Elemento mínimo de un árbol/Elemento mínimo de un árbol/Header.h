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
bintree<T> siguienteHijo(T const& dato) {
	T raiz;
	std::cin >> raiz;

	if (raiz == dato)
		return{};
	else {
		bintree<T> izq = siguienteHijo(dato);
		bintree<T> der = siguienteHijo(dato);

		return{ izq, raiz, der };
	}
}


#endif //Header_h
#pragma once
