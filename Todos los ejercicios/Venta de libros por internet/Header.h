//Grupo E29, Laura Jiménez Fernández y E63, Pablo de Torre Barrio
#ifndef Header_h
#define Header_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <exception>
#include "deque_eda.h"
#include <list>
#include "hashmap_eda.h"
#include "treemap_eda.h"

using libro = std::string;

typedef struct {
	int ejemplares;
	int vendidos;
}tInformacion;

using iterator = std::list<libro>::iterator;
class libros {
private:
	unordered_map<libro, tInformacion> tabla;
	unordered_map<libro, iterator> infoLib;
	map<int, std::list<libro>> mapaV;
	int max;
public:
	libros() {}

	//Coste constante
	void addLibro(int ejemplares, const libro nombre) {
		if (tabla.contains(nombre)) 
			tabla[nombre].ejemplares += ejemplares;
		else 
			tabla.insert({ nombre, {ejemplares, 0} });
	}

	//Coste lineal respecto al tamano del vector
	void comprar(const libro nombre) {
		if (!tabla.contains(nombre))
			throw std::invalid_argument("Libro no existente\n");
		if (tabla[nombre].ejemplares==0) 
			throw std::out_of_range("No hay ejemplares\n");

		--tabla[nombre].ejemplares;
		++tabla[nombre].vendidos;


		if (!infoLib.contains(nombre)) {
			if (!mapaV.contains(1)) {
				max = 1;
				std::list<libro> l;
				mapaV.insert({ 1, l });
			}
			mapaV[1].push_front(nombre);
			infoLib.insert({ nombre, mapaV[1].begin() });
		}
		else {
			if (!mapaV.contains(tabla[nombre].vendidos)) {
				max = tabla[nombre].vendidos;
				std::list<libro> l;
				mapaV.insert({ tabla[nombre].vendidos, l });
			}
			mapaV[tabla[nombre].vendidos].push_front(nombre);
			mapaV[tabla[nombre].vendidos - 1].erase(infoLib[nombre]);
			infoLib[nombre] = mapaV[tabla[nombre].vendidos].begin();
		}
	}

	//Coste constante
	bool estaLibro(const libro nombre) {
		return tabla.contains(nombre);
	}

	//Coste lineal respecto al tamano del vector
	void elimLibro(const libro nombre) {
		if (tabla.contains(nombre)) {

			mapaV[tabla[nombre].vendidos].erase(infoLib[nombre]);
			infoLib.erase(nombre);
			tabla.erase(nombre);
		}
	}

	//Coste constante
	int numEjemplares(const libro nombre) {
		if (!tabla.contains(nombre)) throw std::invalid_argument("No existe el libro " + nombre + " en el sistema\n");
		return tabla[nombre].ejemplares;
	}

	//Coste constante
	std::vector<libro> top10() {
		std::vector<libro> top;
		int i = 0, j = max;
		while (i < 10 && j > 0) {
			auto li = mapaV[j].begin();
			while (i < 10 && li != mapaV[j].end()) {
				top.push_back(*li);
				i++;
				++li;
			}
			--j;
		}
		return top;
	}
};


#endif