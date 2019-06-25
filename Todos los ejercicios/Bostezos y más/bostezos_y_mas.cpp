
#include <iostream>
#include <fstream>

#ifndef DOMJUDGE
#include "checkML.h"
#endif

#include "bostezos_y_mas.h"

void mostrar(std::vector<alumno> const& v) {
   for (auto const& a : v) {
      std::cout << a << ' ';
   }
   std::cout << '\n';
}

bool resuelveCaso() {
   std::string orden, nombre, falta;
   int num;
   std::cin >> orden;
   if (!std::cin)
      return false;

   bostezos_y_mas B;
   while (orden != "FIN") {
      if (orden == "REGISTRAR") {
         std::cin >> falta >> nombre;
         B.registrar(falta, nombre);
      } else if (orden == "LISTA_NEGRA") {
         std::cin >> num;
         mostrar(B.lista_negra(num));
      } else if (orden == "LISTA_NEGRA_FALTA") {
         std::cin >> falta >> num;
         std::cout << falta << ": ";
         mostrar(B.lista_negra_falta(falta, num));
      } else if (orden == "BORRAR") {
         std::cin >> nombre;
         B.borrar(nombre);
      } else if (orden == "BORRAR_FALTA") {
         std::cin >> falta >> nombre;
         B.borrar_falta(falta, nombre);
      } else if (orden == "CANTIDAD") {
         std::cin >> nombre;
         std::cout << nombre << ": " << B.cantidad(nombre) << '\n';
      } else if (orden == "CANTIDAD_FALTA") {
         std::cin >> falta >> nombre;
         std::cout << nombre << ": " << B.cantidad_falta(falta, nombre) << ' ' << falta << '\n';
      }

      std::cin >> orden;
   }
   std::cout << "---\n";
   return true;
}

int main() {

   // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
   std::ifstream in("bostezos_y_mas.txt");
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

