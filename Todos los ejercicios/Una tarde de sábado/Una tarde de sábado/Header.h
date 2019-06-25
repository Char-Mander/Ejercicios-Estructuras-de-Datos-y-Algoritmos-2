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
	horas() : _hora(0), _minuto(0), _segundo(0){}

	horas(int h, int m, int s) {
		if (check(h, m, s)) {
			_hora = h;
			_minuto = m;
			_segundo = s;
		}
		else throw invalid_argument("Argumentos incorrectos para una hora");
	}

	bool operator<(horas const &h) const {
		if (_hora < h._hora) return true;
		else if (_hora == h._hora && _minuto < h._minuto) return true;
		else if (_hora == h._hora  && _minuto == h._minuto && _segundo < h._segundo) return true;
		else return false;

	}


	horas operator+(horas const &h) const {
		int hr, m, s;
		s = _segundo + h._segundo;
		m = _minuto + h._minuto + (s / 60);
		s = s % 60;
		hr = _hora + h._hora + (m / 60);
		m = m % 60;
		if (hr > 23) throw invalid_argument("Te has pasado de día");
		else return horas(hr, m, s);
	}

	int hora() const { return _hora; }

	int minuto() const { return _minuto; }

	int segundo() const { return _segundo; }

	void read(std::istream &input = std::cin) {
		int h, m, s;
		char c;
		input >> h >> c >> m >> c >> s;
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


#endif Header_h#pragma once
