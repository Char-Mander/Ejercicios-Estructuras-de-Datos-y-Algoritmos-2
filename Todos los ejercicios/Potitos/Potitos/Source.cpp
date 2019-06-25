//Laura Jiménez Fernández, E29
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <cstddef> // size_t
#include <string>

using namespace std;

class set {
private:
	vector<string> _si, _no;

public:
	set::set() : _si(0), _no(0) {}
	
	void set::insertSi(string e) {
		if (!containsSi(e)) _si.push_back(e);
	}

	void set::insertNo(string e) {
		if (!containsNo(e)) _no.push_back(e);
	}

	bool set::containsSi(string e) const {
		int i = 0;
		while (i < _si.size() && _si[i] != e)
			++i;
		return i < _si.size();
	}

	bool set::containsNo(string e) const {
		int i = 0;
		while (i < _no.size() && _no[i] != e)
			++i;
		return i < _no.size();
	}
	
	void read(std::istream &input = std::cin) {
		string op, elem;
		input >> op;
		if (op == "SI:") {
			
				cin >> elem;
				while (elem != "FIN") {
					insertSi(elem);
					cin >> elem;
				}
			}
		else{
			if (_si.size() != 0 && _no.size()!=0) {
				int i = 0;
				while (i < _no.size() && i < _si.size()) {
					
					if (!containsSi(_no[i])) insertNo(_no[i]);
					i++;
				}
			}

		}

		int cont = 0;
		while (cont < _no.size() && cont < _si.size()) {

		}
	}

};

inline istream &operator>>(istream &entrada, const set &set) {
	set.read(entrada);
	return entrada;
}

void resolver(vector<string> &v) {

}

bool resuelveCaso() {
	int numV;
	cin >> numV;
	if (numV == 0) return false;

	while (numV != 0) {
		

	}
	
}

int main() {

	
	while (resuelveCaso())
		;

	return 0;
}