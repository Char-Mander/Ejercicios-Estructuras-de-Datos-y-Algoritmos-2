//Grupo E29, Laura Jiménez Fernández y E63, Pablo de Torre Barrio
#ifndef Header_h
#define Header_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include "treemap_eda.h"


using palabra = std::string;

class palabras {
private:
	map<palabra, std::vector<int>> tabla;
public:
	palabras() {}
	void anadirPalabras(palabra a, int linea) {
		//++tabla[a];
		if (tabla.contains(a)) {
			if (tabla[a].at(tabla[a].size()-1)!= linea) tabla[a].push_back(linea);
	
		}
		else {
			std::vector<int> v;
			v.push_back(linea);
			tabla.insert({a, v});
		}
	}

	//muestra las palabras del mapa ordenado
    void mostrar() {
		for (auto &it: tabla) {
			std::cout << it.clave;
			for (int i = 0; i < it.valor.size(); i++){
				std::cout << " " << it.valor[i];
			}
			std::cout << '\n';
		}
	}
};
#endif