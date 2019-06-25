//Laura Jiménez Fernández, E29
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

//using namespace std;


template <class T>
class queue {

public:

	// constructor: cola vacía
	queue() : prim(nullptr), ult(nullptr), nelems(0) {}

	// destructor
	~queue() {
		libera(); prim = ult = nullptr;
	}

	// constructor por copia
	queue(queue<T> const& other) : prim(nullptr), ult(nullptr) {
		copia(other);
	}

	// operador de asignación
	queue<T> & operator=(queue<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// añadir un elemento al final de la cola
	void push(T const& elem) {
		Nodo* nuevo = new Nodo(elem, nullptr);

		if (ult != nullptr)
			ult->sig = nuevo;
		ult = nuevo;
		if (prim == nullptr) // la cola estaba vacía
			prim = nuevo;
		++nelems;
	}

	// consultar el primero de la cola
	T const& front() const {
		if (empty())
			throw std::domain_error("la cola vacia no tiene primero");
		return prim->elem;
	}

	// eliminar el primero de la cola
	void pop() {
		if (empty())
			throw std::domain_error("eliminando de una cola vacia");
		Nodo* a_borrar = prim;
		prim = prim->sig;
		if (prim == nullptr) // la cola se ha quedado vacía
			ult = nullptr;
		delete a_borrar;
		--nelems;
	}

	// consultar si la cola está vacía
	bool empty() const {
		return nelems == 0;
	}

protected:

	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente, que puede ser nullptr si
	el nodo es el último de la lista enlazada.
	*/
	struct Nodo {
		Nodo() : sig(nullptr) {}
		Nodo(T const& elem, Nodo* si = nullptr) : elem(elem), sig(si) {}
		T elem;
		Nodo* sig;
	};

	// punteros al primer y último elemento
	Nodo* prim;
	Nodo* ult;

	// número de elementos en la cola
	size_t nelems;

	void libera() {
		while (prim != nullptr) {
			Nodo* aux = prim;
			prim = prim->sig;
			delete aux;
		}
	}

	void copia(queue const& other) {
		if (other.empty()) {
			prim = ult = nullptr;
			nelems = 0;
		}
		else {
			Nodo* act = other.prim;
			Nodo* ant;
			prim = new Nodo(act->elem);
			ant = prim;
			while (act->sig != nullptr) {
				act = act->sig;
				ant->sig = new Nodo(act->elem);
				ant = ant->sig;
			}
			ult = ant;
			nelems = other.nelems;
		}
	}
};




void resuelveCaso() {
	queue<std::string> nombres;
	std::string nom;
	std::cin >> nom;
	std::string primElem = nom;
	int i = 0;
	while (nom != "F") {
		i++;
		nombres.push(nom);
		std::cin >> nom;
	}
	
	int nElementos = i;
	int camasD, nPalabras;
	std::cin >> camasD >> nPalabras;
	int j = 1;
	
	while (i != camasD) {
		std::string aux = nombres.front();
		nombres.pop();
		i--;
		if (j != nPalabras) {
			nombres.push(aux); 
			i++;
			j++;
		}
		else j = 1;
		
	}

	if (!nombres.empty()) {
		while (nombres.front() != primElem) {
			 std::string aux = nombres.front();
			nombres.pop();
			nombres.push(aux);
		}
	}

	if (i == nElementos) std::cout << "TODOS TIENEN CAMA";
	else if (nombres.empty()) std::cout << "NADIE TIENE CAMA";
	else { 
		while (!nombres.empty()) {
			std::cout << nombres.front() << " ";
			nombres.pop();
		}
	}
	std::cout << '\n';

}



int main() {



	int numCasos;
	std::cin >> numCasos; 

	for (int i = 0; i < numCasos; i++)
		resuelveCaso();



	return 0;
}
