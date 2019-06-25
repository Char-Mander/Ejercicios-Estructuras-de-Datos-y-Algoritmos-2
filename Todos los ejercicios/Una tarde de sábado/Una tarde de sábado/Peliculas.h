#ifndef Peliculas_h
#define Peliculas_h

#include "Header.h"
#include <cstddef>    
#include <stdexcept>  
#include <utility>    
#include <iostream>
#include <string>

using namespace std;

class peliculas {
private:
	horas inicio;
	horas fin;
	horas duracion;
	string nombre;

public:
	peliculas() {}
	peliculas(horas const &i, horas const &f, horas const &dur, string const &nom) :
		inicio(i), fin(i+dur), duracion(dur), nombre(nom) {}

	//para ordenar por hora de finalización
	bool operator<(peliculas const &that) const {
		if (fin < that.fin) return true;
		else if (that.fin < fin) return false;
		else return nombre < that.nombre;
	}

	//Entrada de datos
	void read(istream &input = cin) {
		horas ini, dur;
		string nom;
		input >> ini >> dur;
		input.ignore();
		getline(input, nom);
		inicio = ini;
		duracion = dur;
		fin = ini + dur;
		nombre = nom;
	}

	//Salida de datos
	void print(ostream& o = cout) const {
		o << fin << " " << nombre;
	}

};

inline ostream & operator<<(ostream & salida, peliculas const& p) {
	p.print(salida);
	return salida;
}

inline istream & operator>>(istream & entrada, peliculas & p) {
	p.read(entrada);
	return entrada;
}


#endif Peliculas_h
