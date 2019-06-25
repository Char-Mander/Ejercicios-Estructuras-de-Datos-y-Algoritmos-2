
#include <iostream>
#include <fstream>

#ifndef DOMJUDGE
//#include "checkML.h"
#endif

#include "bostezos.h"

bool resuelveCaso() {
   std::string orden, nombre;
   std::cin >> orden;
   if (!std::cin)
      return false;
   
   bostezos B;
   while (orden != "FIN") {
      if (orden == "BOSTEZAR") {
         std::cin >> nombre;
         B.bostezar(nombre);
      } else if (orden == "LISTA_NEGRA") {
         for (auto a : B.lista_negra()) {
            std::cout << a << ' ';
         }
         std::cout << '\n';
      } else if (orden == "BORRAR") {
         std::cin >> nombre;
         B.borrar(nombre);
      } else if (orden == "CANTIDAD") {
         std::cin >> nombre;
         std::cout << nombre << ": " << B.cantidad(nombre) << '\n';
      }

      std::cin >> orden;
   }
   std::cout << "---\n";
   return true;
}

int main() {

   // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());

   // restablecimiento de cin
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("pause");
#endif
   return 0;
}

