#ifndef Header_h
#define Header_h

#include <iostream>
#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>


class polinomio {
private:
	std::vector<std::pair<int, int>> _poli;
public:
	polinomio() {}

	int calcula(int x) {
		int total = 0;

		for (int i = 0; i < _poli.size(); i++) 
		total += _poli[i].first	* (pow(x, _poli[i].second));
		
		return total;
	}

	void read(std::istream &input = std::cin) {
		std::pair<int, int> n;
		input >> n.first;
		if (!input) throw std::invalid_argument("");

		input >> n.second;
		while (n.first != 0 || n.second != 0) {
			_poli.push_back(n);
			input >> n.first >> n.second;
		}
		sort(_poli.begin(), _poli.end());
	}

};


inline std::istream &operator>>(std::istream &entrada, polinomio &po) {
	po.read(entrada);
	return entrada;
}
#endif //Header_h