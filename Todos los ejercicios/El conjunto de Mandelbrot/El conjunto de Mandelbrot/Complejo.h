#ifndef Complejo_h
#define Complejo_h

#include <cstddef>
#include <stdexcept>  
#include <utility>  
#include <iostream>
#include <iomanip>
#include <istream>
using namespace std;

template <class T>
class conjunto {
private:
	T _real, _imaginario;

public:
	conjunto() : _real(0), _imaginario(0){}

	conjunto(T r, T i) {
			_real = r;
			_imaginario = i;
	}

	conjunto<T> operator+(conjunto const &co) const {
		T r, i;
		r = _real + co._real;
		i = _imaginario + co._imaginario;

		return conjunto(r, i);
	}

	conjunto<T> operator*(conjunto const &co) const {
		T r, i;
		r = (_real * co._real) - (_imaginario*co._imaginario);
		i = (_real * co._imaginario) + (co._real * _imaginario);

		return conjunto(r, i);
	}

	T mod() const {
		T r, i;
		r = (_real*_real);
		i = (_imaginario*_imaginario);
		return sqrt(r + i);
	}

	T real () /*const*/ { return _real; }
	T imaginario()/* const*/ { return _imaginario; }
	

	void read(std::istream &input = std::cin) {
		input >> _real >> _imaginario;
	}

};


template <class T>
inline istream &operator>>(istream &entrada, conjunto<T> &co) {
	co.read(entrada);
	return entrada;
}


#endif 