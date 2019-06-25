//Laura Jiménez Fernández, E29
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
#include "queue_eda.h"


template <class T>
class lista : public queue<T> {
	using Nodo = typename queue <T>::Nodo;
public:
	lista() {}
	~lista() {}

	void invertir() {
		Nodo *anterior = nullptr;
		Nodo *siguiente = this->prim;
	
		for (int i = 0; i < this->nelems; i++) {
			Nodo *aux = siguiente->sig; 
			siguiente->sig = anterior;
			anterior = siguiente;
			siguiente = aux;
		}

		std::swap(this->prim, this->ult);
	}

	void mostrar() const {
		Nodo* mostrar = this->prim;
		for (int i = 0; i < this->nelems; i++) {
			std::cout << mostrar->elem << " ";
			mostrar = mostrar->sig;
		}
		std::cout << '\n';
	}


};

#endif //Lista_h
