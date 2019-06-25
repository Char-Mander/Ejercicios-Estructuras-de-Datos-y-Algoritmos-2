//
//  Header.h
//

#ifndef Hora_h
#define Hora_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iostream>
#include <iomanip>
using namespace std;

class hora {
private:
	int _horas;
	int _minutos;
	int _segundos;
	static bool check(int h, int m, int s) {
		return 0 <= h && h < 24 && 0 <= m && m < 60 && 0 <= s && s < 60;
	}
public:
	// constructor
	hora() : _horas(0), _minutos(0), _segundos(0) {}
	hora(int h, int m, int s) {
		if (check(h, m, s)) {
			_horas = h; _minutos = m; _segundos = s;
		}
		else
			throw invalid_argument("ERROR\n");
	}
	// operador de comparación
	bool operator<(hora const& hora) const {
		if (_horas < hora._horas)
			return true;
		else if (_horas == hora._horas && _minutos < hora._minutos)
			return true;
		else if (_horas == hora._horas && _minutos == hora._minutos && _segundos < hora._segundos)
			return true;
		else
			return false;
	}

	hora operator+(hora const& ho) const {
		int h, m, s;
		s = _segundos + ho._segundos;
		m = _minutos + ho._minutos + (s / 60);
		s %= 60;
		h = _horas + ho._horas + (m / 60);
		m %= 60;
		if (h > 23)
			throw invalid_argument("nos pasamos de dia");
		else
			return hora(h, m, s); //Se podría poner "return {h, m, s}" 
				//que sería como decirle a la fumción que intente crear una hora con esos valorres.
	}

	int horas() const { return _horas; }
	int minutos() const { return _minutos; }
	int segundos() const { return _segundos; }


	void read(istream& input = cin) {
		int h, m, s; char c;
		input >> h >> c >> m >> c >> s;
		if (check(h, m, s)) {
			_horas = h; 
			_minutos = m; 
			_segundos = s;
		}
		else
			throw invalid_argument("ERROR\n");
	}

	void print(ostream& o = cout) const {
		o << setfill('0') << setw(2) << _horas << ':'
			<< setfill('0') << setw(2) << _minutos << ':'
			<< setfill('0') << setw(2) << _segundos;
	}
};

inline ostream & operator<<(ostream & salida, hora const& h) {
	h.print(salida);
	return salida;
}

inline istream & operator>>(istream & entrada, hora & h) {
	h.read(entrada);
	return entrada;
}


#endif // Hora_h
