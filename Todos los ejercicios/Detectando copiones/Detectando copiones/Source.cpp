//Grupo E29, Laura Jiménez Fernández y E63, Pablo de Torre Barrio
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <sstream>
//#include "hashmap_eda.h"
//#include "Header.h"

/* Primero se cogen los reyes y se meten en el mapa. Después, con la segunda tanda de reyes, se añaden y se muestran. */


/*Esta solución tiene coste lineal respecto a los elementos que entran en el mapa O(n) */

template <class Clave, class Valor, class Hash = std::hash<Clave>, class Pred = std::equal_to<Clave>>
class unordered_map {
public:
	// parejas (clave, valor)
	struct clave_valor {
		const Clave clave;
		Valor valor;
		clave_valor(Clave const& c, Valor const& v = Valor()) : clave(c), valor(v) {};
	};

protected:
	using umap_t = unordered_map<Clave, Valor, Hash, Pred>;

	/*
	Clase nodo que almacena internamente la pareja (clave, valor)
	y un puntero al siguiente.
	*/
	struct ListNode;
	using Link = ListNode *;
	struct ListNode {
		clave_valor cv;
		Link sig;
		ListNode(clave_valor const& e, Link s = nullptr) : cv(e), sig(s) {}
	};

	// vector de listas (el tamaño se ajustará a la carga)
	std::vector<Link> array;

	static const size_t TAM_INICIAL = 17; // tamaño inicial de la tabla
	static const size_t MAX_CARGA = 75;   // máxima ocupación permitida

										  // número de parejas <clave, valor>
	size_t nelems;

	// objeto función para hacer el hash de las claves
	Hash hash;

	// objeto función para comparar claves
	Pred pred;

public:

	unordered_map(size_t n = TAM_INICIAL, Hash h = Hash(), Pred p = Pred()) :
		array(n, nullptr), nelems(0), hash(h), pred(p) {}

	unordered_map(umap_t const& other) {
		copia(other);
	}

	umap_t & operator=(umap_t const& that) {
		if (this != &that) {
			libera();
			copia(that);
		}
		return *this;
	}

	~unordered_map() {
		libera();
	};

	void insert(clave_valor const& cv) {
		if (muy_llena())
			amplia();
		size_t i = hash(cv.clave) % array.size();
		Link ant, pos = array[i];
		if (localizar(cv.clave, ant, pos)) {
			pos->cv.valor = cv.valor;
		}
		else {
			array[i] = new ListNode(cv, array[i]);
			++nelems;
		}
	}

	bool empty() const {
		return nelems == 0;
	}

	size_t size() const {
		return nelems;
	}

	bool contains(Clave const& c) const {
		size_t i = hash(c) % array.size();
		Link ant, pos = array[i];
		return localizar(c, ant, pos);
	}

	Valor const& at(Clave const& c) const {
		size_t i = hash(c) % array.size();
		Link ant, pos = array[i];
		if (localizar(c, ant, pos))
			return pos->cv.valor;
		else
			throw std::out_of_range("La clave no se puede consultar");
	}

	// devuelve el valor asociado a la clave, si existe.
	// Si no existe, crea un nuevo nodo (con valor por defecto) y
	// lo devuelve.
	Valor & operator[](Clave const& c) {
		size_t i = hash(c) % array.size();
		Link ant, pos = array[i];
		if (localizar(c, ant, pos)) {
			return pos->cv.valor;
		}
		else {
			if (muy_llena()) {
				amplia();
				i = hash(c) % array.size();
			}
			array[i] = new ListNode(c, array[i]);
			++nelems;
			return array[i]->cv.valor;
		}
	}

	void erase(Clave const& c) {
		size_t i = hash(c) % array.size();
		Link ant, pos = array[i];
		if (localizar(c, ant, pos)) {
			if (ant == nullptr)
				array[i] = pos->sig;
			else
				ant->sig = pos->sig;
			delete pos;
			--nelems;
		}
	}

protected:

	void copia(umap_t const& other) {
		array.resize(other.array.size());
		for (size_t i = 0; i < array.size(); ++i) {
			array[i] = nullptr;
			Link act = other.array[i];
			while (act != nullptr) {
				array[i] = new ListNode(act->cv, array[i]);
				act = act->sig;
			}
		}
		nelems = other.nelems;
		hash = other.hash;
		pred = other.pred;
	}

	void libera() {
		for (size_t i = 0; i < array.size(); ++i) {
			// liberamos los nodos de la lista array[i]
			Link act = array[i];
			while (act != nullptr) {
				Link a_borrar = act;
				act = act->sig;
				delete a_borrar;
			}
			array[i] = nullptr;
		}
	}

	bool localizar(Clave const& c, Link & ant, Link & pos) const {
		ant = nullptr;
		while (pos != nullptr) {
			if (pred(c, pos->cv.clave))
				return true;
			else {
				ant = pos; pos = pos->sig;
			}
		}
		return false;
	}

	bool muy_llena() const {
		return 100.0 * nelems / array.size() > MAX_CARGA;
	}

