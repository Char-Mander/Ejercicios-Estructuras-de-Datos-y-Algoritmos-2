#ifndef bostezos_h
#define bostezos_h
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using alumno = std::string;

class bostezos {
private:
	std::map<alumno, unsigned int> tabla;
public:
   bostezos() {}
   void bostezar(alumno const& a) {
	   //++tabla[a];
	   if (tabla.count(a) > 0)
		   ++tabla[a];
	   else
		   tabla.insert({ a, 1 });
   }

   void borrar(alumno const& a) {
	   tabla.erase(a);
   }

   unsigned int cantidad(alumno const& a) const {
	   try {
		   return tabla.at(a);
	   }
	   catch (std::out_of_range & e) {
		   return 0;
	   }
   }

   std::vector<alumno> lista_negra() const {
	   std::vector<alumno> res;
	   for (auto const& p : tabla) {
		   if (p.second >= 3)
			   res.push_back(p.first);
	   }
	   return res;
   }
};

#endif
