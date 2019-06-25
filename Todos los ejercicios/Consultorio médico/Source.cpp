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
#include <string>
#include <exception>
#include "treemap_eda.h"
#include "Header.h"
#include "Horas.h"

/* Describir lo que hace la función */


/* Coste de la función */


bool resuelveCaso() {
	int numLineas;
	std::cin >> numLineas;
	if (!std::cin) return false;
	
	consultorio c;
	int d, h, m;

	for (int i = 0; i < numLineas; i++) {
		std::string tipo = "", medico, paciente, siguiente;
		std::cin >> tipo;
		try {
			if (tipo == "nuevoMedico") {
				std::cin >> medico;
				c.nuevoMedico(medico);
			}
			else if (tipo == "pideConsulta") {
				std::cin >> paciente >> medico >> d >> h >> m;
				fecha f(d, h, m);
				c.pideConsulta(paciente, medico, f);
			}
			else if (tipo == "siguientePaciente") {
				std::cin >> medico;
				siguiente = c.siguientePaciente(medico);
				std::cout << "Siguiente paciente doctor " << medico << '\n' << siguiente << '\n' << "---" << '\n';
			}
			else if (tipo == "atiendeConsulta") {
				std::cin >> medico;
				c.atiendeConsulta(medico);
			}
			else if (tipo == "listaPacientes") {
				std::cin >> medico >> d;
				std::vector < pair<fecha, std::string>> lista = c.listaPacientes(medico, d);
				std::cout << "Doctor " << medico << " dia " << d << '\n';
				for (int i = 0; i < lista.size(); i++)
					std::cout << lista[i].second << ' ' << lista[i].first << '\n';
				std::cout << "---\n";
			}
		}
		catch (std::domain_error e) { 
			std::cout << e.what(); 
			std::cout << "---" << '\n';
		}

	}
	std::cout << "------" << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
		
	while (resuelveCaso())
		;

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}