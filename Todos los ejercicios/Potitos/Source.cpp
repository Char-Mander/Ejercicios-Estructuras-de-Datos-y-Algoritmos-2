// Grupo E54, Eduardo Romero Palencia
// Comentario general sobre la solucio?n,
// explicando co?mo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <set>

typedef struct {
	std::string ingrediente;
	bool gusta;
} comida;

class conjunto {
public:
	conjunto() : contador(0), capacidad(5), datos(new comida[capacidad]){}
	~conjunto(){ delete[] datos; datos = nullptr; }
	void insert(std::string e, bool g) {
		int pos = 0;
		if (!contains(e, pos)) {
			pos = 0;
			if (contador == capacidad)
				amplia();
			while (datos[pos].ingrediente < e && pos < contador){
				pos++;
			}
			for (int i = contador; i > pos; i--){
				datos[i] = datos[i - 1];
			}
			datos[pos].ingrediente = e;
			datos[pos].gusta = g;
			++contador;
		}
		else if (contains(e, pos) && !datos[pos].gusta){
			datos[pos].gusta = g;
		}
	}
	bool contains(std::string e, int & i) const {
		while (i < contador && datos[i].ingrediente != e)
			++i;
		return i < contador;
	}
	size_t size() const {
		return contador;
	}
	void erase(std::string e) {
		size_t i = 0;
		while (i < contador && datos[i].ingrediente != e)
			++i;
		if (i < contador) {
			datos[i] = datos[contador - 1];
			--contador;
		}
		else
			throw std::domain_error("El elemento no esta");
	}
	comida getValorDatos(int i) const{
		return this->datos[i];
	}
	int getContador() const{
		return this->contador;
	}

private:
	size_t contador;
	size_t capacidad;
	comida * datos;
	void amplia() {
		comida * nuevos = new comida[2 * capacidad];
		for (size_t i = 0; i < capacidad; ++i)
			nuevos[i] = std::move(datos[i]);
		delete[] datos;
		datos = nuevos;
		capacidad *= 2;
	}


};

inline std::ostream & operator<<(std::ostream & that, conjunto const& conj){
	bool gusta = false;
	for (int i = 0; i < conj.getContador(); i++){
		if (!conj.getValorDatos(i).gusta && !gusta){
			std::cout << conj.getValorDatos(i).ingrediente;
			gusta = true;
		}
		else if (!conj.getValorDatos(i).gusta && gusta){
			std::cout << " " << conj.getValorDatos(i).ingrediente;
		}
			
	}
	return that;
}

// funcio?n que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(int & n) {

	conjunto conj;
	std::string aux;
	for(int i = 0; i < n; i++){
		std::cin >> aux;
		if (aux == "SI:"){
			std::cin >> aux;
			while (aux != "FIN"){
				conj.insert(aux, true);
				std::cin >> aux;
			}
		}else{
			std::cin >> aux;
			while (aux != "FIN"){
				conj.insert(aux, false);
				std::cin >> aux;
			}
		}
	}
	std::cout << conj << "\n";

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;

	std::cin >> num;
	if (num == 0)
		return false;

	resolver(num);

	// escribir sol

	return true;

}

int main() {
	while (resuelveCaso())
		;
	return 0;
}