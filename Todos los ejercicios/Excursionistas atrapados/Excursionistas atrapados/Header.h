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
bintree<T> siguienteHijo(T const& dato, int &numCaminos, int &maxPringaos, int &numPringaos) {
	T raiz;
	std::cin >> raiz;

	if (raiz == dato)
		return{};
	else {
		numPringaos += raiz;
		int aux = numPringaos;
		int auxCam = numCaminos;
		bintree<T> izq = siguienteHijo(dato, numCaminos, maxPringaos, numPringaos);
		if (numPringaos > aux &&/*nuevo*/ izq.root()>0) numCaminos++; //solución 1
		//int i = numPringaos; solución 2
		if (numPringaos > maxPringaos) maxPringaos = numPringaos;
		if(!izq.empty()) numPringaos -= izq.root();
		

		bintree<T> der = siguienteHijo(dato, numCaminos, maxPringaos, numPringaos);
		if (numPringaos > aux&&/*nuevo*/der.root()>0) numCaminos++; //solución 1
		//int d = numPringaos; solución 2
		if (numPringaos > maxPringaos) maxPringaos = numPringaos;
		if (!der.empty()) numPringaos -= der.root();

		// nuevo numPringaos -= raiz; 
		
		//if (numPringaos == i && numPringaos == d && raiz!=0) numCaminos++; solución 2

		//En vez de hacer numCaminos++ cada vez que pasa por el hijo izquierdo y el derecho, (solución 1)
		//lo comentado es otra posible solución (aunque sigue saliendo mal)
		
		return{ izq, raiz, der };
	}
}


#endif //Header_h
#pragma once

