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
#include <exception>
#include "treemap_eda.h"
#include "Horas.h"




using clave = std::string;

class consultorio {
private:

	using info_pacientes = map<fecha, std::string>;
	map<clave, info_pacientes> doctor;
	
public:
	consultorio() {}

	void nuevoMedico(const std::string &clave) {
		if (!doctor.contains(clave)) doctor.insert({ clave, {} });
	}

	void pideConsulta(std::string paciente, std::string medico, fecha f) {
		if (!doctor.contains(medico)) throw std::domain_error("Medico no existente\n");
		else if(doctor[medico].contains(f)) throw std::domain_error("Fecha ocupada\n"); 
		else doctor[medico].insert({ f, paciente });
	}

	std::string siguientePaciente(std::string medico) {

		if (!doctor.contains(medico))
			throw std::domain_error("Medico no existente\n");
		else if (doctor[medico].empty())
			throw std::domain_error("No hay pacientes\n");
		else {
			auto it = doctor[medico].begin();
			std::string nombre = it->valor;
			return nombre;
		}

	}

	void atiendeConsulta(std::string medico) {
		if (!doctor.contains(medico))
			throw std::domain_error("Medico no existente\n");
		else if (doctor[medico].empty())
			throw std::domain_error("No hay pacientes\n");
		else {
			auto it = doctor[medico].begin();
			doctor[medico].erase(it->clave);
		}
	}


	std::vector < pair<fecha, std::string>> listaPacientes(std::string medico, int dia) {
		std::vector < pair<fecha, std::string>> v;
		if (!doctor.contains(medico)) throw std::domain_error("Medico no existente\n");
		else {
			std::string aux = "";
			for (auto &it : doctor[medico]) {
				if (it.clave.dia() == dia) 
					v.push_back({ it.clave, it.valor });
			}
			return v;
		}
	}


};
#endif