	static size_t siguiente_primo(size_t a) {
		bool primo = false;
		while (!primo) {
			++a;
			primo = true;
			for (size_t j = 2; j < a && primo; ++j) {
				primo = a % j != 0;
			}
		}
		return a;
	}

	void amplia() {
		std::vector<Link> nuevo(siguiente_primo(array.size() * 2), nullptr);
		for (size_t i = 0; i < array.size(); ++i) {
			Link act = array[i];
			while (act != nullptr) {
				Link a_mover = act;
				act = act->sig;
				size_t i = hash(a_mover->cv.clave) % nuevo.size();
				a_mover->sig = nuevo[i];
				nuevo[i] = a_mover;
			}
		}
		swap(array, nuevo);
	}

protected:
	// iteradores que recorren los pares <clave, valor> de la tabla (no ordenados)
	template <class Apuntado, class Tabla>
	class Iterador {
	public:
		Apuntado & operator*() const {
			if (act == nullptr)
				throw std::out_of_range("No hay elemento a consultar");
			return act->cv;
		}

		Apuntado * operator->() const {
			return &operator*();
		}

		Iterador & operator++() {  // ++ prefijo
			next();
			return *this;
		}

		bool operator==(Iterador const& that) const {
			return act == that.act;
		}

		bool operator!=(Iterador const& that) const {
			return !(this->operator==(that));
		}

	protected:
		friend class unordered_map;
		Tabla * tabla;   // la tabla que se está recorriendo
		Link act;        // nodo actual
		size_t ind;      // índice de la lista actual

						 // iterador al primer elemento o al último
		Iterador(Tabla * t, bool first = true) : tabla(t) {
			if (first) {
				ind = 0;
				while (ind < tabla->array.size() && tabla->array[ind] == nullptr) {
					++ind;
				}
				act = (ind < tabla->array.size() ? tabla->array[ind] : nullptr);
			}
			else {
				act = nullptr;
				ind = tabla->array.size();
			}
		}

		// iterador a una clave
		Iterador(Tabla * t, Clave const& c) : tabla(t) {
			ind = tabla->hash(c) % tabla->array.size();
			Link ant;
			act = tabla->array[ind];
			if (!tabla->localizar(c, ant, act)) { // se devuelve iterador al final
				act = nullptr; ind = tabla->array.size();
			}
		}

		void next() {
			if (act == nullptr)
				throw std::out_of_range("El iterador no puede avanzar");
			act = act->sig;
			while (act == nullptr && ++ind < tabla->array.size()) {
				act = tabla->array[ind];
			}
		}
	};

public:
	// iterador que no permite modificar el elemento apuntado
	using const_iterator = Iterador<clave_valor const, umap_t const>;

	const_iterator cbegin() const {
		return const_iterator(this);
	}
	const_iterator begin() const {
		return cbegin();
	}

	const_iterator cend() const {
		return const_iterator(this, false);
	}
	const_iterator end() const {
		return cend();
	}

	const_iterator find(Clave const& c) const {
		return const_iterator(this, c);
	}

	// iterador que sí permite modificar el elemento apuntado (su valor)
	using iterator = Iterador<clave_valor, umap_t>;

	iterator begin() {
		return iterator(this);
	}

	iterator end() {
		return iterator(this, false);
	}

	iterator find(Clave const& c) {
		return iterator(this, c);
	}

};


class examenes {
private:
	unordered_map<int, int> tabla;
public:
	int contador;
	examenes() : contador(0) {} 
	void anadirExamenes(int a) {
		//++tabla[a];
		if (tabla.contains(a)) ++tabla[a];
		else tabla.insert({ a, 1 });
	}

	int recordar(int a, int i, int k, int antigua) {
		contador = 0;
		if (tabla.contains(a)) {
			contador -= (tabla[a] - 1);
			++tabla[a];
		}
			else tabla.insert({ a, 1 });
			contador += (tabla[a] - 1);

		
			if (i >= k) {
				--tabla[antigua];
				if (tabla[antigua] == 0) tabla.erase(antigua);
			}

		return contador;
	}

	int examenesCopiados() {
		int contador = 0;
		for (auto &it : tabla) {
			contador += (it.valor - 1);
		}

		return contador;
	}
	
};

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (!std::cin) return false;
	

	
	examenes e, c;
	int k, exa, aux;
	int sol1, sol2=0;
	std::cin >> k;
	std::vector<int>v(k);
	
		for (int i = 0; i < n; i++) {
			std::cin >> exa;
			e.anadirExamenes(exa);
			
				if (i < k) {
					v[i] = exa;
					sol2 += c.recordar(exa, i, k, 0);
				}
				else {
						aux = v[i%k];
						v[i%k] = exa;
						sol2 += c.recordar(exa, i, k, aux);
				}
			
		}
	
		
		sol1 = e.examenesCopiados();
	

	std::cout << sol1 << " " << sol2 << '\n';
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto

//#ifndef DOMJUDGE
//	std::ifstream in("datos.txt");
//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
//#endif 

	while (resuelveCaso())
		;
//
//#ifndef DOMJUDGE // para dejar todo como estaba al principio
//	std::cin.rdbuf(cinbuf);
//	system("PAUSE");
//#endif

	return 0;
}