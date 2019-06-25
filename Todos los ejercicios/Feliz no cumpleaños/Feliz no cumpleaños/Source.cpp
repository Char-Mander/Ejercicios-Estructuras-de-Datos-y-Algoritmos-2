//Laura Jiménez Fernández, E29
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

class fecha {
private:
	int dia, mes, ano;
	bool check(int d, int m, int a) {
		return(d>0 && (((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d <= 31) ||
			((m == 4 || m == 6 || m == 9 || m == 11) && d <= 30) || (m == 2 && d <= 28)) && m>0 && m <= 12 && a >= 1862);
	}

public:
	fecha() : dia(0), mes(0), ano(0) {}

	fecha(int d, int m, int a) {
		if (check(d, m, a)) {
			dia = d;
			mes = m;
			ano = a;
		}
		else if (d == 0 && m == 0 && a == 0) throw invalid_argument("");
		else throw invalid_argument("Formato de fecha incorrecto \n");
	}


	bool operator<(fecha const &f) const {
		if (ano  < f.ano) return true;
		else if (f.ano < ano) return false;
		else if (mes < f.mes) return true;
		else if (f.mes < mes) return false;
		else if (dia < f.dia) return true;
		else if (f.dia < dia) return false;
	}

	int cuentaDias(fecha const &f) const {
		int d = di(), m = me(), a = an(), totaldias = 0;

		while (f.dia>d || f.mes>m || f.ano > a) {

			if ((d == 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)) ||
				(d == 30 && (m == 4 || m == 6 || m == 9 || m == 11)) || (d == 28 && m == 2)) {
				d = 1;
				if (m == 12) {
					m = 1;
					a++;
				}
				else m++;
			}
			else d++;

			totaldias++;
		}
		return totaldias;
	}

	int di() const { return dia; }
	int me() const { return mes; }
	int an() const { return ano; }


	void read(std::istream &input = std::cin) {
		int d, m, a;
		input >> d >> m >> a;
		if (check(d, m, a)) {
			dia = d;
			mes = m;
			ano = a;
		}
		else throw invalid_argument("ERROR \n");
	}


};


inline istream &operator>>(istream &entrada, fecha &f) {
	f.read(entrada);
	return entrada;
}

bool resuelveCaso() {
	fecha nacimiento; 
	fecha actual;
	try {
		cin >> nacimiento;
		cin >> actual;
	}
	catch (invalid_argument) {
		return false;
	}
	int total = nacimiento.cuentaDias(actual);
	if (total % 365 == 0) total = 0;
	else if (total>365) total = total - (total / 365);
	cout << total << '\n';

	return true;
}

int main() {

	while (resuelveCaso())
		;
 
	return 0;
}