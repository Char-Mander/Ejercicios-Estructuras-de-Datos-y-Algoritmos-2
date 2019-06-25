// Grupo E29, Laura Jiménez Fernández
// Grupo E63, Pablo de Torre Barrio
#ifndef Header_h
#define Header_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include "bintree_eda.h"


template <class T>
bintree<T> cargarArbol(T const& dato) {
	T raiz;
	std::cin >> raiz;

	if (raiz == dato)
		return{};
	else {
		bintree<T> izq = cargarArbol(dato);
		bintree<T> der = cargarArbol(dato);
		return{ izq, raiz, der };
	}
}


//El problema se va resolviendo de abajo a arriba, de las hojas a la raiz
template <class T>
void resolver(bintree<T> const& arbol, int & numPringaos, int & equipos) {

	if (arbol.empty())
		numPringaos = equipos = 0;
	else {
		numPringaos = arbol.root();

		int max_iz, eq_iz, max_dr, eq_dr;
		resolver(arbol.left(), max_iz, eq_iz);
		resolver(arbol.right(), max_dr, eq_dr);

		/*Para llevar el camino más largo, en cada nodo cogemos el camino más largo de cada uno de sus hijos
			Por lo que al llegar a la raiz, ésta elegiría entre el mejor camino entre el mejor de su hijo derecho
			el mejor de su hijo izquierdo, los cuales harán lo mismo hasta llegar a las hojas*/
		if (max_iz > max_dr)
			numPringaos += max_iz;
		else
			numPringaos += max_dr;

		/*Si un nodo es mayor que 0 y no hacen falta equipos en su hijo derecho ni en el izquierdo
			es que hace falta un equipo para buscarles a ellos. Si no, el numero de equipos que hacen
			falta en ese nudo son la suma de los equipos que hacen falta en su hijo derecho y es su hijo izquierdo*/
		if (arbol.root() > 0 && eq_iz == 0 && eq_dr == 0)
			equipos = 1;
		else
			equipos = eq_iz + eq_dr;

	}
}
#endif //Header_h

