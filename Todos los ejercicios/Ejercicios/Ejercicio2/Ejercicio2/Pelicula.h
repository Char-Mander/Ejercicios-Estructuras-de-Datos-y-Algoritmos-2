//
//  Pelicula.h
//

#ifndef Pelicula_h
#define Pelicula_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <string>
#include "Hora.h"
using namespace std;

class pelicula {
private:
	string titulo;
	hora inicio, duracion, fin;
public:
	// constructor
	pelicula() {}
	pelicula(hora const& ini, hora const& dur, hora const& fn, string const& tit) : 
		inicio(ini), duracion(dur), fin(ini + dur), titulo(tit) {}
	// operador de comparación
	bool operator<(pelicula const& that) const {
		if (fin < that.fin)
			return true;
		else if (that.fin < fin)
			return false;
		else
			return titulo < that.titulo;
	}

	void read(istream& input = cin) {
		hora ini, dur;
		string tit;
		input >> ini >> dur;
		input.ignore();//ignora 1
		getline(input, tit);
		inicio = ini;
		duracion = dur;
		fin = ini + dur;
		titulo = tit;
	}

	void print(ostream& o = cout) const {
		o <<  fin << ' ' << titulo;
	}
};

inline ostream & operator<<(ostream & salida, pelicula const& p) {
	p.print(salida);
	return salida;
}

inline istream & operator>>(istream & entrada, pelicula & p) {
	p.read(entrada);
	return entrada;
}


#endif // Header_h

