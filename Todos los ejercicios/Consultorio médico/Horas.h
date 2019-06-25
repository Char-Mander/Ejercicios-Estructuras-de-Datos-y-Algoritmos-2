#pragma once

#ifndef Horas_h
#define Horas_h
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class fecha {
private:
	int _dia;
	int _hora;
	int _minuto;
public:
	fecha(int d, int h, int m) : _dia(d), _hora(h), _minuto(m) {}

	//observadoras

	int dia() const { return _dia; }

	int hora() const { return _hora; }

	int minuto() const { return _minuto; }


	bool operator<(fecha const &h) const {
		if (_dia < h._dia) return true;
		else if (h._dia < _dia) return false;
		else if (_hora < h._hora) return true;
		else if (h._hora < _hora) return false;
		else if (_minuto < h._minuto) return true;
		else if (h._minuto < _minuto) return false;
		else return false;

	}

	bool operator==(fecha const &f) const {
		return _dia == f._dia && _hora == f._hora && _minuto == f._minuto;
	}

	std::string cogerHorasYMinutos () const {
		std::string caca= "";
		return caca = _hora + ":" + _minuto;
	}
	void print(std::ostream &o = std::cout) const {
		o << setfill('0') << setw(2) << _hora << ':'
			<< setfill('0') << setw(2) << _minuto;
	}

};

inline ostream &operator<<(ostream &salida, fecha const &f) {
	f.print(salida);
	return salida;
}

#endif //Horas_h