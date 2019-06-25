#ifndef Header_h
#define Header_h
#include "hashmap_eda.h"
#include "treemap_eda.h"
#include <list>

using libro = std::string;
using iterator = std::list<std::string>::iterator;
using informacion = std::pair<int, int>;

class libros {
private:

	unordered_map<libro, informacion> tabla;
	unordered_map<libro, iterator> infoLib; //guarda el nombre del libro y el iterador en el mapa de Ventas
	map<int, std::list<libro>> mapaVentas;
	int max;

public: 
	libros() {}

	void nuevoLibro(int ejemplares,const std::string libro) {
		if (!tabla.contains(libro)) {
			tabla.insert({libro, {ejemplares, 0}});
		}
		else {
			tabla[libro].first = ejemplares;
		}
	}

	void comprar(const std::string libr) {
		if (!tabla.contains(libr)) throw std::invalid_argument("Libro no existente\n");
		else if (tabla[libr].first == 0) throw std::out_of_range("No hay ejemplares\n");
		else {
			--tabla[libr].first;
			++tabla[libr].second;
			if (!infoLib.contains(libr)) {
				if (!mapaVentas.contains(1)) {
					max = 1;
					std::list<libro> li;
					mapaVentas.insert({ 1, li });
				}
				mapaVentas[1].push_front(libr);
				infoLib.insert({ libr, mapaVentas[1].begin() });
			}
			else {
				if (!mapaVentas.contains(tabla[libr].second)) {
					max = tabla[libr].second;
					std::list<libro>li;
					mapaVentas.insert({ tabla[libr].second, li});
				}
				mapaVentas[tabla[libr].second].push_front(libr);
				mapaVentas[tabla[libr].second - 1].erase(infoLib[libr]); //accede al iterador y lo borra
				infoLib[libr] = mapaVentas[tabla[libr].second].begin(); // pone su iterador al principio de la lista de los vendidos (de su número)
			}
		}
	}


	bool estaLibro(const std::string libro) {
		if (tabla.contains(libro)) return true;
		else return false;
	}

	void elimLibro(const std::string libro) {
		if (tabla.contains(libro)) {
			if (infoLib.contains(libro)) {
				mapaVentas[tabla[libro].second].erase(infoLib[libro]);
				infoLib.erase(libro);
			}

			tabla.erase(libro);
		}
	}

	int numEjemplares(const std::string libro) {
		if (!tabla.contains(libro)) throw std::invalid_argument("No existe el libro " + libro + " en el sistema ");
		else return tabla[libro].first;
	}
	

	std::vector<std::string> top10() {
		std::vector<std::string> top;
		int i = 0, j = max;
		while (i < 10 && j>0) {
			auto lis = mapaVentas[j].begin();
			while (i < 10 && lis != mapaVentas[j].end()) {
				top.push_back(*lis);
				i++;
				++lis;
			}
			j++;
		}
	}
};
#endif 
