#pragma once

#ifndef Header_h
#define Header_h
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <iomanip>
using namespace std;

class horas {
private:
	int _hora;
	int _minuto;
	int _segundo;
	bool check(int h, int m, int s) {
		return 0 <= h && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60;
	}
public:
	horas(int h = 0, int m = 0, int s = 0) {
		
		if (check(h, m, s)) {
			_hora = h;
			_minuto = m;
			_segundo = s;
		} 
		else throw invalid_argument("argumentos incorrectos para una hora");
	}

	//observadoras

	int hora() const { return _hora; }

	int minuto() const { return _minuto; }

	int segundo() const { return _segundo; }

	bool operator<(horas const &h) const {
		if (_hora < h._hora) return true;
		else if (_hora>h._hora) return false;
		else if (_minuto < h._minuto) return true;
		else if (_minuto > h._minuto) return false;
		else if (_segundo < h._segundo) return true;
		else if (_segundo > h._segundo) return false;

	}

	void read(std::istream &input = std::cin) {
		int h, m, s;
		char c;
		input >> h>> c >> m >> c >> s;
		if (check(h, m, s)) {
			_hora = h;
			_minuto = m;
			_segundo = s;
		}
		else throw invalid_argument("ERROR \n");
	}

	void print(std::ostream &o = std::cout) const {
		o << setfill('0') << setw(2) << _hora << ':'
			<< setfill('0') << setw(2) << _minuto << ':'
			<< setfill('0') << setw(2) << _segundo;
	}

};

inline ostream &operator<<(ostream &salida, horas const &h) {
	h.print(salida);
	return salida;
}

inline istream &operator>>(istream &entrada, horas &h) {
	h.read(entrada);
	return entrada;
}


#endif Header_h