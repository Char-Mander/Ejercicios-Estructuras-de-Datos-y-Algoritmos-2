//Grupo E29, Laura Jiménez Fernández y E63, Pablo de Torre Barrio
#ifndef Header_h
#define Header_h

#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include "hashmap_eda.h"


//using capitulo = int;

class series {
private:
	unordered_map<int, int> tabla;
public:
	series() {}
	void anadircapitulos(int a, int pos, int &max, int & rep) {
		//++tabla[a];
		if (tabla.contains(a)) {
			if (tabla.at(a) >= rep) {		
				rep = tabla.at(a) + 1;
			}
			tabla[a] = pos;
		}
		else {
			tabla.insert({ a, pos });
		}
		if ((pos - rep)+1 > max) {
			max = (pos - rep) + 1;
		}
	}
};
#endif