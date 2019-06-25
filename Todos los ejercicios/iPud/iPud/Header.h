//Grupo E29, Laura Jiménez Fernández y E63, Pablo de Torre Barrio
#ifndef Header_h
#define Header_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <vector>
#include <queue>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <exception>
#include <list>
#include "hashmap_eda.h"

using informacion = std::pair<std::string, int>;
using reproduccion = std::list<std::string>;
using recientes = std::list<std::string>;
using it = std::list<std::string>::iterator;

class canciones {
private:
	unordered_map<std::string, informacion> tabla;
	reproduccion listaRep;
	recientes listaRec;
	unordered_map<std::string, it> mapaRep;
	unordered_map<std::string, it> mapaRec; 
	int tiempoTotal=0;

public:
	canciones() {}

	void addSong(const std::string nombre, const std::string artista, int duracion) {
		if (tabla.contains(nombre))
			throw std::domain_error("ERROR addSong\n");
		else 
			tabla.insert({ nombre, {artista, duracion} });
	}

	void addToPlayList(const std::string nombre) {
		if (!tabla.contains(nombre)) 
			throw std::domain_error("ERROR addToPlaylist\n");
		if (!mapaRep.contains(nombre)) {
			listaRep.push_front(nombre);
			mapaRep.insert({nombre, listaRep.begin()});
			tiempoTotal += tabla[nombre].second;
		}
					
	}

	std::string current() {
		if (listaRep.empty())
			throw std::domain_error("ERROR current\n");
		return listaRep.back();
	}


	std::string play() {
		std::string sonando = "";
		if (!listaRep.empty()) {
			sonando = listaRep.back();
			listaRep.pop_back();
			mapaRep.erase(sonando);
			listaRec.push_front(sonando);
			if (mapaRec.contains(sonando)) {
				listaRec.erase(mapaRec[sonando]);
				mapaRec.erase(sonando);
			}
			mapaRec.insert({ sonando, listaRec.begin() });
			tiempoTotal -= tabla[sonando].second;
		}
		else {
			throw std::domain_error("No hay canciones en la lista\n");
		}
		return sonando;
	}

	int totalTime() {
		return tiempoTotal;
	}

	//Única función lque tiene coste lineal O(n)
	std::string recent(int n) {
		if (listaRec.empty()) throw std::domain_error("No hay canciones recientes\n");
		std::vector<std::string> aux;
		std::string elemento;
		it ite=listaRec.begin();

		std::string mostrar = "Las ";
		std::ostringstream num;
		num << n;
		mostrar += num.str();
		mostrar += " mas recientes\n";

		int i = 0;
		while (i < n && ite!=listaRec.end()) {
			//va cogiendo el valor de la dirección a la que apunta el puntero
			mostrar += "    " +*ite + '\n';
			++ite;
			i++;
		}

		return mostrar;
	}

	void deleteSong(const std::string nombre) {
		
		std::string elemento;
		std::vector<std::string> aux;
		if (tabla.contains(nombre)) {
			int t = tabla[nombre].second;
			tabla.erase(nombre);

			if (mapaRec.contains(nombre)) {
				listaRec.erase(mapaRec[nombre]);
				mapaRec.erase(nombre);
			}

			if (mapaRep.contains(nombre)) {
				listaRep.erase(mapaRep[nombre]);
				tiempoTotal -= t;
				mapaRep.erase(nombre);
			}
		}
	}

};


#endif