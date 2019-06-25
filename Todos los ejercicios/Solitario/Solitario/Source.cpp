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
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <stdexcept>

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

	size_t getNElems() const { return nelems; }

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

typedef struct {
	char palo;
	int num;
}tCarta;

//Segun el palo de la carta, se compara si la carta anterior esta colocada. En caso afirmativo, se coloca devolviemdo true
bool insertar(tCarta carta, stack<int> & pilaO, stack<int> & pilaC, stack<int> & pilaE, stack<int> & pilaB) {

	bool ok = true;
	switch (carta.palo) {
	case 'O':
		if (carta.num == 1)
			pilaO.push(carta.num);
		else if (!pilaO.empty()) {
			if (((carta.num > 1 && carta.num <= 7) || (carta.num > 10 && carta.num <= 12))
				&& carta.num == pilaO.top() + 1)
				pilaO.push(carta.num);
			else if (carta.num == 10 && pilaO.top() == 7)
				pilaO.push(carta.num);
			else ok = false;
		}
		else ok = false;
		break;
	case 'C':
		if (carta.num == 1)
			pilaC.push(carta.num);
		else if (!pilaC.empty()) {
			if (((carta.num > 1 && carta.num <= 7) || (carta.num > 10 && carta.num <= 12))
				&& carta.num == pilaC.top() + 1)
				pilaC.push(carta.num);
			else if (carta.num == 10 && pilaC.top() == 7)
				pilaC.push(carta.num);
			else ok = false;
		}
		else ok = false;
		break;
	case 'E':
		if (carta.num == 1)
			pilaE.push(carta.num);
		else if (!pilaE.empty()) {
			if (((carta.num > 1 && carta.num <= 7) || (carta.num > 10 && carta.num <= 12))
				&& carta.num == pilaE.top() + 1)
				pilaE.push(carta.num);
			else if (carta.num == 10 && pilaE.top() == 7)
				pilaE.push(carta.num);
			else ok = false;
		}
		else ok = false;
		break;
	case 'B':
		if (carta.num == 1) pilaB.push(carta.num);
		else if (!pilaB.empty()) {
			if (((carta.num > 1 && carta.num <= 7) || (carta.num > 10 && carta.num <= 12))
				&& carta.num == pilaB.top() + 1)
				pilaB.push(carta.num);
			else if (carta.num == 10 && pilaB.top() == 7)
				pilaB.push(carta.num);
			else ok = false;
		}
		else ok = false;
		break;
	default: return false;
	}
	return ok;
}

bool resolver(stack<tCarta> & pilaSacar, stack<tCarta> & pilaPoner, stack<int> & pilaO,
	stack<int> & pilaC, stack<int> & pilaE, stack<int> & pilaB) {
	bool gana = true;
	int numEl;
	while (gana && !pilaSacar.empty()) {//Este bucle representa todas las vueltas del mazo
		numEl = pilaSacar.getNElems();
		while (!pilaSacar.empty()) {//Este bucle representa UNA vuelta del mazo
									//Se sacan las cartas
			pilaPoner.push(pilaSacar.top());
			pilaSacar.pop();
			if (!pilaSacar.empty()) {
				pilaPoner.push(pilaSacar.top());
				pilaSacar.pop();
			}
			while (!pilaPoner.empty()&& insertar(pilaPoner.top(), pilaO, pilaC, pilaE, pilaB)) {
				//En este bucle se colocan las cartas que sean posibles
				pilaPoner.pop();
			}
		}
		if (numEl == pilaPoner.getNElems())gana = false; //Si las cartas al dar la vuelta al mazo 
															 //son iguales que antes de sacar las cartas la partida ha sido fallida
		
		else {
			//Se da la vuelta al mazo
			while (!pilaPoner.empty()) {
				pilaSacar.push(pilaPoner.top());
				pilaPoner.pop();
			}
		}
	}

	return gana;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	stack<tCarta> pilaSacar, pilaPoner;
	stack<int> pilaO, pilaC, pilaE, pilaB;

	int n;
	std::cin >> n;
	if (n == 0)
		return false;
	tCarta aux;
	std::vector<tCarta> v(n * 10);
	for (int i = 0; i < n * 10; i++) {
		std::cin >> aux.num;
		std::cin >> aux.palo;
		v[i] = aux;
	}

	for (int i = n * 10 - 1; i >= 0; --i) {
		pilaSacar.push(v[i]);
	}

	if (resolver(pilaSacar, pilaPoner, pilaO, pilaC, pilaE, pilaB)) std::cout << "GANA";
	else std::cout << "PIERDE";

	std::cout << '\n';
	// escribir sol

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto

	while (resuelveCaso())
		;

	return 0;
}