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
#include "set.h"


class deporte {
protected:
	std::string d;
	int a;
public:

	deporte() : d(""), a(0) {}
	deporte(std::string dep, int al) : d(dep), a(al) {}
	bool operator<(deporte const& dep) const {
		if (a > dep.a)
			return true;
		else if (a == dep.a && d < dep.d)
			return true;
		else
			return false;
	}

	std::string getD() const { return d; }
	int getA() const { return a; }
};

class deportes {
private:
	
	unordered_map<std::string, set<std::string>> tabla;
	std::vector<deporte> res;
	set<std::string> eliminados;
public:
	deportes() {}

	bool esDeporte(std::string deporte) {
		bool esDep = true;
		int i = 0;

		while (esDep && i < deporte.length()) {
			if (deporte.at(i) < 'A' || deporte.at(i) > 'Z')
				esDep = false;
			i++;
		}

		return esDep;
	}

	void anadirDeporte(std::string dep) {
		if (!tabla.contains(dep)) {
			tabla.insert({ dep,  set<std::string>(10) });
		}
	}

	bool alumnoRepetido(std::string deporte, std::string alumno) {
		bool repetido = false;

		for (auto const& d : tabla) {
			if (d.clave != deporte)
				if (tabla[d.clave].contains(alumno)) {
					repetido = true;
					tabla[d.clave].erase(alumno);
					eliminados.insert(alumno);
				}
		}

		if (eliminados.contains(alumno))
			repetido = true;
		return repetido;
	}

	void anadirAlumno(std::string dep, std::string alumno) {

		if(!tabla[dep].contains(alumno))
			tabla[dep].insert(alumno);
	}

	void mostrar() {
		for (auto & d : tabla) {
			int al = d.valor.size();
			res.push_back({ d.clave, al });
		}

		std::sort(res.begin(), res.end());

		for (auto const & d : res) {
			std::cout << d.getD() << ' ' << d.getA() << '\n';
		}
	}
};
#endif