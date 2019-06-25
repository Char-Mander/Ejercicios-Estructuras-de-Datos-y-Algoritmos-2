#ifndef bostezos_y_mas_h
#define bostezos_y_mas_h
#include <string>
#include <vector>

#include <map>
#include <unordered_map>


using alumno = std::string;
using falta = std::string;
using uint = unsigned int;

#define valor second
#define clave first

class bostezos_y_mas {
private:
	using info_alumno = std::pair<uint, std::unordered_map<falta, uint>>;
	std::map<alumno, info_alumno> tabla;
public:
   bostezos_y_mas() {}

   void registrar(falta const& f, alumno const& a) {
	  
	   ++info.first;
	   ++info.second[f];
   }

   void borrar_falta(falta const& f, alumno const& a) {
	   auto itA = tabla.find(a);
	   if (itA != tabla.end()) {
		   itA->valor.first -= itA->valor.second[f];
		   itA->valor.second.erase(f);
		   if (itA->valor.first == 0)
			   tabla.erase(a);
	   }
   }

   void borrar(alumno const& a) {
	   tabla.erase(a);
   }

   uint cantidad_falta(falta const& f, alumno const& a) const {
	   auto itA = tabla.find(a);
	   if (itA != tabla.end()) {
		   try {
			   return itA->valor.second.at(f);
		   }
		   catch (std::exception & e) {
			   return 0;
		   }
	   }
	   else
		   return 0;
   }
   
   uint cantidad(alumno const& a) const {
	   auto itA = tabla.find(a);
	   if (itA != tabla.end()) {
		   return itA->valor.first;
	   }
	   else
		   return 0;

   }

   std::vector<alumno> lista_negra_falta(falta const& f, uint n) const {
	   std::vector<alumno> resultado;
	  
	   for (auto const& par : tabla) {
		   auto itF = par.valor.second.find(f);
		   if (itF != par.valor.second.end() && itF->valor >= n)
			   resultado.push_back(par.first);
	   }
	   return resultado;
   }

   std::vector<alumno> lista_negra(uint n) const {
	   std::vector<alumno> resultado;
	   for (auto const& par : tabla) {
		   if (par.valor.first >= n)
			   resultado.push_back(par.first);
	   }
	   return resultado;

   }
};

#endif
