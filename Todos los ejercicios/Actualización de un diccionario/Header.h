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


using clave = std::string;

class consultorio {
private:
	unordered_map<clave, std::string> antiguo;
	unordered_map<clave, std::string> nuevo;
public:
	consultorio() {}

	void cargarAntiguo(clave const &a, std::string pos) {
		antiguo.insert({ a, pos });
	}

	void cargarNuevo(clave const &a, std::string pos) {
			nuevo.insert({ a, pos });
		}
	
	void compararNuevoConViejo( std::vector<std::string> &anadir, std::vector<std::string> &modificar) {
		
		for (auto const& c : nuevo) {
			if (!antiguo.contains(c.clave)) anadir.push_back(c.clave);
			else if (antiguo.contains(c.clave) && (c.valor != antiguo.at(c.clave))) modificar.push_back(c.clave);
		}
	}

	void compararViejoConNuevo( std::vector<std::string> &quitar) {

		for (auto const &c : antiguo) {
			if (!nuevo.contains(c.clave))
				quitar.push_back(c.clave);
		}

	}

	
};
#endif