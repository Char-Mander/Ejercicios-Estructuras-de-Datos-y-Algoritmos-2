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
#include "hashmap_eda.h"


using rey = std::string;

class reyes {
private:
	unordered_map<rey, int> tabla;
public:
	reyes() {}
	void anadirReyes(const rey &a) {
		//++tabla[a];
		if (tabla.contains(a)) ++tabla[a];	
		else tabla.insert({a, 1});
		
	}

	//muestra las palabras del mapa ordenado
	void mostrar(const rey &a) {
		std::cout << tabla[a] << '\n';
	}
};
#endif