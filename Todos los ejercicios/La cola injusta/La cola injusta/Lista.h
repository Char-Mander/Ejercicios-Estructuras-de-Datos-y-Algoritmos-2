//Laura Jiménez Fernández, E29
//Pablo de Torre Barrio, E63
#ifndef Lista_h
#define Lista_h

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "queue.h"


template <class T>
class lista : public queue<T> {
	using Nodo = typename queue <T>::Nodo;
public:
	lista() {}
	~lista() {}


	void mostrar() const {
		Nodo* mostrar = this->prim;
		std::cout << "{";
		for (int i = 0; i < this->nelems; i++) {
			std::cout << mostrar->elem;
			if(i!=this->nelems-1) std::cout << ",";
			mostrar = mostrar->sig;
		}
		std::cout << "}" << '\n';

	}


};

#endif //Lista_h

