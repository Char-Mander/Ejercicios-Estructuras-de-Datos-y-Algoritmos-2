//Laura Jiménez Fernández, E29 y Pablo de Torre Barrio, E63
//  stack_eda.h
//
//  Implementación del TAD pila con array dinámico
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Created by Alberto Verdejo on 6/12/16.
//  Copyright (c) 2016 Alberto Verdejo. All rights reserved.
//

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

template <class T>
class stack {
	static const int TAM_INICIAL = 10; // tamaño inicial del array dinámico
public:

	// constructor: pila vacía
	stack() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

	// destructor
	~stack() {
		libera();
	}

	// constructor por copia
	stack(stack<T> const& other) {
		copia(other);
	}

	// operador de asignación
	stack<T> & operator=(stack<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// apilar un elemento
	void push(T const& elem) {
		if (nelems == capacidad)
			amplia();
		array[nelems] = elem;
		++nelems;
	}

	// consultar la cima
	T const& top() const {
		if (empty())
			throw std::domain_error("la pila vacia no tiene cima");
		return array[nelems - 1];
	}

	// desapilar el elemento en la cima
	void pop() {
		if (empty())
			throw std::domain_error("desapilando de la pila vacia");
		--nelems;
	}

	// consultar si la pila está vacía
	bool empty() const {
		return nelems == 0;
	}

protected:

	// número de elementos en la pila
	size_t nelems;

	// tamaño del array
	size_t capacidad;

	// puntero al array que contiene los datos
	T * array;

	void libera() {
		delete[] array;
		array = nullptr;
	}

	void copia(stack const& other) {
		capacidad = other.nelems;
		nelems = other.nelems;
		array = new T[capacidad];
		for (size_t i = 0; i < nelems; ++i)
			array[i] = other.array[i];
	}

	void amplia() {
		T * viejo = array;
		capacidad *= 2;
		array = new T[capacidad];

		for (size_t i = 0; i < nelems; ++i)
			array[i] = std::move(viejo[i]);

		delete[] viejo;
	}

};

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



	if (ok && pila.empty()) cout << "YES";
	else cout << "NO";
	cout << '\n';


	return true;
}



int main() {


	while (resuelveCaso())
		;


	return 0;
}
