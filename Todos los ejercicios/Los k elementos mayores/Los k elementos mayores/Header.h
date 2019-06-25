#ifndef Header_h
#define Header_h

#include <cstddef>
#include <stdexcept>  
#include <utility>  
#include <iostream>
#include <iomanip>
#include <istream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class conjunto {
private:
	vector<T> _elementos;

public:
	conjunto() {}
	//Función que deja el vector con los k mayores
	void kMayores(long int k) {
		long int i = _elementos.size() - 1, cont = 0, cont2 = i - (k - 1);

		while (cont!=k) {
			_elementos[cont] = _elementos[cont2];			
			cont++;
			cont2++;
			
		}

		_elementos.erase(_elementos.begin() + k, _elementos.end());

		for (long int i = 0; i < _elementos.size(); i++)
			cout << _elementos[i] << " ";

	}


	//Función que añade elementos
	void anadirElementos(const T &elemento) {
		if (!contains(elemento)) _elementos.push_back(elemento);
	}


	//función que comprueba si está contenido el elemento e en el conjunto
	bool contains(T e) const {
		long int i = 0;
		while (i < _elementos.size() && _elementos[i] != e)
			++i;
		return i < _elementos.size();
	}

	//función que ordena el conjunto
	void ordena() {
		sort(_elementos.begin(),_elementos.end());
	}

	//función que muestra el conjunto por pantalla
	void print(std::ostream &o = std::cout) const {
		for (long int i = 0; i < _elementos.size(); i++) {
			o << _elementos[i] << " ";
		}

		o << '\n';
	}
};

template <class T>
inline ostream &operator<<(ostream &salida, conjunto<T> const &co) {
	co.print(salida);
	return salida;
}
#endif 
